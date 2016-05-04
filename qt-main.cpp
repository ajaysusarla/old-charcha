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

#include <stdio.h>

#include <iostream>

#include <QApplication>

#include "core-lib/qt-gui.h"
#include "ui-lib/mainwindow.h"

int main(int argc, char **argv)
{
        QApplication *application = new QApplication(argc, argv);
        (void)application;

        std::cout << "[charcha] Hello, World!\n";

        charcha_init_ui();

        MainWindow *m = MainWindow::instance();

        charcha_run_ui();

        charcha_exit_ui();

        return 0;
}
