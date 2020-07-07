#ifndef ORDERDIALOG_H
#define ORDERDIALOG_H

#include <QDialog>
#include<QLineEdit>
#include"button.h"
#include<QGridLayout>
class orderdialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* ask_order;
public:
    explicit orderdialog(QString text,QWidget *parent = nullptr);
    unsigned int order;
  Button *createButton(const QString &text, const char *member);
signals:

public slots:
    void end_order();
};

#endif // ORDERDIALOG_H
