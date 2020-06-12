#ifndef MOD_H_INCLUDED
#define MOD_H_INCLUDED

#include <string>

class Mod
{
	public:

	Mod(std::string xml);
	std::string getName();

	private:

	std::string m_name;
};

#endif // MOD_H_INCLUDED
