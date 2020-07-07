#include <QtWidgets>

  #include "button.h"

  Button::Button(const QString &text, QWidget *parent)
      : QPushButton(parent)
  {
      setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
      setText(text);
  }

  QSize Button::sizeHint() const
  {
      QSize size = QPushButton::sizeHint();
      size.rheight() += 20;
      size.rwidth() = qMax(size.width(), size.height());
      return size;
  }
