#include "equationinput.h"

EquationInput::EquationInput(unsigned int n,QWidget *parent) : QDialog(parent)
{

order=n;
reals=new QLineEdit[order*(order+1)];
imags=new QLineEdit[order*(order+1)];

for(unsigned int i=1;i<=order;i++)
{
    for(unsigned int j=1;j<=order+1;j++)
    {
        if(j==order+1)
        {
            reals[index(i,j)].setPlaceholderText("=(0");
            imags[index(i,j)].setPlaceholderText("+j0)");
        }
        else
        {
            reals[index(i,j)].setPlaceholderText("(0");
            imags[index(i,j)].setPlaceholderText("+j0)x"+QString::number(j));
        }
    }
}

Button *solve_button=createButton("Solve!",SLOT(make_matrix()));

  QGridLayout *mainLayout = new QGridLayout;

  for(unsigned int i=1;i<=order;i++)
  {
      for(unsigned int j=1;j<=order+1;j++)
      {
          mainLayout->addWidget(&reals[index(i,j)],i-1,2*(j-1));
           mainLayout->addWidget(&imags[index(i,j)],i-1,2*(j-1)+1);
      }
  }

  mainLayout->addWidget(solve_button,order,0);
  setLayout(mainLayout);

        setWindowTitle("CODMAT Input Terminal");
  mat=new SquareMatrix(order);
  vec=new ColumnVector(order);

}
Button* EquationInput::createButton(const QString &text, const char *member)
 {
     Button *button = new Button(text);
     connect(button, SIGNAL(clicked()), this, member);
     return button;
 }
unsigned int EquationInput::index(unsigned int i, unsigned int j)const    // index function
{
   return (i - 1)*(order+1) + (j - 1);
} //end function

void EquationInput::make_matrix()
{

    double r,im;
    for(unsigned int i=1;i<=order;i++)
    {
        for(unsigned int j=1;j<=order+1;j++)
        {
            r=reals[index(i,j)].text().toDouble();
            im=imags[index(i,j)].text().toDouble();
            if(j==order+1)
            {
                vec->element(i)=Cmplx(r,im);
            }
            else
            {
                mat->element(i,j)=Cmplx(r,im);
            }


        }
    }

   this->done(0);
}

