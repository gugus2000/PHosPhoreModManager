#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include "modmanager.h"

using namespace std;
namespace fs = std::filesystem;

ModManager::ModManager(string directory)
{
	m_directory = directory;
	fs::directory_entry directory_entry(m_directory);
	if (!directory_entry.is_directory())
	{
		throw "It is not a directory";
	}
}
vector<Mod> ModManager::scan()
{
	fs::path mod_directory(m_directory/"mod");
	for (const auto & entry : fs::recursive_directory_iterator(mod_directory))
	{
		if (entry.path().filename()=="mod.xml")
		{
			Mod mod(entry.path());
			m_mods.push_back(mod);
		}
	}
	return m_mods;
}
void ModManager::update()
{
}
void ModManager::add(string path)
{
	fs::copy(path, m_directory, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
}
void ModManager::del(string name)
{
	for (Mod mod : m_mods)
	{
		if (mod.getName()==name)
		{
			cout << mod.display() << endl;
			return;
		}
	}
	cout << " This mod doesn't exist! " << endl;
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
