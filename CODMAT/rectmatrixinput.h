#ifndef RectMATRIXINPUT_H
#define RectMATRIXINPUT_H

#include <QDialog>
#include"cmplx.h"
#include"matrix.h"
#include<QLineEdit>
#include"button.h"
#include<QGridLayout>

class RectMatrixInput : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* reals;
    QLineEdit* imags;
    unsigned int rows;
    unsigned int cols;

    Button *createButton(const QString &text, const char *member);
    unsigned int index(unsigned int i, unsigned int j)const;
public:
    explicit RectMatrixInput(unsigned int,unsigned int ,QWidget *parent = nullptr);
   Matrix* mat;
signals:

private slots:
    void make_matrix();
};

#endif // RectMATRIXINPUT_H
