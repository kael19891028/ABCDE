#pragma once

#include "GDefine.h"

class DTSComboBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    DTSComboBoxDelegate(QObject *parent = Q_NULLPTR);
    ~DTSComboBoxDelegate();

public:
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
//    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
//    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const Q_DECL_OVERRIDE;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;


    //private slots:
    //void commitAndCloseEditor();

};

