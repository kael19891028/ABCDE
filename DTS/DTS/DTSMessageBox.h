// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSMessageBox.h
**
**  @description
**      界面-消息框
******************************************************************************/
//=============================================================================

#ifndef __DTSMESSAGEBOX_H__
#define __DTSMESSAGEBOX_H__

#include "GConfig.h"

class DTSMessageBox : public QMessageBox
{
    Q_OBJECT
public:
    enum EMBTYPE
    {
        EMBTYPE_DEFAULT = 0,
        EMBTYPE_SAVECONFIRM,
        EMBTYPE_CREATECONFIRM,
        EMBTYPE_DELETECONFIRM,
        EMBTYPE_QUITCONFIRM,
        EMBTYPE_QUITFORCE,
    };
public:
    DTSMessageBox(EMBTYPE enType = EMBTYPE_DEFAULT, const QString& m_WTitle = QString(), const QString& m_Title = QString());
    ~DTSMessageBox();

private:
    void initUI();

    void showSaveConfirm();
    void showCreateConfirm();
    void showDeleteConfirm();
    void showQuitConfirm();
    void showQuitForce();
private:
    EMBTYPE m_enType;
};

#endif