// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSMessageBox.cpp
**
**  @description
**      界面-消息框
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "DTSMessageBox.h"


DTSMessageBox::DTSMessageBox(EMBTYPE enType, const QString& m_WTitle, const QString& m_Title)
    : m_enType(enType)
{
    initUI();
}

DTSMessageBox::~DTSMessageBox()
{
}

void DTSMessageBox::initUI()
{
    this->setWindowIcon(QIcon(STR_PICTURE_MAIN));

    switch (m_enType)
    {
    case EMBTYPE_SAVECONFIRM:
        showSaveConfirm();
        break;
    case EMBTYPE_CREATECONFIRM:
        showCreateConfirm();
        break;
    case EMBTYPE_DELETECONFIRM:
        showDeleteConfirm();
        break;
    case EMBTYPE_QUITCONFIRM:
        showQuitConfirm();
        break;
    case EMBTYPE_QUITFORCE:
        showQuitForce();
        break;
    }
}

void DTSMessageBox::showSaveConfirm()
{
    this->setIcon(QMessageBox::Information);
    this->setStandardButtons(QMessageBox::Yes);
    this->setButtonText(QMessageBox::Yes, STR_MESSAGEBOX_BUTTON_YES);
    this->setWindowTitle(STR_MESSAGEBOX_TITLE_INF);
    this->setText(STR_MESSAGEBOX_TXT_SAVECONFIRM);
}

void DTSMessageBox::showCreateConfirm()
{
    this->setIcon(QMessageBox::Information);
    this->setStandardButtons(QMessageBox::Yes);
    this->setButtonText(QMessageBox::Yes, STR_MESSAGEBOX_BUTTON_YES);
    this->setWindowTitle(STR_MESSAGEBOX_TITLE_INF);
    this->setText(STR_MESSAGEBOX_TXT_CREATECONFIRM);
}

void DTSMessageBox::showDeleteConfirm()
{
    this->setIcon(QMessageBox::Warning);
    this->setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    this->setButtonText(QMessageBox::Cancel, STR_MESSAGEBOX_BUTTON_CANCEL);
    this->setButtonText(QMessageBox::Yes, STR_MESSAGEBOX_BUTTON_YES);
    this->setWindowTitle(STR_MESSAGEBOX_TITLE_WAR);
    this->setText(STR_MESSAGEBOX_TXT_DELETECONFIRM);
}

void DTSMessageBox::showQuitConfirm()
{
    this->setIcon(QMessageBox::Warning);
    this->setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    this->setButtonText(QMessageBox::Cancel, STR_MESSAGEBOX_BUTTON_CANCEL);
    this->setButtonText(QMessageBox::Yes, STR_MESSAGEBOX_BUTTON_YES);
    this->setWindowTitle(STR_MESSAGEBOX_TITLE_WAR);
    this->setText(STR_MESSAGEBOX_TXT_QUITCONFIRM);
}

void DTSMessageBox::showQuitForce()
{
    this->setIcon(QMessageBox::Critical);
    this->setStandardButtons(QMessageBox::Yes);
    this->setButtonText(QMessageBox::Yes, STR_MESSAGEBOX_BUTTON_YES);
    this->setWindowTitle(STR_MESSAGEBOX_TITLE_CRI);
    this->setText(STR_MESSAGEBOX_TXT_UNKOWNCMD);
}