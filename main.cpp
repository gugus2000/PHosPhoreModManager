#include <iostream>
#include <vector>
#include <string>
#include "modmanager.h"

using namespace std;

int main()
{
	ModManager modManager("path");
	vector<Mod> mods(modManager.scan());
	int const nb_mods(mods.size());
	for (int i(0);i<nb_mods;i++)
	{
		cout << mods[i].getName() << endl;
	}
}
