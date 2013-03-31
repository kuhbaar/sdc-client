#ifndef CHATUI_H
#define CHATUI_H

#include <QApplication>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QTextEdit>
#include "Chat.h"
//Class encapsulating all GUI elements
class ChatUI : public QWidget
{
Q_OBJECT

public:
  ChatUI();
  ~ChatUI();

private:
  QPushButton *connectButton, *exitButton;
  QLineEdit *serverLineEdit, *portLineEdit, *caLineEdit;
  QTextEdit *msg, *re;
  QVBoxLayout *layout;
  QFormLayout *form;

public slots:
  /*it takes the servername, port and certificate's path
  from GUI inputs and creates a Chat-class, 
  which then calls the echo method and redirects
  the return string to response window of GUI */
  void send(); 
};

#endif