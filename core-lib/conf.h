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

#ifndef _CONF_H_
#define _CONF_H_

#include <stdio.h>

#define CONFBUFSIZE 1024

typedef enum {
        C_STRING,
        C_INT,
        C_BOOL,
        C_ENUM,
        C_USHORT,
        C_OTHER,
        NUM_CONF_TYPES
} confType;

typedef struct _confEntry {
        char *name;
        char *defval;
        void *data;
        confType type;
} confEntry;

typedef struct _confFile {
        FILE *fp;
        char *path;
        char *tmppath;
        size_t path_len;
} confFile;

confFile *conf_file_open(const char *path);
int conf_file_close(confFile *cfile);
void conf_read_config(confEntry *entry, const char *section,
                      const char *cfile, const char *encoding);

#endif  /* _CONF_H_ */
