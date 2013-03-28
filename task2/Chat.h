#ifndef CHAT_H
#define CHAT_H

#include <Ice/Ice.h>
#include <IceSSL/IceSSL.h>
#include "SecureDistributedChat.h"

using namespace std;

class Chat{
public:
  Chat(string server, string port, string ca_path){
    Ice::PropertiesPtr props = Ice::createProperties();
    props->setProperty("Ice.Plugin.IceSSL", "IceSSL:createIceSSL");
    props->setProperty("IceSSL.CertAuthFile", ca_path);
    try{
      Ice::InitializationData id;
      id.properties = props;
      ic = Ice::initialize(id);
      Ice::ObjectPrx base = ic->stringToProxy("Authentication:ssl -h " + server +" -p " + port);
      auth = sdc::AuthenticationIPrx::checkedCast(base);
    } catch (const Ice::Exception& e){
      if(ic) ic->destroy();
      throw;
    }
  }

  string echo(string s){
    return auth->echo(s);
  }

  ~Chat(){
    if(ic) ic->destroy();
  }
private:
  Ice::CommunicatorPtr ic;
  sdc::AuthenticationIPrx auth;
};
#endif