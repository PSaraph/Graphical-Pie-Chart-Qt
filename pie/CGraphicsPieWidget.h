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
#ifndef CGRAPHICSPIEWIDGET_H
#define CGRAPHICSPIEWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsScene>

#include "CGraphicsPieView.h"
#include "CGraphicsPieItem.h"
typedef struct _sPieItemInfo {
    QString strKey;
    int iVal;
    QColor objColor;
    bool bHatch;
    QString strSpecialToolTip;
}sPieItemInfo,*lpsPieItemInfo;

class CGraphicsPieWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CGraphicsPieWidget(QWidget *parent = 0);
    ~CGraphicsPieWidget();
    void AddItem(const QString& strKey,
                 const QColor& objColor,
                 const int& iVal, bool bHatch = false,
                 const QString& strSpecialToolTip="");
    void DrawPie();
    void ClearItems();

    inline void SetMinimumRadius(const int& iRadius) {
        m_iRadius = iRadius;
    }

    inline void SetHeading(const QString& strMainText) {
        m_strHeadingText = strMainText;
    }

    inline void SetSubHeading(const QString& strSubText) {
        m_strSubHeadingText = strSubText;
    }

private:
    void SetUp();
    void Retranslate();
    void SetPieScene();
    void MakeItemCoordinates(CGraphicsPieItem* pPieItem,
                             const int &iPieRadius);
    void MakeTextCoordinates(sPieItemInfo *pItemInfo,
                             const int& iPieRadius,
                             const QString& strItemText,
                             const int &iCounter);
    static CGraphicsPieWidget* GetMe() {
        return m_pclsSelf;
    }

protected:
    void resizeEvent(QResizeEvent * /* pEvent*/);
signals:
    
public slots:

private:
    QVBoxLayout *m_pObjMainVerticalLayout;
    QGridLayout *m_pObjGLayoutLabel;
    QLabel *m_pObjMainTitleLabel;
    QLabel *m_pObjSubTitleLabel;
    QGraphicsScene* m_pObjScene;
    CGraphicsPieView *m_pObjPieView;
    QVector<lpsPieItemInfo> m_objPieItemInfoVec;
    QString m_strHeadingText;
    QString m_strSubHeadingText;

    int m_iStartAngle;
    int m_iTotalValueOfItems;
    int m_iRadius;
    static CGraphicsPieWidget* m_pclsSelf;
};

#endif // CGRAPHICSPIEWIDGET_H
