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
		string message(directory + " is not a directory");
		throw message;
	}
}
vector<Mod> ModManager::scan()
{
	fs::path mod_directory(m_directory/"mod");
	if (!fs::exists(mod_directory))
	{
		fs::create_directory(mod_directory);
	}
	for (const auto & entry : fs::recursive_directory_iterator(mod_directory))
	{
		if (entry.path().filename()=="mod.xml")
		{
			Mod mod(entry.path().string());
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
	fs::path pathmod(path);
	Mod mod(path+"mod/"+pathmod.parent_path().filename().c_string()+"/mod.xml");
	mod.check(path);
	fs::copy(path, m_directory, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
}
void ModManager::del(string name)
{
	for (Mod mod : m_mods)
	{
		if (mod.getName()==name)
		{
			fs::path all;
			for (fs::path file : mod.getFiles())
			{
				all=m_directory/file;
				if (!fs::exists(all))
				{
					cout << "This file or folder does not exist" << endl;
				}
				else
				{
					fs::directory_entry File(all);
					if (File.is_regular_file())
					{
						cout << all << " removed" << endl;
						fs::remove(all);
					}
					else if (File.is_directory())
					{
						if (fs::is_empty(all))
						{
							cout << all << " removed because it was empty" << endl;
							fs::remove(all);
						}
					}
				}
			}
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
