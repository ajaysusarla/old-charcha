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
 * cstring - String handling library based of git's strbuf implementation.
 */

#include "cstring.h"
#include "util.h"

char cstring_base[1];

void cstring_grow(cstring *cstr, size_t len)
{
        int newbuf = !cstr->alloc;

        if (unsigned_add_overflows(len, 1) ||
            (unsigned_add_overflows(cstr->len, len+1))) {
                fprintf(stderr, "Not enough memory. Giving up!");
                exit(EXIT_FAILURE);
        }

        if (newbuf)
                cstr->buf = NULL;
        ALLOC_GROW(cstr->buf, cstr->len + len + 1, cstr->alloc);
        if (newbuf)
                cstr->buf[0] = '\0';
}

void cstring_init(cstring *cstr, size_t len)
{
        cstr->len = 0;
        cstr->alloc = 0;
        cstr->buf = cstring_base;
        if (len)
                cstring_grow(cstr, len);
}

void cstring_release(cstring *cstr)
{
        if (cstr->alloc) {
                free(cstr->buf);
                cstring_init(cstr, 0);
        }
}

char *cstring_detach(cstring *cstr, size_t *len)
{
        char *res;

        cstring_grow(cstr, 0);
        res = cstr->buf;
        if (len)
                *len = cstr->len;

        cstring_init(cstr, 0);

        return res;
}

void cstring_attach(cstring *cstr, void *buf, size_t len, size_t alloc)
{
        cstring_release(cstr);
        cstr->buf = buf;
        cstr->len = len;
        cstr->alloc = alloc;
        cstring_grow(cstr, 0);
        cstr->buf[cstr->len] = '\0';
}
