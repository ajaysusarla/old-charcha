/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

#include <sys/select.h>

#include "core-lib/net_tcp.h"

#define PROGNAME "Charcha"
#define VERSION "0.1"
#define DFL_HOST "irc.freenode.net"
#define DFL_PORT 6667
#define STDIN 0
#define STDOUT 1
#define PING_TIMEOUT 300
#define BUF_SIZE 2048

static void print_version(void)
{
        printf("%s v%s\n", PROGNAME, VERSION);
}

static void print_usage(void)
{
        print_version();

        printf("\n");
        printf("Usage: charcha [options]\n\n");
        printf("Options:\n");
        printf("  --server       IRC server to connect to.\n");
        printf("  --nick         IRC nick to use.\n");
        printf("  --help|-h      Print this help.\n");
        printf("  --version|-V   Print version.\n");
}

static void parse_arg(const char *arg)
{
        const char *p = arg + 1;

        do {
                switch(*p) {
                case 'h':
                        print_usage();
                        exit(EXIT_SUCCESS);
                case 'V':
                        print_version();
                        exit(EXIT_SUCCESS);
                case '-':
                        if (strcmp(arg, "--server") == 0) {
                                continue;
                        }
                        if (strcmp(arg, "--nick") == 0) {
                                continue;
                        }
                        if (strcmp(arg, "--help") == 0) {
                                print_usage();
                                exit(EXIT_SUCCESS);
                        }
                        if (strcmp(arg, "--version") == 0) {
                                print_version();
                                exit(EXIT_SUCCESS);
                        }
                default:
                        fprintf(stderr, "Invalid argument '%s'\n", arg);
                        print_usage();
                        exit(EXIT_FAILURE);
                }

        } while (*++p);
}

static void irc_login(int sockfd, char *nick, char *fullname, char *host)
{
        char msg[512];

        snprintf(msg, sizeof(msg), "NICK %s\r\nUSER %s localhost %s : %s\r\n",
                 nick, nick, host, fullname);
        net_tcp_socket_write(sockfd, msg, strlen(msg));
}

static size_t tokenize(char *proc_buf, char *msg,
                       char **word, char **word_eol)
{
        size_t num_toks;
        char *str;

        if (!msg)
                return 0;

        word[0] = "\000";
        word_eol[0] = "\000";
        word[1] = proc_buf;
        word[1] = msg;

        while (1) {
                switch (*msg) {
                case 0:
                        break;
                case '"':
                        break;
                case ' ':
                        break;
                default:
                        break;
                }
        }

        return num_toks;
}

static void process_server_msg(int sockfd, char *buf)
{
        if (!strncmp(buf, "PING ", 5)) {
                char str[512] = { 0 };
                sprintf(str, "PONG %s\r\n", buf + 5);
                net_tcp_socket_write(sockfd, str, strlen(str));
        }
}

static void process_msg(int sockfd, char *buf)
{
        char *word[32 + 1];
        char *word_eol[32 + 1];
        char *token_buf = NULL;

        if (!buf || !buf[0]) {
                fprintf(stderr, "Internal Error!\n");
                exit(EXIT_FAILURE);
        }

        token_buf = malloc(strlen(buf) + 1);
        if (token_buf == NULL) {
                fprintf(stderr, "Memory allocation failure!\n");
                exit(EXIT_FAILURE);
        }

        tokenize(token_buf, buf, word, word_eol);
        /* Process server message */
        if (buf[0] == ':') {
        }

        if (buf[0] != ':') {
                process_server_msg(sockfd, buf);
                goto cleanup;
        }

cleanup:
        free(token_buf);
        token_buf = NULL;
}

static void irc(int sockfd)
{
        fd_set readfds;
        struct timeval tv;
        int ret;
        static time_t ping;
        char ping_msg[512];
        char buf[BUF_SIZE] = { 0 };
        int nread;

        snprintf(ping_msg, sizeof(ping_msg), "PING %s\r\n", DFL_HOST);

        while (1) {
                FD_ZERO(&readfds);
                FD_SET(sockfd, &readfds);
                FD_SET(STDIN, &readfds);

                tv.tv_sec = 120;
                tv.tv_usec = 0;
                ret = select(sockfd + 1, &readfds, 0, 0, &tv);
                if (ret < 0) {
                        if (errno == EINTR)
                                continue;
                        perror("select()");
                        exit(EXIT_FAILURE);
                } else if (ret == 0) {
                        if (time(NULL) - ping >= PING_TIMEOUT) {
                                fprintf(stderr, "ping timeout...\n");
                                exit(EXIT_FAILURE);
                        }

                        net_tcp_socket_write(sockfd, ping_msg, strlen(ping_msg));
                }

                if (FD_ISSET(sockfd, &readfds)) {
                        ping = time(NULL);
                        nread = net_tcp_socket_read(sockfd, buf, BUF_SIZE);
                        if (nread >= 0) {
                                process_msg(sockfd, buf);
                                write(STDOUT, buf, nread);
                        }
                }

                if (FD_ISSET(STDIN, &readfds)) {
                        nread = read(STDIN, buf, BUF_SIZE);
                        if (nread >= 0) {
                                net_tcp_socket_write(sockfd, buf, nread);
                        }
                }

                memset(buf, 0, BUF_SIZE);
        }
}

int main(int argc, char **argv)
{
        int i;
        int sockfd;

        for (i = 1; i < argc; i++) {
                const char *a = argv[i];

                if (a[0] == '-') {
                        parse_arg(a);
                        continue;
                }
        }

        printf("Connecting to %s:%d...", DFL_HOST, DFL_PORT);
        sockfd = net_tcp_socket_open(DFL_HOST, DFL_PORT, 0);
        if (!sockfd) {
                fprintf(stderr, "Failed to connect to %s:%d\n", DFL_HOST, DFL_PORT);
                exit(EXIT_FAILURE);
        }
        printf("...Done!\n");

        irc_login(sockfd, "booblah", "Boo Blah", "localhost");

        irc(sockfd);

        printf("Disconnecting from %s...", DFL_HOST);
        net_tcp_socket_close(sockfd);
        printf("...Done!\n");

        exit(EXIT_SUCCESS);
}
