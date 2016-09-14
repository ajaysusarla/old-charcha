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

#include "conf.h"
#include "util.h"
#include "htable.h"

#include <string.h>
#include <unistd.h>

typedef enum
{
        A_PARAM
} AnEnum;

confFile *conf_file_open(const char *path)
{
        confFile *cfile = NULL;
        char *tmppath;
        FILE *fp;
        size_t path_len;

        if (path == NULL || path[0] == '\0')
                return NULL;

        path_len = strlen(path);

        tmppath = xmalloc(sizeof(char) * (path_len + 4)); /* Appending .tmp */

        tmppath = strncpy(tmppath, path, path_len);
        tmppath = strcat(tmppath, ".tmp");

        if ((fp = fopen(tmppath, "wb")) == NULL) {
                fprintf(stderr, "Error opening file %s\n", tmppath);
                free(tmppath);
                return NULL;
        }


        if (file_change_mode_rw(tmppath) < 0)
                fprintf(stderr, "Could not chmod %s.\n", tmppath);

        cfile = xmalloc(sizeof(confFile) * 1);
        cfile->fp = fp;
        cfile->path = strdup(path);
        cfile->tmppath = tmppath;
        cfile->path_len = path_len;

        return cfile;
}

int conf_file_close(confFile *cfile)
{

        if (fclose(cfile->fp) == EOF) {
                fprintf(stderr, "Error close file: %s\n", cfile->tmppath);
                unlink(cfile->tmppath);
                free(cfile->path);
                free(cfile->tmppath);
                free(cfile);
                cfile = NULL;
                return -1;
        }

        if (file_exists(cfile->path)) {
                char *bakpath;
                int ret;

                bakpath = xmalloc(sizeof(char) * (cfile->path_len + 4)); /* Appending .bak */

                bakpath = strncpy(bakpath, cfile->path, cfile->path_len);
                bakpath = strcat(bakpath, ".bak");

                ret = file_rename(cfile->path, bakpath);
                free(bakpath);

                if (ret < 0) {
                        fprintf(stderr, "could not rename %s to %s.",
                                cfile->path, bakpath);
                        unlink(cfile->tmppath);
                        free(cfile->path);
                        free(cfile->tmppath);
                        free(cfile);
                        cfile = NULL;
                        return -1;
                }
        }


        if (file_rename(cfile->tmppath, cfile->path)) {
                fprintf(stderr, "could not rename %s to %s.",
                        cfile->tmppath, cfile->path);
                unlink(cfile->tmppath);
                free(cfile->path);
                free(cfile->tmppath);
                free(cfile);
                cfile = NULL;
                return -1;
        }

        free(cfile->path);
        free(cfile->tmppath);
        free(cfile);
        cfile = NULL;
        return 0;
}

void conf_set_default(confEntry *entries)
{
        int i;

        if (entries == NULL) {
                fprintf(stderr, "Invalid Entry!");
                return;
        }

        for (i = 0; entries[i].name != NULL; i++) {
                if (!entries[i].data)
                        continue;

                switch(entries[i].type) {
                case C_STRING:
                        if (entries[i].defval != NULL) {
                                if (strncasecmp(entries[i].defval, "ENV_", 4)) {
                                        /* Environment Variable */
                                        char *envstr;
                                        envstr = getenv(entries[i].defval + 4);
                                        *((char **)entries[i].data) =
                                                envstr ? strdup(envstr) : NULL;
                                } else if(entries[i].defval[0] == '~') {
                                        /* Path */
                                } else if(entries[i].defval[0] != '\0') {
                                        /* Regular String */
                                        *((char **)entries[i].data) =
                                                strdup(entries[i].defval);
                                } else {
                                        *((char **)entries[i].data) = NULL;
                                }
                        } else {
                                *((char **)entries[i].data) = NULL;
                        }
                        break;
                case C_INT:
                        if (entries[i].defval != NULL) {
                                *((int *)entries[i].data) =
                                        (int)atoi(entries[i].defval);
                        } else {
                                *((int *)entries[i].data) = 0;
                        }
                        break;
                case C_BOOL:
                        if (entries[i].defval != NULL) {
                                if (strncasecmp(entries[i].defval, "TRUE", 4))
                                        *((bool_t *)entries[i].data) = TRUE;
                                else if (strncasecmp(entries[i].defval, "FALSE", 5))
                                        *((bool_t *)entries[i].data) = FALSE;
                                else
                                        *((bool_t *)entries[i].data) =
                                                atoi(entries[i].defval) ? TRUE : FALSE;
                        } else {
                                *((bool_t *)entries[i].data) = FALSE;
                        }
                        break;
                case C_ENUM:
                        if (entries[i].defval != NULL) {
                                *((AnEnum *)entries[i].data) =
                                        (AnEnum)atoi(entries[i].defval);
                        } else {
                                *((AnEnum *)entries[i].data) = 0;
                        }
                        break;
                case C_USHORT:
                        if (entries[i].defval != NULL) {
                                *((unsigned short *)entries[i].data) =
                                        (unsigned short)atoi(entries[i].defval);
                        } else {
                                *((unsigned short *)entries[i].data) = 0;
                        }
                        break;
                case C_OTHER:
                default:
                        break;
                }
        }
}


void conf_read_config(confEntry *entry, const char *section,
                      const char *cfile, const char *encoding)
{
        FILE *fp;
        char *buf[CONFBUFSIZE];
        char *section_label;
        HashTable *entry_ht;

        if (!entry || !section || !cfile) {
                fprintf(stderr, "Invalid arguments\n");
                return;
        }

        /* FIXME: Incomplete - need to implement this. */
}
