#include "Chat.h"
#include <QLabel>

Chat::Chat()
{
  connectButton = new QPushButton( "Verbinden" );
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
  connect( connectButton, SIGNAL( clicked() ), qApp, SLOT( quit() ) );
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

 
  setWindowTitle( "SDC" );
  setLayout( form );
}
 
 
Chat::~Chat()
{
  delete connectButton;
  delete serverLineEdit;
  delete portLineEdit;
  delete caLineEdit;
  delete msg;
  delete re;
  delete form;
  delete layout;
}