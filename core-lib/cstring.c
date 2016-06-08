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

#include "cstring.h"

char cstring_base[1];

void cstring_grow(cstring *cstr, size_t len)
{
}

void cstring_init(cstring *cstr)
{
        cstr->len = 0;
        cstr->alloc = 0;
        cstr->buf = cstring_base;
}

void cstring_new(cstring *cstr, size_t len)
{
        cstring_init(cstr);

        if (len)
                cstring_grow(cstr, len);
}

void cstring_free(cstring *cstr)
{
        if (cstr->alloc) {
                free(cstr->buf);
                cstring_init(cstr);
        }
}

