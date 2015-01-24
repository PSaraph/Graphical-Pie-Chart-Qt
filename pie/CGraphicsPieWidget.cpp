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
#include "CGraphicsPieWidget.h"
#include "CGraphicsPieItem.h"

CGraphicsPieWidget* CGraphicsPieWidget::m_pclsSelf = NULL;

CGraphicsPieWidget::CGraphicsPieWidget(QWidget *parent) :
    QWidget(parent),
    m_pObjMainVerticalLayout(NULL),
    m_pObjGLayoutLabel(NULL),
    m_pObjMainTitleLabel(NULL),
    m_pObjSubTitleLabel(NULL),
    m_pObjScene(NULL),
    m_pObjPieView(NULL),
    m_iStartAngle(0),
    m_iTotalValueOfItems(0),
    m_iRadius(480){
    SetUp();
    m_pclsSelf = this;
    setAutoFillBackground(true);
    setPalette(QPalette(qRgba(255,255,255,255)));
}

CGraphicsPieWidget::~CGraphicsPieWidget() {
    ClearItems();
    m_pclsSelf = NULL;
}

void CGraphicsPieWidget::SetUp() {
    m_pObjMainVerticalLayout = new QVBoxLayout(this);
    m_pObjMainVerticalLayout->setObjectName(
                QString::fromUtf8("m_pObjMainVerticalLayout"));
    m_pObjMainVerticalLayout->setSpacing(0);
    m_pObjGLayoutLabel = new QGridLayout();
    m_pObjGLayoutLabel->setSpacing(0);
    m_pObjGLayoutLabel->setObjectName(
                QString::fromUtf8("m_pObjGLayoutLabel"));
    m_pObjMainTitleLabel = new QLabel(this);
    m_pObjMainTitleLabel->setAutoFillBackground(true);
    m_pObjMainTitleLabel->setPalette(
                QPalette(qRgba(255,255,255,255)));
    m_pObjMainTitleLabel->setObjectName(
                QString::fromUtf8("m_pObjMainTitleLabel"));
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    font.setWeight(75);
    m_pObjMainTitleLabel->setFont(font);
    m_pObjMainTitleLabel->setLineWidth(0);
    m_pObjMainTitleLabel->setScaledContents(true);
    m_pObjMainTitleLabel->setAlignment(Qt::AlignCenter);

    m_pObjGLayoutLabel->addWidget(m_pObjMainTitleLabel, 0, 0, 1, 1);

    m_pObjSubTitleLabel = new QLabel(this);
    m_pObjSubTitleLabel->setAutoFillBackground(true);
    m_pObjSubTitleLabel->setPalette(QPalette(qRgba(255,255,255,255)));
    m_pObjSubTitleLabel->setObjectName(QString::fromUtf8("m_pObjSubTitleLabel"));
    QFont font1;
    font1.setPointSize(10);
    m_pObjSubTitleLabel->setFont(font1);
    m_pObjSubTitleLabel->setLineWidth(0);
    m_pObjSubTitleLabel->setAlignment(Qt::AlignCenter);

    m_pObjGLayoutLabel->addWidget(m_pObjSubTitleLabel, 1, 0, 1, 1);


    m_pObjMainVerticalLayout->addLayout(m_pObjGLayoutLabel);
    Retranslate();
    SetPieScene();

    QMetaObject::connectSlotsByName(this);
}

void CGraphicsPieWidget::Retranslate()
{
    if(m_strHeadingText.isEmpty()) {
        m_strHeadingText = "Main Text";
    }

    if(m_strSubHeadingText.isEmpty()) {
        m_pObjSubTitleLabel->setText("Sub Heading");
    }
    m_pObjMainTitleLabel->setText(m_strHeadingText);
    m_pObjSubTitleLabel->setText(m_strSubHeadingText);
} // retranslateUi

void CGraphicsPieWidget::SetPieScene() {
    m_pObjScene = new QGraphicsScene(this);
    if(m_strHeadingText.isEmpty()) {
        m_strHeadingText = "Main Text";
    }
    m_pObjPieView = new CGraphicsPieView(m_pObjMainTitleLabel,m_pObjScene);
    m_pObjPieView->SetHeading(m_strHeadingText);
    m_pObjPieView->setObjectName(QString::fromUtf8("m_pObjPieView"));
    m_pObjPieView->setMouseTracking(true);
    m_pObjPieView->setFrameShape(QFrame::NoFrame);
    m_pObjPieView->setFrameShadow(QFrame::Plain);
    m_pObjPieView->setFocus();
    m_pObjPieView->setLineWidth(0);
    m_pObjPieView->mapToScene(0,0);
    m_pObjPieView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pObjPieView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pObjMainVerticalLayout->addWidget(m_pObjPieView);
}

void CGraphicsPieWidget::AddItem(const QString& strKey,
                                 const QColor& objColor,
                                 const int& iVal,
                                 bool bHatch,
                                 const QString &strSpecialToolTip) {
    if(iVal > 0) {
        lpsPieItemInfo pItemInfo = new sPieItemInfo;
        pItemInfo->strKey = strKey;
        pItemInfo->objColor = objColor;
        pItemInfo->iVal = iVal;
        pItemInfo->bHatch = bHatch;
        m_iTotalValueOfItems += iVal;
        if(!strSpecialToolTip.isEmpty()) {
            pItemInfo->strSpecialToolTip = strSpecialToolTip;
        }
        m_objPieItemInfoVec.push_back(pItemInfo);
        pItemInfo = NULL;
    }
}

void CGraphicsPieWidget::DrawPie() {
    QVectorIterator<lpsPieItemInfo> objIter(m_objPieItemInfoVec);
    CGraphicsPieItem* pPieItem = NULL;
    int height = m_pObjPieView->viewport()->height();
    int width = m_pObjPieView->viewport()->width();
    int iPieRadius = qMin(height,width);
    if(iPieRadius < m_iRadius) {
        iPieRadius = m_iRadius;
    }

    m_pObjMainTitleLabel->setText(m_strHeadingText);
    m_pObjSubTitleLabel->setText(m_strSubHeadingText);

    QStringList objItemTextList;
    while(objIter.hasNext()) {
        lpsPieItemInfo pItemInfo = objIter.next();
        int iCount = 1;
        if(pItemInfo) {
            pPieItem = new CGraphicsPieItem();
            if(pPieItem) {
                pPieItem->SetColor(pItemInfo->objColor, pItemInfo->bHatch);
                pPieItem->SetItemVal(pItemInfo->iVal);
                pPieItem->SetKey(pItemInfo->strKey);

                if(pItemInfo->strSpecialToolTip.isEmpty()) {
                    pPieItem->GenerateAndSetTooltip();
                } else {
                    pPieItem->SetSpecialToolTip(pItemInfo->strSpecialToolTip);
                }
                objItemTextList << pPieItem->GetItemKey() + " (" +
                                   QString::number(pPieItem->GetItemValue())
                                   + ")";
                MakeItemCoordinates(pPieItem,iPieRadius);
                iCount += 20;
                m_pObjScene->addItem(pPieItem);
                pPieItem = NULL;
            }
        }
    }

    objIter.toFront();
    int iCount = 0, iCounter = 1;
    while(objIter.hasNext()) {
        lpsPieItemInfo pItemInfo = objIter.next();
        if(pItemInfo) {
            MakeTextCoordinates(pItemInfo,
                                iPieRadius,
                                objItemTextList.at(iCount),
                                iCounter);
            iCounter += 1;
            pPieItem = NULL;
        }
        ++iCount;
    }
}

void CGraphicsPieWidget::MakeItemCoordinates(CGraphicsPieItem *pPieItem,
                                             const int& iPieRadius) {
    if(pPieItem) {
        pPieItem->setStartAngle(m_iStartAngle * 16.00);
        int Span = 360.00 * pPieItem->GetItemValue() / m_iTotalValueOfItems;
        m_iStartAngle +=  Span;
        pPieItem->setSpanAngle(Span * 16.00);
        pPieItem->setRect(0,-iPieRadius*0.35,iPieRadius*0.35,iPieRadius*0.35);
    }
}

void CGraphicsPieWidget::MakeTextCoordinates(sPieItemInfo* pItemInfo,
                                             const int& iPieRadius,
                                             const QString& strItemText,
                                             const int& iCounter) {
    if(pItemInfo) {
        QGraphicsRectItem* pObjRectItem =
                new QGraphicsRectItem(iPieRadius* 0.3,
                                      20.5 * iCounter,
                                      20,
                                      20);
        if(pItemInfo->bHatch) {
            pObjRectItem->setBrush(* new
                                   QBrush(pItemInfo->objColor,
                                          Qt::Dense2Pattern));
        } else {
            pObjRectItem->setBrush(* new QBrush(pItemInfo->objColor));
        }
        pObjRectItem->setPen(Qt::NoPen);
        m_pObjScene->addItem(pObjRectItem);
        pObjRectItem = NULL;

        QGraphicsTextItem* pTextItem = new QGraphicsTextItem(strItemText);
        pTextItem->setPos(iPieRadius* 0.3 + 20,20.5 * iCounter);
        m_pObjScene->addItem(pTextItem);
        pTextItem = NULL;
    }
}

void CGraphicsPieWidget::ClearItems() {
    QVectorIterator<lpsPieItemInfo> objIter(m_objPieItemInfoVec);
    while(objIter.hasNext()) {
        lpsPieItemInfo pItemInfo = objIter.next();
        if(pItemInfo) {
            delete pItemInfo;
            pItemInfo = NULL;
        }
    }
    m_objPieItemInfoVec.clear();
    m_pObjScene->clear();
    m_iStartAngle = 0;
    m_iTotalValueOfItems = 0;
}


void CGraphicsPieWidget::resizeEvent(QResizeEvent * /* pEvent*/) {
    QRectF bounds = m_pObjScene->itemsBoundingRect();
    bounds.setWidth(bounds.width()*0.9);         // to tighten-up margins
    bounds.setHeight(bounds.height()*0.9);       // same as above
    m_pObjPieView->fitInView(bounds, Qt::KeepAspectRatio);
    m_pObjPieView->centerOn(0, 0);
}
