#include "ChatUI.h"
#include "Chat.h"
#include "sendButton.h"
#include <QLabel>

using namespace std;

ChatUI::ChatUI()
{
  connectButton = new QPushButton("Send");
  exitButton = new QPushButton("Quit");
  serverLineEdit = new QLineEdit();
  portLineEdit = new QLineEdit();
  caLineEdit = new QLineEdit();
  msg = new QTextEdit();
  re = new QTextEdit();
  layout = new QVBoxLayout();
  form = new QFormLayout();
 
  // Anstatt eine Verbindung herzustellen beendet unser Button das Programm
  // 'qApp' ist ein globaler Zeiger auf unsere QApplication-Instanz, die in
  // 'QApplication' deklariert ist.
  connect(connectButton, SIGNAL(clicked()), this, SLOT(send())); 
  connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

  re->setReadOnly(true);

  form->addRow("Server Name", serverLineEdit);
  form->addRow("PortNo", portLineEdit);
  form->addRow("Path to certificate", caLineEdit);
  form->addRow(layout);
  layout->addWidget(new QLabel("Your message"));
  layout->addWidget(msg);
  layout->addWidget(new QLabel("Response"));
  layout->addWidget(re);
  layout->addWidget(connectButton);
  layout->addWidget(exitButton);

 
  setWindowTitle( "SDC" );
  setLayout( form );
}
 
 
ChatUI::~ChatUI()
{
  delete connectButton;
  delete exitButton;
  delete serverLineEdit;
  delete portLineEdit;
  delete caLineEdit;
  delete msg;
  delete re;
  delete form;
  delete layout;
}

void ChatUI::send(){
  string s = this->serverLineEdit->text().toStdString();
  string p = this->portLineEdit->text().toStdString();
  string c = this->caLineEdit->text().toStdString();
  Chat ch = Chat(s, p, c);
  string resp = ch.echo(this->msg->toPlainText().toStdString());
  QString temp = QString::fromStdString(resp);
  this->re->setText(temp);
}