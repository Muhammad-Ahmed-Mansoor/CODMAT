#include "squarematrixinput.h"



SquareMatrixInput::SquareMatrixInput(unsigned int n,QWidget *parent) : QDialog(parent)
{

order=n;
reals=new QLineEdit[order*order];
imags=new QLineEdit[order*order];

for(unsigned int i=0;i<order*order;i++)
{
    reals[i].setPlaceholderText("0");
    imags[i].setPlaceholderText("+j0");
}

Button *solve_button=createButton("Solve!",SLOT(make_matrix()));

  QGridLayout *mainLayout = new QGridLayout;

  for(unsigned int i=1;i<=order;i++)
  {
      for(unsigned int j=1;j<=order;j++)
      {
          mainLayout->addWidget(&reals[index(i,j)],i-1,3*(j-1));
           mainLayout->addWidget(&imags[index(i,j)],i-1,3*(j-1)+1);
      }
  }

  mainLayout->addWidget(solve_button,order,0);
  setLayout(mainLayout);

        setWindowTitle("CODMAT Input Terminal");
  mat=new SquareMatrix(order);

}
Button* SquareMatrixInput::createButton(const QString &text, const char *member)
 {
     Button *button = new Button(text);
     connect(button, SIGNAL(clicked()), this, member);
     return button;
 }
unsigned int SquareMatrixInput::index(unsigned int i, unsigned int j)const    // index function
{
   return (i - 1)*order + (j - 1);
} //end function

void SquareMatrixInput::make_matrix()
{

    double r,im;
    for(unsigned int i=1;i<=order;i++)
    {
        for(unsigned int j=1;j<=order;j++)
        {
            r=reals[index(i,j)].text().toDouble();
            im=imags[index(i,j)].text().toDouble();

            mat->element(i,j)=Cmplx(r,im);

        }
    }

   this->done(0);
}

