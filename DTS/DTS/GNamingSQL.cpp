// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   GNamingSQL.cpp
**
**  @description
**      公用数据库语句类
**
**  @history
**  001     2017/09/22      weiheng     创建该文档
******************************************************************************/
//=============================================================================

#include "GNamingSQL.h"

GNamingSQL& GNamingSQL::Instance()
{
    static GNamingSQL inst;

    return inst;
}

GNamingSQL::GNamingSQL()
{

}

GNamingSQL::~GNamingSQL()
{

}

GERROR GNamingSQL::Initialize(const QString& strAppID)
{
    m_strAppID = strAppID;
    
    if (!readNamingSQL() || !readNamingTBL())
    {
        return GERROR_TASK_READXML_ERROR;
    }

    return GERROR_OK;
}

GERROR GNamingSQL::UnInitialize()
{
    m_tSQL.clear();
    m_tTBLUpld.clear();
    m_tTBLDnld.clear();

    return GERROR_OK;
}


QBool GNamingSQL::readNamingSQL()
{
    m_tSQL.clear();

    QDomDocument xmldoc(STR_XML_ATTRIBUTE_NAMINGSQL);
    QFile file(QString(STR_COMB_KEY_VALUE).arg(m_strAppID).arg(DEFAULT_APP_NS_FILE));

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << QString(STR_NAMINGSQL_OPENFILE_ERROR).arg(file.fileName());
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorCol;
    if (!xmldoc.setContent(&file, true, &errorStr, &errorLine, &errorCol))
    {
        qWarning() << QString(STR_NAMINGSQL_READXML_ERROR).arg(errorLine).arg(errorCol).arg(errorStr);
        file.close();
        return false;
    }
    file.close();

    QDomElement xmlElem = xmldoc.documentElement();
    QDomNode xmlNod = xmlElem.firstChild();
    while (!xmlNod.isNull())
    {
        QDomElement ele = xmlNod.toElement();
        if (!ele.isNull()) {
            QString name = ele.attribute(STR_XML_ATTRIBUTE_NAME);
            QString text = ele.text();

            m_tSQL.insert(name, text);
        }
        xmlNod = xmlNod.nextSibling();
    }
    return true;
}

QBool GNamingSQL::readNamingTBL()
{
    m_tTBLUpld.clear();
    m_tTBLDnld.clear();

    QDomDocument xmldoc(STR_XML_ATTRIBUTE_NAMINGTBL);
    QFile file(QString(STR_COMB_KEY_VALUE).arg(m_strAppID).arg(DEFAULT_APP_NT_FILE));

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << QString(STR_NAMINGSQL_OPENFILE_ERROR).arg(file.fileName());
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorCol;
    if (!xmldoc.setContent(&file, true, &errorStr, &errorLine, &errorCol))
    {
        qWarning() << QString(STR_NAMINGSQL_READXML_ERROR).arg(errorLine).arg(errorCol).arg(errorStr);
        file.close();
        return false;
    }
    file.close();

    QDomElement xmlElem = xmldoc.documentElement();
    QDomNode xmlNod = xmlElem.firstChild();
    while (!xmlNod.isNull())
    {
        QDomNode nodTable = xmlNod.firstChild();
        QString strName;
        QString strOperate;
        QInt32 nType;
        while (!nodTable.isNull()) 
        {    
            QDomElement ele = nodTable.toElement();
            if (ele.nodeName() == STR_XML_ATTRIBUTE_NAME)
            {
                strName = ele.text();
            }
            else if (ele.nodeName() == STR_XML_ATTRIBUTE_OPERATE)
            {
                strOperate = ele.text();
            }
            else if (ele.nodeName() == STR_XML_ATTRIBUTE_TYPE)
            {
                nType = ele.text().toInt();
            }

            if (nType == GSYNCH_UPLD)
            {
                m_tTBLUpld.insert(strName, strOperate);
            }
            else if (nType == GSYNCH_DNLD)
            {
                m_tTBLDnld.insert(strName, strOperate);
            }

            nodTable = nodTable.nextSibling();
        }
        xmlNod = xmlNod.nextSibling();
    }
    return true;
}

