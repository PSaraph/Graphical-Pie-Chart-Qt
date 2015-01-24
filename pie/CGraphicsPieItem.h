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
#ifndef CGRAPHICSPIEITEM_H
#define CGRAPHICSPIEITEM_H

#include <QGraphicsEllipseItem>
#include <QColor>

class CGraphicsPieItem : public QGraphicsEllipseItem
{
public:
    CGraphicsPieItem(QGraphicsItem *parent = 0);
    void SetColor(const QColor& objColor, bool bHatch = false);
    void SetItemVal(const int& iItemVal);
    void SetKey(const QString& strKey);
    void GenerateAndSetTooltip();
    void SetSpecialToolTip(const QString& strSpecialToolTip);
    void ReDraw();

public:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
public:
    inline int GetItemValue() const { return m_iItemVal; }
    inline QString GetItemKey() const { return m_strKey; }
    inline QColor GetItemColor() const { return m_objItemColor; }
    inline bool HasHatchedColor() const { return m_bHasHatchedColor;}
protected:
    QRectF boundingRect() const;
private:
    bool m_bHasHatchedColor;
    bool m_bItemAltered;
    int m_iItemVal;
    QColor m_objItemColor;
    QString m_strKey;
    QRectF m_objOrigRect;
};

#endif // CGRAPHICSPIEITEM_H
