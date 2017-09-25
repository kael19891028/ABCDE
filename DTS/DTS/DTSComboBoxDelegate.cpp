#include "DTSComboBoxDelegate.h"



DTSComboBoxDelegate::DTSComboBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}


DTSComboBoxDelegate::~DTSComboBoxDelegate()
{
}

QWidget* DTSComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    QComboBox* editor = new QComboBox(parent);
    //editor->addItem(STR_GSYNCH_UPLD, QVariant((QInt32)GSYNCH_UPLD));
    //editor->addItem(STR_GSYNCH_DNLD, QVariant((QInt32)GSYNCH_DNLD));
    editor->addItem(STR_GSYNCH_UPLD);
    editor->addItem(STR_GSYNCH_DNLD);
    editor->installEventFilter(const_cast<DTSComboBoxDelegate*>(this));

    return editor;
}

//void DTSComboBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//
//}
//QSize DTSComboBoxDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    return option.rect.size();
//}

void DTSComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox* itEditor = qobject_cast<QComboBox *>(editor);
    if (itEditor)
    {
        itEditor->setCurrentIndex(index.model()->data(index, Qt::EditRole).toInt());
    }
}

void DTSComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *itEditor = qobject_cast<QComboBox *>(editor);
    if (itEditor)
    {
       // model->setData(index, itEditor->currentText(), Qt::UserRole);
        model->setData(index, itEditor->currentText());
    }
}

void DTSComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
