#include <string>
#include "mod.h"

using namespace std;

Mod::Mod(string xml)
{
	m_name=xml;
}
string Mod::getName()
{
	return m_name;
}
