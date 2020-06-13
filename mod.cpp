#include <string>
#include "mod.h"

using namespace std;

Mod::Mod(string name, string description, string version, string content)
{
	m_name=name;
	m_description=description;
	m_version=version;
	m_content=content;
}
string Mod::getName() const
{
	return m_name;
}
string Mod::getDescription() const
{
	return m_description;
}
string Mod::getVersion() const
{
	return m_version;
}
string Mod::getContent() const
{
	return m_content;
}
string Mod::display() const
{
	return m_name + " v" + m_version;
}
