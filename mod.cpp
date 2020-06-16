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
Mod::Mod(string xml)
{
	tinyxml2::XMLDocument doc;
	const char* xml_char = xml.c_str();
	doc.LoadFile(xml_char);
	tinyxml2::XMLText* name = doc.FirstChildElement("mod")->FirstChildElement("name")->FirstChild()->ToText();
	m_name=name->Value();
	tinyxml2::XMLText* description = doc.FirstChildElement("mod")->FirstChildElement("description")->FirstChild()->ToText();
	m_description=description->Value();
	tinyxml2::XMLText* version = doc.FirstChildElement("mod")->FirstChildElement("version")->FirstChild()->ToText();
	m_version=version->Value();
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
