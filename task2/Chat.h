#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QApplication>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QTextEdit>

class Chat : public QWidget
{
  
public:
  Chat();
  ~Chat();

private:
  QPushButton *connectButton;
  QLineEdit *serverLineEdit, *portLineEdit, *caLineEdit;
  QTextEdit *msg, *re;
  QVBoxLayout *layout;
  QFormLayout *form;
};

#endif