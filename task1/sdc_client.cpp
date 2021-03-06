#include <iostream>
#include <boost/program_options.hpp>
#include "SecureDistributedChat.h"
#include <Ice/Ice.h>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]){
  //This Description will be displayed if the user types --help
  po::options_description desc("Allowed options");
  desc.add_options()
      ("help", "produce help message")
      ("server_name,s", po::value<string>(), "set server name")
      ("port,p", po::value<string>(), "set portNo")
      ("ca_path,c", po::value<string>(), "set path to the certificate");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);    
  
  //param = --help - view Description
  if (vm.count("help")) {
      cout << desc << "\n";
      return 1;
  }

  //Displays the server name if set or exits the program with error message
  if (vm.count("server_name")) {
      cout << "Server name was set to " 
   << vm["server_name"].as<string>() << ".\n";
  } else {
      cout << "Server name was not set.\n";
      exit(1);
  }

  //Displays the server name if set or exits the program with error message
  if (vm.count("port")) {
    cout << "PortNo was set to "
  << vm["port"].as<string>() << ".\n";
  } else {
      cout << "PortNo was not set.\n";
      exit(1);
  }

  //Displays the server name if set or exits the program with error message 
  if (vm.count("ca_path")) {
      cout << "CA path was set to " 
   << vm["ca_path"].as<string>() << ".\n";
  } else {
      cout << "CA path was not set.\n";
      exit(1);
  }

  string server = vm["server_name"].as<string>();
  string port = vm["port"].as<string>();
  string ca_path = vm["ca_path"].as<string>();

  //Setting the right properties for COmmunicator
  Ice::PropertiesPtr props = Ice::createProperties(argc, argv);
  props->setProperty("Ice.Plugin.IceSSL", "IceSSL:createIceSSL");
  props->setProperty("IceSSL.CertAuthFile", ca_path);

  Ice::CommunicatorPtr ic;
  try{
    //initializing the Communicator with the Properties
    Ice::InitializationData id;
    id.properties = props;
    Ice::CommunicatorPtr ic = Ice::initialize(id);

    //getting the right Proxy and calling echo-method
    Ice::ObjectPrx base = ic->stringToProxy("Authentication:ssl -h " + server +" -p " + port);
    sdc::AuthenticationIPrx auth = sdc::AuthenticationIPrx::checkedCast(base);
    cout << auth->echo("Hallo chat") << endl;
  } catch (const Ice::Exception& e){
    std::cerr << e << std::endl;
  }
  //destroy the communicator at the end
  if(ic) ic->destroy();
  return 1;
}