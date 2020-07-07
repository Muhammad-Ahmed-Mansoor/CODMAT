#ifndef ORDERDIALOG2_H
#define ORDERDIALOG2_H

#include <QDialog>
#include<QLineEdit>
#include"button.h"
#include<QGridLayout>
class orderdialog2 : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* ask_row;
     QLineEdit* ask_col;
public:
    explicit orderdialog2(QWidget *parent = nullptr);
    unsigned int row;
    unsigned int col;
  Button *createButton(const QString &text, const char *member);
signals:

public slots:
    void end_order();
};

#endif // ORDERDIALOG2_H
