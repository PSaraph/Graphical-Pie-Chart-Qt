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
#include "CGraphicsPieItem.h"
#include <QPen>
#include <QBrush>
#include "../Utils/CGenUtils.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>


CGraphicsPieItem::CGraphicsPieItem(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    m_bHasHatchedColor(false),
    m_bItemAltered(false) {
    this->setAcceptHoverEvents(true);
}

void CGraphicsPieItem::SetColor(const QColor& objColor,
                                bool bHatch) {
    m_objItemColor = objColor;
    m_bHasHatchedColor = bHatch;
    if(bHatch) {
        this->setBrush(* new QBrush(m_objItemColor,Qt::Dense2Pattern));
    } else {
        this->setBrush(* new QBrush(m_objItemColor));
    }
    this->setPen(* new QPen(Qt::NoPen));
}

void CGraphicsPieItem::SetItemVal(const int& iItemVal) {
    m_iItemVal = iItemVal;
}

void CGraphicsPieItem::SetKey(const QString& strKey) {
    m_strKey = strKey;
}

void CGraphicsPieItem::GenerateAndSetTooltip() {
    QString strToolTip;
    strToolTip.append(m_strKey).append(" (")
            .append(QString::number(m_iItemVal))
            .append(")");
    setToolTip(strToolTip);
}

void CGraphicsPieItem::SetSpecialToolTip(const QString&
                                         strSpecialToolTip) {
    setToolTip(strSpecialToolTip);
}

void CGraphicsPieItem::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget) {
    if(!m_objOrigRect.isValid()) {
        m_objOrigRect = rect();
    }

    if(option->state & QStyle::State_MouseOver ) {
        QPen pen = painter->pen() ;
        pen.setWidth(5) ;
        pen.setCapStyle(Qt::RoundCap);
        pen.setColor(this->GetItemColor()) ;
        painter->setPen(pen) ;

        QBrush brush ;
        brush.setStyle(Qt::NoBrush);
        painter->setBrush(brush);
        QRectF r = rect().adjusted(-13,-13,13,13);
        if(!m_bItemAltered) {
            this->setRect(r);
            m_bItemAltered = true;
        }
        painter->drawArc(r,this->startAngle(),this->spanAngle());
    } else {
        m_bItemAltered = false;
        this->setRect(m_objOrigRect);
    }
    QGraphicsEllipseItem::paint(painter,option,widget);
}

void CGraphicsPieItem::ReDraw() {
    this->update();
}

QRectF CGraphicsPieItem::boundingRect() const {
    QRectF r = rect() ;
    r.adjust(-70, -70, 70, 70) ;
    return r ;
}

void CGraphicsPieItem::hoverEnterEvent(QGraphicsSceneHoverEvent *
                                       event) {
    update();
    QGraphicsEllipseItem::hoverEnterEvent(event);
}

void CGraphicsPieItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *
                                       event) {
    update();
    QGraphicsEllipseItem::hoverLeaveEvent(event);
}

void CGraphicsPieItem::hoverMoveEvent(QGraphicsSceneHoverEvent *
                                      event) {
    update();
    QGraphicsEllipseItem::hoverMoveEvent(event);
}
