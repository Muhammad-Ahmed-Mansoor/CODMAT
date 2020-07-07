#ifndef SQUAREMATRIXINPUT_H
#define SQUAREMATRIXINPUT_H

#include <QDialog>
#include"cmplx.h"
#include"squarematrix.h"
#include<QLineEdit>
#include"button.h"
#include<QGridLayout>

class SquareMatrixInput : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* reals;
    QLineEdit* imags;
    unsigned int order;

    Button *createButton(const QString &text, const char *member);
    unsigned int index(unsigned int i, unsigned int j)const;
public:
    explicit SquareMatrixInput(unsigned int,QWidget *parent = nullptr);
   SquareMatrix* mat;
signals:

private slots:
    void make_matrix();
};

#endif // SQUAREMATRIXINPUT_H
