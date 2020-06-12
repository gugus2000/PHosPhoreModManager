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
	void add(Mod const& mod);
	void del(Mod const& mod);

	private:

	std::string m_directory;
	std::vector<Mod> m_mods;
};

#endif // MODMANAGER_H_INCLUDED
