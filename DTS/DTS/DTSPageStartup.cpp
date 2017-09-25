// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSPageStartup.cpp
**
**  @description
**      界面-启动页
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "DTSPageStartup.h"
#include "DTSPageSysConfig.h"
#include "DTSMessageBox.h"

DTSPageStartup::DTSPageStartup(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    this->m_ui.setupUi(this);
    this->setWindowTitle(STR_UI_MAINWINDOW_STARTUP);
    this->setWindowIcon(QIcon(STR_PICTURE_ACTION_LOGIN));
    this->setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    QObject::connect(m_ui.m_pbStart, SIGNAL(clicked()), this, SLOT(Slot_PushButton_Clicked_Start()));
    QObject::connect(m_ui.m_pbCreate, SIGNAL(clicked()), this, SLOT(Slot_PushButton_Clicked_Create()));
    QObject::connect(m_ui.m_pbDelete, SIGNAL(clicked()), this, SLOT(Slot_PushButton_Clicked_Delete()));



    initUI();

    // TODO
    m_ui.m_lblLogo->setText(QStringLiteral("JHMES DTS"));
}

DTSPageStartup::~DTSPageStartup()
{
}

QString DTSPageStartup::GetAppID()
{
    return m_strAppID;
}

void DTSPageStartup::Slot_PushButton_Clicked_Start()
{
    qDebug() << "Slot_PushButton_Clicked_Start";
    
    m_strAppID = m_ui.m_cbSelect->currentData().toString();

    this->close();
}

void DTSPageStartup::Slot_PushButton_Clicked_Create()
{
    qDebug() << "Slot_PushButton_Clicked_Create";

    DTSPageSysConfig SysConfigPage;
    SysConfigPage.exec();

    initUI();
}

void DTSPageStartup::Slot_PushButton_Clicked_Delete()
{
    qDebug() << "Slot_PushButton_Clicked_Delete";

    QString strAppID = m_ui.m_cbSelect->currentData().toString();
    if (strAppID.isEmpty())
    {
        return;
    }

    DTSMessageBox msgBox(DTSMessageBox::EMBTYPE_DELETECONFIRM);
    if (msgBox.exec() == QMessageBox::Cancel)
    {
        return;
    }
    qConfig->DeleteApp(strAppID);
    initUI();
}

void DTSPageStartup::initUI()
{
    m_ui.m_cbSelect->clear();

    /// 列表框初始化
    TAPPLIST config;
    qConfig->GetAllApp(config);

    for (TAPPLIST_IT it = config.begin(); it != config.end(); ++it)
    {
        m_ui.m_cbSelect->addItem(QIcon(STR_PICTURE_WORKSHOP), it.value(), it.key());
    }
}