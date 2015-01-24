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
#ifndef CGRAPHICSPIEVIEW_H
#define CGRAPHICSPIEVIEW_H

#include <QGraphicsView>
#include <QLabel>
#include <QMouseEvent>
#include "CGraphicsPieItem.h"
class CGraphicsPieView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CGraphicsPieView(QLabel* pLabel ,
                              QWidget *parent = 0);
    explicit CGraphicsPieView(QLabel* pLabel,
                              QGraphicsScene *scene,
                              QWidget *parent = 0);

    void SetHeading(const QString& strHeading) {
        m_strHeadingLabelText = strHeading;
        m_pLabel->setText(strHeading);
    }

protected:
    void resizeEvent(QResizeEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void focusOutEvent(QFocusEvent *event);
private:
    QString m_strHeadingLabelText;
    QLabel *m_pLabel;
    CGraphicsPieItem* m_pCurrentItemRef;
};

#endif // CGRAPHICSPIEVIEW_H
