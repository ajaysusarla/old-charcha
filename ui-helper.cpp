// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.


#include "qt-ui-lib/mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>

static MainWindow *window = NULL;

void charcha_init_ui(void)
{
        window = new MainWindow();
}


void charcha_run_ui(void)
{
        window->show();
        qApp->exec();
}


void charcha_exit_ui(void)
{
        delete window;
        delete qApp;
}

double get_screen_dpi(void)
{
        QDesktopWidget *mydesk = qApp->desktop();
        return mydesk->physicalDpiX();
}
