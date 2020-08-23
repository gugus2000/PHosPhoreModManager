#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "func.h"
#include "modmanager.h"

using namespace std;

int main(int argc, char* argv[])
{
	string path("/var/www/phosphore/");
	string mod_dir("/etc/phosphore/mod/example/");
	string mod_name("example");
	map<string, int> command_map(command_map_init());
	string command("update");
	if (argc<2)
	{
		cout << "Enter the directory you want to manage: ";
		cin >> path;
	}
	else
	{
		path=argv[1];
	}
	do
	{
		try
		{
			ModManager modManager(path);
			vector<Mod> mods(modManager.scan());
			modManager.display();
			if (argc<3)
			{
				cout << "Command (h for help/q for quit): ";
				cin >> command;
			}
			else
			{
				command=argv[2];
			}
			switch (command_map[command])
			{
				case 2:
					modManager.update();
					cout << "Mods updated" << endl;
					break;

				case 3:
					if (argc<4)
					{
						cout << "Enter the main directory of the mod to add: ";
						cin >> mod_dir;
					}
					else
					{
						mod_dir=argv[3];
					}
					modManager.add(mod_dir);
					cout << mod_dir << " mod added to the directory" << endl;
					break;

				case 4:
					if (argc<4)
					{
						cout << "Enter the name of the mod to delete: ";
						cin >> mod_name;
					}
					else
					{
						mod_name=argv[3];
					}
					modManager.del(mod_name);
					cout << mod_name << " removed from the directory" << endl;
					break;

				case 5:
					cout << "Enter the new directory to manage: ";
					cin >> path;
					cout << "Path changed" << endl;
					break;

				case 1:
					help();
					break;

				case 0:
					cout << "exited" << endl;
					return 0;

				default:
					cout << "unknow command, type help to get a list of available command" << endl;
					break;
			}
			if (argc>2)
			{
				return 0;
			}
		} catch (const string msg)
		{
			cerr << msg << endl;
			cout << "Enter the directory you want to manage: ";
			cin >> path;

		}
	} while (true);
}
