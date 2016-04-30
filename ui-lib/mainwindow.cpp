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

#include "mainwindow.h"


MainWindow *MainWindow::m_Instance = NULL;

MainWindow::MainWindow(): QMainWindow()
{
        Q_ASSERT_X(m_Instance == NULL, "MainWindow", "MainWindow recreated");
        m_Instance = this;
}


MainWindow::~MainWindow()
{
        m_Instance = NULL;
}


MainWindow *MainWindow::instance()
{
        return m_Instance;
}
