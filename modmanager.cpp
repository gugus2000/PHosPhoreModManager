#include <string>
#include <vector>
#include <iostream>
#include "modmanager.h"

using namespace std;

ModManager::ModManager(string directory)
{
	m_directory=directory;
}
vector<Mod> ModManager::scan()
{
	Mod moda("a", "a mod a", "1.0");
	Mod modb("b", "a mod b", "1.2");
	m_mods.push_back(moda);
	m_mods.push_back(modb);
	return m_mods;
}
void ModManager::update()
{
}
void ModManager::add(string path)
{
}
void ModManager::del(string name)
{
}
void ModManager::display() const
{
	cout << "====== MODMANAGER ======" << endl;
	cout << "path: " << m_directory << endl;
	cout << "mods: " << endl;
	int const nb_mods(m_mods.size());
	for (int i(0);i<nb_mods;i++)
	{
		cout << m_mods[i].display() << endl;
	}
	cout << nb_mods << " mods installed" << endl;
	cout << "====== MODMANAGER ======" << endl;
}
