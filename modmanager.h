#ifndef MODMANAGER_H_INCLUDED
#define MODMANAGER_H_INCLUDED

#include <string>
#include <vector>
#include "mod.h"

class ModManager
{
	public:

	ModManager(std::string directory);
	std::vector<Mod> scan();
	void update();
	void add(std::string path);
	void del(std::string name);
	void display() const;

	private:

	std::string m_directory;
	std::vector<Mod> m_mods;
};

#endif // MODMANAGER_H_INCLUDED
