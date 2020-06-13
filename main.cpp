#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "func.h"
#include "modmanager.h"

using namespace std;

int main()
{
	cout << "Enter the directory you want to manage: ";
	string path("/var/www/phosphore/");
	string mod_dir("/etc/phosphore/mod/example/");
	string mod_name("example");
	map<string, int> command_map(command_map_init());
	string command("update");
	cin >> path;
	do
	{

		ModManager modManager(path);
		vector<Mod> mods(modManager.scan());
		modManager.display();
		cout << "Command (h for help/q for quit): ";
		cin >> command;
		switch (command_map[command])
		{
			case 2:
				modManager.update();
				break;

			case 3:
				cout << "Enter the main directory of the mod to add: ";
				cin >> mod_dir;
				modManager.add(mod_dir);
				break;

			case 4:
				cout << "Enter the name of the mod to delete: ";
				cin >> mod_name;
				modManager.del(mod_name);
				break;

			case 5:
				cout << "Enter the new directory to manage: ";
				cin >> path;
				break;

			case 1:
				help();
				break;

			case 0:
				cout << "exited" << endl;
				return 0;

			default:
				cout << "unknow command, type help to get a lis of available command" << endl;
				break;
		}
	} while (true);
}
