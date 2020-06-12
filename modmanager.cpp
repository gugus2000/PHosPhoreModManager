#include <string>
#include <vector>
#include "modmanager.h"


ModManager::ModManager(std::string directory)
{
	m_directory=directory;
}
vector ModManager::scan()
{
	m_mods.push_back(Mod mod("a"));
	m_mods.push_back(Mod mod("b"));
	return m_mods;
}
void ModManager::update()
{
}
void ModManager::add(Mod const& mod)
{
}
void ModManager::del(Mod const& mod)
{
}
