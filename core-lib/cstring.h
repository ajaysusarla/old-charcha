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
 *
 * cstring - String handling library based of git's strbuf implementation.
 */

#ifndef _CSTRING_H_
#define _CSTRING_H_

#include <stdio.h>
#include <stdlib.h>

struct _cstring {
        size_t len;
        size_t alloc;
        char *buf;
};

typedef struct _cstring cstring;
extern char cstring_base[];
#define CSTRING_INIT {0, 0, cstring_base};

/* cstring_init():
 * Initialise the cstring structure.
 *
 */
void cstring_init(cstring *cstr, size_t len);

/* cstring_release():
 * Release the cstring structure and memory.
 */
void cstring_release(cstring *cstr);

/* cstring_detach():
 * The caller needs to free(), the string returned.
 */
char *cstring_detach(cstring *cstr, size_t *len);

/* cstring_attach():
 * Attach a string to a cstring buffer. You should
 * specify the string to attach, the length of string and
 * the amount of allocated memory. The amount should be
 * larger than the string length. This string must be
 * malloc()ed, and after attaching shouldn't be free()d.
 */
void cstring_attach(cstring *cstr, void *buf, size_t len, size_t alloc);

void cstring_grow(cstring *cstr, size_t len);

#endif  /* _CSTRING_H_ */

