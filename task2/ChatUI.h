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

class ChatUI : public QWidget
{

public:
  ChatUI();
  ~ChatUI();

private:
  QPushButton *connectButton, *exitButton;
  QLineEdit *serverLineEdit, *portLineEdit, *caLineEdit;
  QTextEdit *msg, *re;
  QVBoxLayout *layout;
  QFormLayout *form;

private slots:
  void send();
};

#endif