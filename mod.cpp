#include <string>
#include <vector>
#include "mod.h"

using namespace std;
namespace fs = std::filesystem;

Mod::Mod(string name, string description, string version, vector<string> files)
{
	m_name=name;
	m_description=description;
	m_version=version;
	m_files=files;
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
	tinyxml2::XMLElement* content = doc.FirstChildElement("mod")->FirstChildElement("content");
	m_files=this->retrieveFiles(content, "", true);
}
vector<string> Mod::retrieveFiles(tinyxml2::XMLElement* content, string name, bool ignore) const
{
	vector<string> files, files_insert;
	string name_insert;
	tinyxml2::XMLElement* folder(content->FirstChildElement());
	while(folder!=NULL)
	{
		if (ignore)
		{
			name_insert=name;
		}
		else
		{
			name_insert=name+content->Value()+"/";
		}
		files_insert=this->retrieveFiles(folder, name_insert);
		files.insert(end(files),begin(files_insert),end(files_insert));
		folder = folder->NextSiblingElement();
	}
	if (ignore)
	{
		return files;
	}
	files.push_back(name+content->Value());
	return files;
}
void Mod::check(string path)
{
	string pathmodxml(path+"/mod/"+m_name+"/mod.xml");
	tinyxml2::XMLDocument doc;
	ofstream modfile;
	doc.LoadFile(pathmodxml.c_str());
	tinyxml2::XMLElement* content=doc.FirstChildElement("mod")->FirstChildElement("content");
	this->checkContent(path, content);
	modfile=fopen(path, "a+");
	tinyxml2::XMLPrinter printer(modfile);
	doc.Print(&printer);
}
void Mod::checkContent(string path, tinyxml2::XMLElement* element)
{
	for(const auto& isEntry:fs::recursive_directory_iterator(path))
	{
		tinyxml2::XMLElement* node;
		if(isEntry.is_directory())
		{
			this->checkContent(isEntry.path(), &node);
		}
		node->SetValue(isEntry.path().filename());
		element->InsertEndChild(node);
	}
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
vector<string> Mod::getFiles() const
{
	return m_files;
}
string Mod::display() const
{
	return m_name + " v" + m_version;
}
