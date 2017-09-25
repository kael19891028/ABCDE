// -*- C++ -*-

//=============================================================================
/******************************************************************************
**  @file   GNamingSQL.h
**
**  @description
**      公用数据库语句类
******************************************************************************/
//=============================================================================

#ifndef __GNAMINGSQL_H__
#define __GNAMINGSQL_H__

#include "GDefine.h"

class GNamingSQL
{
public:
    static GNamingSQL& Instance();

private:
    GNamingSQL();
    ~GNamingSQL();

public:
    GERROR Initialize(const QString& strAppID);
    GERROR UnInitialize();

private:
    QBool readNamingSQL();
    QBool readNamingTBL();

public:
    TMAPNAMINGSQL   m_tSQL;
    TMAPNAMINGTBL   m_tTBLUpld;
    TMAPNAMINGTBL   m_tTBLDnld;

private:
    QString         m_strAppID;
};

#endif
