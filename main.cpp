/*=============================================================================
This is a Program to demonstrate a Graphics Pie Application with some effects.
Copyright (C) 2015  Pradyumna Pramod Saraph
Contact: prady.pps@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the Lesser GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
Lesser GNU General Public License for more details.

You should have received a copy of the Lesser GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
=============================================================================*/
#include "CMainWindow.h"
#include <QApplication>
#include "pie/CGraphicsPieWidget.h"
#include "Utils/CGenUtils.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMainWindow w;

    CGraphicsPieWidget* pPieWidget =
            new CGraphicsPieWidget();
    pPieWidget->AddItem("One",QColor(133,194,254),20);
    QString strTime;
    CGenUtils::TimeToHHMMSS(CGenUtils::ConvertSecsToQTime(80),
                            strTime);
    pPieWidget->AddItem("two",QColor(153,0,0),80,true,
                        strTime);
    pPieWidget->AddItem("three",QColor(128,255,0),50,false,
                        "This is another special tool tip");
    pPieWidget->AddItem("four",QColor(0,153,76),90,true);
    pPieWidget->AddItem("five",QColor(255,153,51),80);
    w.setCentralWidget(pPieWidget);
    pPieWidget->SetMinimumRadius(480);
    pPieWidget->SetHeading("Main Label");
    pPieWidget->SetSubHeading("Sub Heading Label");
    pPieWidget->DrawPie();
    w.resize(580,580);
    w.show();

    
    return a.exec();
}
