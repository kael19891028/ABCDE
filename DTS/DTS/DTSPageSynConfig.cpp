// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSPageSynConfig.cpp
**
**  @description
**      界面-同步参数配置
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "DTSPageSynConfig.h"
#include "DTSComboBoxDelegate.h"

DTSPageSynConfig::DTSPageSynConfig(const QString& strApp_IID, QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
    , m_strAppID(strApp_IID)
{
    m_ui.setupUi(this);
    this->setWindowTitle(STR_UI_MAINWINDOW_SYNCONFIG);
    this->setWindowIcon(QIcon(STR_PICTURE_ACTION_SYNCONFIG));
    this->setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    QObject::connect(m_ui.m_pbSave, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_Save()));
    QObject::connect(m_ui.m_pbCancel, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_Cancel()));

    initUI();
}

DTSPageSynConfig::~DTSPageSynConfig()
{
}

void DTSPageSynConfig::Slot_PushButton_clicked_Save()
{
    qDebug() << "Slot_PushButton_clicked_Cancel";
}

void DTSPageSynConfig::Slot_PushButton_clicked_Cancel()
{
    qDebug() << "Slot_PushButton_clicked_Cancel";
    this->close();
}

void DTSPageSynConfig::initUI()
{
    QStandardItemModel* sqlModel = new QStandardItemModel(this);
    sqlModel->setHorizontalHeaderItem(0, new QStandardItem(STR_UI_SYNCONFIG_TABLETITLE_NAME));
    sqlModel->setHorizontalHeaderItem(1, new QStandardItem(STR_UI_SYNCONFIG_TABLETITLE_OPER));
    sqlModel->setHorizontalHeaderItem(2, new QStandardItem(STR_UI_SYNCONFIG_TABLETITLE_TYPE));
    sqlModel->setHorizontalHeaderItem(3, new QStandardItem(STR_CHAR_EMPTY));
    m_ui.m_tvTable->setModel(sqlModel);
    m_ui.m_tvTable->setColumnWidth(0, 250);
    m_ui.m_tvTable->setColumnWidth(1, 380);
    m_ui.m_tvTable->setColumnWidth(2, 100);
    m_ui.m_tvTable->setColumnWidth(3, 30);

    QStringList strSyn = QStringList() << STR_GSYNCH_UPLD << STR_GSYNCH_DNLD;

    DTSComboBoxDelegate* delegate = new DTSComboBoxDelegate(this);

    m_ui.m_tvTable->setItemDelegateForColumn(2, delegate);
    int i = 0;
    for (TMAPNAMINGTBL_IT it = qNaming->m_tTBLUpld.begin(); it != qNaming->m_tTBLUpld.end(); ++it)
    {
        sqlModel->setItem(i, 0, new QStandardItem(it.key()));
        sqlModel->setItem(i, 1, new QStandardItem(it.value()));
        sqlModel->setItem(i, 2, new QStandardItem(strSyn[0]));
        ++i;
    }
    for (TMAPNAMINGTBL_IT it = qNaming->m_tTBLDnld.begin(); it != qNaming->m_tTBLDnld.end(); ++it)
    {
        sqlModel->setItem(i, 0, new QStandardItem(it.key()));
        sqlModel->setItem(i, 1, new QStandardItem(it.value()));
        sqlModel->setItem(i, 2, new QStandardItem(strSyn[1]));
        ++i;
    }

    
}