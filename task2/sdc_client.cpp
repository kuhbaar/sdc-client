#include <iostream>
#include <boost/program_options.hpp>
#include "SecureDistributedChat.h"
#include <Ice/Ice.h>

#include "Chat.h"
#include <QApplication>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]){
  po::options_description desc("Allowed options");
  desc.add_options()
      ("help", "produce help message")
      ("server_name,s", po::value<string>(), "set server name")
      ("port,p", po::value<string>(), "set portNo")
      ("ca_path,c", po::value<string>(), "set path to the certificate")
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);    

  if (vm.count("help")) {
      cout << desc << "\n";
      return 1;
  }
  
  if (!vm.count("server_name") && !vm.count("port") && !vm.count("ca_path")){
    QApplication a(argc, argv);
    Chat c;
    c.show();

    return a.exec();
  }

  string server = vm["server_name"].as<string>();
  string port = vm["port"].as<string>();
  string ca_path = vm["ca_path"].as<string>();

  Ice::PropertiesPtr props = Ice::createProperties(argc, argv);
  props->setProperty("Ice.Plugin.IceSSL", "IceSSL:createIceSSL");
  props->setProperty("IceSSL.CertAuthFile", ca_path);

  Ice::CommunicatorPtr ic;
  try{
    Ice::InitializationData id;
    id.properties = props;
    Ice::CommunicatorPtr ic = Ice::initialize(id);

    Ice::ObjectPrx base = ic->stringToProxy("Authentication:ssl -h " + server +" -p " + port);
    sdc::AuthenticationIPrx auth = sdc::AuthenticationIPrx::checkedCast(base);
    cout << auth->echo("Hallo chat") << endl;
  } catch (const Ice::Exception& e){
    std::cerr << e << std::endl;
  }
  if(ic) ic->destroy();
  return 1;
}