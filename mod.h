#ifndef MOD_H_INCLUDED
#define MOD_H_INCLUDED

#include <string>
#include "tinyxml2.h"

class Mod
{
	public:

	Mod(std::string name, std::string description, std::string version, std::string content="");
	Mod(std::string xml);
	std::string getName() const;
	std::string getDescription() const;
	std::string getVersion() const;
	std::string getContent() const;
	std::string display() const;

	private:

	std::string m_name;
	std::string m_description;
	std::string m_version;
	std::string m_content;
};

#endif // MOD_H_INCLUDED
