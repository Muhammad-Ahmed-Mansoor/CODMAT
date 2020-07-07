#ifndef EQUATIONINPUT_H
#define EQUATIONINPUT_H

#include <QDialog>
#include"cmplx.h"
#include"squarematrix.h"
#include<QLineEdit>
#include"button.h"
#include<QGridLayout>
#include"columnvector.h"
class EquationInput : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* reals;
    QLineEdit* imags;
    unsigned int order;

    Button *createButton(const QString &text, const char *member);
    unsigned int index(unsigned int i, unsigned int j)const;
public:
    explicit EquationInput(unsigned int,QWidget *parent = nullptr);
    SquareMatrix* mat;
    ColumnVector *vec;
 signals:

 private slots:
     void make_matrix();
};

#endif // EQUATIONINPUT_H
