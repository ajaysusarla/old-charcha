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

#ifndef _CONF_COMMON_H_
#define _CONF_COMMON_H_

#include "util.h"
#include "conf.h"

typedef struct _confCommon {

        /* View */
        bool_t show_channel_list;
        bool_t show_user_list;
        bool_t show_time_stamps;

        /* Spell Check */
        bool_t check_spell;
        char *spell_lang;

        /* Misc */
        bool_t confirm_on_exit;

        /* External Commands */
        char *uri_open_cmd;

} confCommon;

extern confCommon conf_common;

confCommon *conf_common_get(void);
confEntry *conf_common_get_entries(void);

#endif  /* _CONF_COMMON_H_ */
