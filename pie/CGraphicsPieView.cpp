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
#include "CGraphicsPieView.h"

CGraphicsPieView::CGraphicsPieView(QLabel *pLabel, QWidget *parent) :
    QGraphicsView(parent),m_pLabel(pLabel),m_pCurrentItemRef(NULL)
{
    setRenderHints(QPainter::Antialiasing |
                   QPainter::SmoothPixmapTransform |
                   QPainter::HighQualityAntialiasing);
}

CGraphicsPieView::CGraphicsPieView(QLabel *pLabel, QGraphicsScene *scene,
                                   QWidget *parent):
    QGraphicsView(scene,parent),m_pLabel(pLabel),m_pCurrentItemRef(NULL)
{
    setRenderHints(QPainter::Antialiasing |
                   QPainter::SmoothPixmapTransform |
                   QPainter::HighQualityAntialiasing);
}

void CGraphicsPieView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
}

void CGraphicsPieView::mouseMoveEvent(QMouseEvent *event) {
    m_pCurrentItemRef = dynamic_cast<CGraphicsPieItem*>(itemAt(event->pos()));
    if (m_pCurrentItemRef) {
        m_pLabel->setText(m_pCurrentItemRef->GetItemKey());
        QColor objColor = m_pCurrentItemRef->GetItemColor();
        int red = qRed(objColor.rgb());
        int green = qGreen(objColor.rgb());
        int blue = qBlue(objColor.rgb());
        QString strStyleSheetText = "QLabel {\n"\
                "color: rgb(";
        strStyleSheetText.append(QString::number(red)).append(",")
                .append(QString::number(green)).append(",")
                .append(QString::number(blue)).append(");\n}");
        m_pLabel->setStyleSheet(strStyleSheetText);
        m_pLabel->update();
    } else {
        QString strStyleSheetText = "QLabel {\n"\
                "color: rgb(0,0,0);\n}";
        m_pLabel->setStyleSheet(strStyleSheetText);
        m_pLabel->setText(m_strHeadingLabelText);
        m_pLabel->update();
    }
    QGraphicsView::mouseMoveEvent(event);
}

void CGraphicsPieView::focusOutEvent(QFocusEvent *event) {
    QString strStyleSheetText = "QLabel {\n"\
            "color: rgb(0,0,0);\n}";
    m_pLabel->setStyleSheet(strStyleSheetText);
    m_pLabel->setText(m_strHeadingLabelText);
    m_pLabel->update();
    QGraphicsView::focusOutEvent(event);
}
