// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   GLogger.h
**
**  @author WeiHeng
**
**  @description
**      公用日志类
******************************************************************************/
//=============================================================================

#ifndef __GLOGGER_H__
#define __GLOGGER_H__

#include "GDefine.h"

#include <mutex>
#include <fstream>

class GLogger : public QThread
{
    Q_OBJECT
public:
    static GLogger& Instance();
    static void OutputMessage(QtMsgType type, const QMessageLogContext &context, const QString& msg);
    static void CheckDir();
    static void RenameFile();

public:
    static QStringList t_LogStr;

private:
    GLogger(QObject *parent = Q_NULLPTR);
    ~GLogger();



public:
    GERROR Initialize();


protected:
    virtual void run() Q_DECL_OVERRIDE;
   

signals:
    void sendMsg(const QString& strMsg);
    void putMsg();

public slots:
    void Slot_putMsg();

private:
    QBool putq(QString strMsg);
    QBool getq(QString& strMsg);
    void  writeLog(const QString& strMsg);


private:
    QLinkedList<QString>    m_queue;
    QMutex                  m_mx4queue;
    QFile                   m_file;

    std::mutex              m_mx4Write;
    std::fstream            m_fsWrite;


};

#endif // GLOGGER_H
