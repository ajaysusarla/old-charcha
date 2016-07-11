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

#include "conf-common.h"

confCommon conf_common;


static confEntry entries[] = {
        /* View */
        {"show_channel_list", "FALSE", &conf_common.show_channel_list, C_BOOL},
        {"show_user_list", "FALSE", &conf_common.show_user_list, C_BOOL},
        {"show_time_stamps", "FALSE", &conf_common.show_time_stamps, C_BOOL},

        /* Spell Check */
        {"check_spell", "FALSE", &conf_common.check_spell, C_BOOL},
        {"spell_lang", "en", &conf_common.spell_lang, C_STRING},

        /* Misc */
        {"confirm_on_exit", "FALSE", &conf_common.confirm_on_exit, C_BOOL},

        /* External Commands */
        {"uri_open_command", "", &conf_common.uri_open_cmd, C_STRING}, /* FIXME: need command */

        {NULL, NULL, NULL, C_OTHER}
};

confCommon *conf_common_get(void)
{
        return &conf_common;
}

confEntry *conf_common_get_entries(void)
{
        return entries;
}
