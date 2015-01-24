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
#include "CGenUtils.h"
#include <QStringList>
QTime CGenUtils::ConvertSecsToQTime(unsigned int iSeconds) {
    QTime objTime;
    if(iSeconds < 86400) {
        int iSec = 0;
        int iMin = 0;
        int iHr = 0;

        iHr = iSeconds / 3600;
        iSeconds = iSeconds % 3600;

        iMin = iSeconds / 60;
        iSeconds = iSeconds % 60;

        iSec = iSeconds;
        objTime.setHMS(iHr,iMin,iSec);
    }
    return objTime;
}

void CGenUtils::DateTimeToHHMMSS(const QDateTime& objDateTime,QString& strTime) {
    QTime objTime = objDateTime.time();
    TimeToHHMMSS(objTime,strTime);
}

void CGenUtils::DateTimeToHHMMSS(const QDateTime* pobjDateTime,QString& strTime) {
    if(pobjDateTime->isValid()) {
        QTime objTime = pobjDateTime->time();
        TimeToHHMMSS(objTime,strTime);
    } else {
        strTime.clear();
    }
}

void CGenUtils::TimeToHHMMSS(const QTime& objTime,QString& strTime) {
    int hh = objTime.hour();
    int mm = objTime.minute();
    int ss = objTime.second();

    strTime = QString("%1:%2:%3")
            .arg(hh,2,10,QChar('0'))
            .arg(mm,2,10,QChar('0'))
            .arg(ss,2,10,QChar('0'));
}

int CGenUtils::DateTimeToTotalSecs(const QDateTime& objDateTime) {
    QTime objTime = objDateTime.time();
    return (objTime.hour() * 3600 +
            objTime.minute() * 60 +
            objTime.second());

}

int CGenUtils::GetSeconds(const QString& strTime) {
    if(strTime.isNull() || strTime.isEmpty()) {
        return 0;
    }
    QStringList strTimeComp = strTime.split(":");
    //we will always have hh:mm:ss
    return (strTimeComp.at(0).toInt()*3600 +
            strTimeComp.at(1).toInt()* 60 +
            strTimeComp.at(2).toInt());
}

bool CGenUtils::DateCompare(const QDateTime& left, const QDateTime &right) {
    return (left < right);
}

void CGenUtils::SapSleep(unsigned long iNumMilliSecs) {
    CSapSleep objSleep;
    objSleep.sleep(iNumMilliSecs);
}

 QString CGenUtils::GetTimeStringFromSeconds(int iSeconds) {
     QString strTime;
     if(iSeconds > 86400) {
         int iNumDays = iSeconds / 86400;
         int iRemainingSecs = iSeconds % 86400;
         QTime objRemainigTime = CGenUtils::ConvertSecsToQTime(iRemainingSecs);
         int hh = objRemainigTime.hour();
         int mm = objRemainigTime.minute();
         int ss = objRemainigTime.second();
         hh += iNumDays * 24;
         strTime.sprintf("%02d:%02d:%02d",hh,mm,ss);
     } else {
         strTime = CGenUtils::ConvertSecsToQTime(iSeconds).toString();
     }
     return strTime;
 }
