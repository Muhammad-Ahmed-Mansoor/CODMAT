#include "rectmatrixinput.h"

RectMatrixInput::RectMatrixInput(unsigned int r,unsigned int c,QWidget *parent) : QDialog(parent)
{

rows=r;
cols=c;
reals=new QLineEdit[r*c];
imags=new QLineEdit[r*c];

for(unsigned int i=0;i<r*c;i++)
{
    reals[i].setPlaceholderText("0");
    imags[i].setPlaceholderText("+j0");
}

Button *solve_button=createButton("Continue",SLOT(make_matrix()));

  QGridLayout *mainLayout = new QGridLayout;

  for(unsigned int i=1;i<=r;i++)
  {
      for(unsigned int j=1;j<=c;j++)
      {
          mainLayout->addWidget(&reals[index(i,j)],i-1,3*(j-1));
           mainLayout->addWidget(&imags[index(i,j)],i-1,3*(j-1)+1);
      }
  }

  mainLayout->addWidget(solve_button,r,0);
  setLayout(mainLayout);

        setWindowTitle("CODMAT Input Terminal");
  mat=new Matrix(r,c);

}
Button* RectMatrixInput::createButton(const QString &text, const char *member)
 {
     Button *button = new Button(text);
     connect(button, SIGNAL(clicked()), this, member);
     return button;
 }
unsigned int RectMatrixInput::index(unsigned int i, unsigned int j)const    // index function
{
   return (i - 1)*cols + (j - 1);
} //end function

void RectMatrixInput::make_matrix()
{

    double r,im;
    for(unsigned int i=1;i<=rows;i++)
    {
        for(unsigned int j=1;j<=cols;j++)
        {
            r=reals[index(i,j)].text().toDouble();
            im=imags[index(i,j)].text().toDouble();

            mat->element(i,j)=Cmplx(r,im);

        }
    }

   this->done(0);
}

