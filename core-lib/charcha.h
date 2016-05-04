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

#ifndef _CHARCHA_H_
#define _CHARCHA_H_

#include <unistd.h>

/* Linux uses 64 bytes, maybe stick to that? */
#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX  255
#endif

#define NICKNAMELEN 64
#define CHANNELNAMELEN 256

typedef struct _channel {
        char name[CHANNELNAMELEN];
        struct _channel *next;
} Channel;

typedef struct _serverInfo {
        int port;
        int sockfd4;
        int sockfd6;

        char hostname[HOST_NAME_MAX];
        char servername[HOST_NAME_MAX];
        char nick[NICKNAMELEN];

        Channel *channels;
} ServerInfo;

typedef struct _csession {
        ServerInfo *server;
} CSession;

#endif  /* _CHARCHA_H_ */
