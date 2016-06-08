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
 * cstring - A tiny string library
 */

#ifndef _CSTRING_H_
#define _CSTRING_H_


struct _cstring {
        size_t len;
        size_t alloc;
        char *buf;
};

typedef struct _cstring cstring;


void cstring_new(cstring *cstr, size_t len);
void cstring_free(cstring *cstr);
void cstring_grow(cstring *cstr, size_t len);
void cstring_init(cstring *cstr);

#endif  /* _CSTRING_H_ */
