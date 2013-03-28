#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QApplication>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class Chat : public QWidget
{
  
public:
  Chat();
  ~Chat();

private:
  QPushButton *connectButton;
  QLineEdit *addressLineEdit, *usernameLineEdit, *pwLineEdit;
  QGroupBox *authBox;
  QVBoxLayout *layout, *authLayout;
};

#endif