#include <iostream>
#include <string>
#include <map>
#include "func.h"

using namespace std;

map<string, int> command_map_init()
{
	map<string, int> command_map;
	command_map["q"]=0;
	command_map["quit"]=0;
	command_map["exit"]=0;
	command_map["sayonara"]=0;
	command_map["h"]=1;
	command_map["help"]=1;
	command_map["u"]=2;
	command_map["update"]=2;
	command_map["a"]=3;
	command_map["add"]=3;
	command_map["d"]=4;
	command_map["delete"]=4;
	command_map["c"]=5;
	command_map["change"]=5;
	return command_map;
}
void help()
{
	cout << "Command list:" << endl;
	cout << "h/help: display this help" << endl;
	cout << "u/update: update installed mod" << endl;
	cout << "a/add: install a new mod" << endl;
	cout << "d/delete: uninstall a mod" << endl;
	cout << "c/change: change the directory to manage" << endl;
	cout << "q/quit/exit/sayonara: quit this programm" << endl;
}
