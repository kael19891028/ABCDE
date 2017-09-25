// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   DTSPageRunConfig.cpp
**
**  @description
**      界面-运行参数配置
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "DTSPageRunConfig.h"
#include "DTSMessageBox.h"


DTSPageRunConfig::DTSPageRunConfig(const TRUNCONFIG& config, QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
    , m_tRunConfig(config)
{
    m_ui.setupUi(this);
    this->setWindowTitle(STR_UI_MAINWINDOW_RUNCONFIG);
    this->setWindowIcon(QIcon(STR_PICTURE_ACTION_RUNCONFIG));
    this->setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint);


    QObject::connect(m_ui.m_pbCreate, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_Create()));
    QObject::connect(m_ui.m_pbCancel, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_Cancel()));
    QObject::connect(m_ui.m_pbSelect, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_Select()));
    QObject::connect(m_ui.m_pbUseDef, SIGNAL(clicked()), this, SLOT(Slot_PushButton_clicked_UseDef()));

    initUI();
}

DTSPageRunConfig::~DTSPageRunConfig()
{
}

void DTSPageRunConfig::Slot_PushButton_clicked_Create()
{
    qDebug() << "Slot_PushButton_clicked_Create";

    if (m_ui.m_leLGPATH->text().isEmpty()
        || m_ui.m_leLGNAME->text().isEmpty()
        || m_ui.m_leLGMCNT->text().isEmpty()
        || m_ui.m_leLGMSIZ->text().isEmpty()
        || m_ui.m_leTMUPLD->text().isEmpty()
        || m_ui.m_leTMDNLD->text().isEmpty()
        || m_ui.m_cbLGDLVL->currentText().isEmpty())
    {
        return;
    }

    m_tRunConfig.LG_ENAB = m_ui.m_cbLGENAB->isChecked();
    m_tRunConfig.LG_PATH = m_ui.m_leLGPATH->text();
    m_tRunConfig.LG_NAME = m_ui.m_leLGNAME->text();
    m_tRunConfig.LG_MCNT = m_ui.m_leLGMCNT->text().toInt();
    m_tRunConfig.LG_MSIZ = m_ui.m_leLGMSIZ->text().toInt();
    m_tRunConfig.LG_DLVL = m_ui.m_cbLGDLVL->currentIndex();
    m_tRunConfig.TM_UPLD = m_ui.m_leTMUPLD->text().toInt();
    m_tRunConfig.TM_DNLD = m_ui.m_leTMDNLD->text().toInt();

    qConfig->SetRunConfig(m_tRunConfig);

    DTSMessageBox msgBox(DTSMessageBox::EMBTYPE_SAVECONFIRM);
    msgBox.exec();

    this->close();
}

void DTSPageRunConfig::Slot_PushButton_clicked_Cancel()
{
    qDebug() << "Slot_PushButton_clicked_Cancel";

    this->close();
}

void DTSPageRunConfig::Slot_PushButton_clicked_Select()
{
    qDebug() << "Slot_PushButton_clicked_Cancel";

    QFileDialog fileDialog;
    fileDialog.setFileMode(QFileDialog::DirectoryOnly);
    fileDialog.setOption(QFileDialog::ShowDirsOnly, true);
    if (fileDialog.exec() == QDialog::Accepted)
    {
        m_ui.m_leLGPATH->setText(fileDialog.directory().absolutePath());
    }
}

void DTSPageRunConfig::Slot_PushButton_clicked_UseDef()
{
    qDebug() << "Slot_PushButton_clicked_Reset";

    m_tRunConfig = TRUNCONFIG();

    initUI();
}

void DTSPageRunConfig::initUI()
{
    m_ui.m_cbLGENAB->setChecked(m_tRunConfig.LG_ENAB);

    m_ui.m_cbLGDLVL->addItems(qLogger->t_LogStr);
    m_ui.m_cbLGDLVL->setCurrentIndex(m_tRunConfig.LG_DLVL);

    m_ui.m_leLGPATH->setText(m_tRunConfig.LG_PATH);
    m_ui.m_leLGNAME->setText(m_tRunConfig.LG_NAME);
    m_ui.m_leLGMCNT->setText(QString::number(m_tRunConfig.LG_MCNT));
    m_ui.m_leLGMSIZ->setText(QString::number(m_tRunConfig.LG_MSIZ));

    m_ui.m_leTMUPLD->setText(QString::number(m_tRunConfig.TM_UPLD));
    m_ui.m_leTMDNLD->setText(QString::number(m_tRunConfig.TM_DNLD));
}