#include <iostream>
#include <boost/program_options.hpp>
#include "Chat.h"

#include "ChatUI.h"
#include <QApplication>

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
  
  //when ./sdc_client without parameters - start GUI
  if (!vm.count("server_name") && !vm.count("port") && !vm.count("ca_path")){
    QApplication a(argc, argv);    
    ChatUI c;

    c.show();

    return a.exec();
  }

  string server = vm["server_name"].as<string>();
  string port = vm["port"].as<string>();
  string ca_path = vm["ca_path"].as<string>();

  //Creates new Chat Object with given Data and calls the echo-Method
  try{
    Chat sdc = Chat(server, port, ca_path);
    cout << sdc.echo("Hello Chat") << endl;
  } catch (const Ice::Exception& e){
    std::cerr << e << std::endl;
  }
  return 1;
}