#ifndef MOD_H_INCLUDED
#define MOD_H_INCLUDED

#include <string>
#include "tinyxml2.h"
#include <vector>

class Mod
{
	public:

	Mod(std::string name, std::string description, std::string version, std::vector<std::string> files);
	Mod(std::string xml);
	std::vector<std::string> retrieveFiles(tinyxml2::XMLElement* content, std::string name="", bool ignore=false) const;
	void check(std::string path);
	void checkContent(std::string, tinyxml2::XMLElement* element);
	std::string getName() const;
	std::string getDescription() const;
	std::string getVersion() const;
	std::vector<std::string> getFiles() const;
	std::string display() const;

	private:

	std::string m_name;
	std::string m_description;
	std::string m_version;
	std::vector<std::string> m_files;
};

#endif // MOD_H_INCLUDED
