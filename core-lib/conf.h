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

typedef enum {
        C_STRING,
        C_INT,
        C_BOOL,
        C_ENUM,
        C_OTHER
} ConfType;

typedef struct _ConfEntry {
        char *name;
        char *default_val;
        void *data;
        ConfType type;
} ConfEntry;

typedef struct _ConfFile {
        FILE *fp;
        char *path;
        char *tmppath;
        size_t path_len;
} ConfFile;

ConfFile *conf_file_open(const char *path);
int conf_file_close(ConfFile *cfile);

#endif  /* _CONF_H_ */
