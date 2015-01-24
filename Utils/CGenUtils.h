#ifndef CGENUTILS_H
#define CGENUTILS_H
#include <QTime>
#include <QDateTime>
#include <QMutex>
#include <QWaitCondition>

class CSapSleep{
     QMutex m_objLocalMutex;
     QWaitCondition m_objWaitObject;
public:
    CSapSleep() {
        m_objLocalMutex.lock();
    }

    void sleep(unsigned long sleepMS) {
        m_objWaitObject.wait(&m_objLocalMutex, sleepMS);
    }

    void CancelSleep() {
        m_objWaitObject.wakeAll();
    }
};

class CGenUtils {
public:
    //This Routine will only cater for 24 hr difference
    static QTime ConvertSecsToQTime(unsigned int iSeconds);
    static void DateTimeToHHMMSS(const QDateTime& objDateTime,QString& strTime);
    static void DateTimeToHHMMSS(const QDateTime* pobjDateTime,QString& strTime);
    static void TimeToHHMMSS(const QTime& objTime,QString& strTime);
    static int DateTimeToTotalSecs(const QDateTime& objDateTime);
    static int GetSeconds(const QString& strTime);
    static bool DateCompare(const QDateTime& left, const QDateTime &right);
    static void SapSleep(unsigned long iNumMilliSecs);
    static QString GetTimeStringFromSeconds(int iSeconds);
};

#endif // CGENUTILS_H
