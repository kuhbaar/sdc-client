#include "Chat.h"

Chat::Chat()
{
  connectButton = new QPushButton( "Verbinden" );
  addressLineEdit = new QLineEdit();
  usernameLineEdit = new QLineEdit();
  pwLineEdit = new QLineEdit();
  authBox = new QGroupBox( "Authentifizierung erforderlich" );
  layout = new QVBoxLayout();
  authLayout = new QVBoxLayout();
 
  // Anstatt eine Verbindung herzustellen beendet unser Button das Programm
  // 'qApp' ist ein globaler Zeiger auf unsere QApplication-Instanz, die in
  // 'QApplication' deklariert ist.
  connect( connectButton, SIGNAL( clicked() ), qApp, SLOT( quit() ) );
 
  // Passwort beim Tippen nicht anzeigen
  pwLineEdit->setEchoMode( QLineEdit::Password );
  // Widget-Gruppe kann aktiviert werden
  authBox->setCheckable( true );
  authBox->setChecked( false );
 
  // Widgets in den Layouts platzieren
  authLayout->addWidget( usernameLineEdit );
  authLayout->addWidget( pwLineEdit );
  authBox->setLayout( authLayout );
  layout->addWidget( addressLineEdit );
  layout->addWidget( authBox );
  layout->addWidget( connectButton );
 
  setWindowTitle( "Verbinden" );
  setLayout( layout );
}
 
 
Chat::~Chat()
{
  delete connectButton;
  delete addressLineEdit;
  delete usernameLineEdit;
  delete pwLineEdit;
  delete authLayout;
  delete authBox;
  delete layout;
}