#pragma once

#include <string>
#include <vector>

class CommandLineParser
{
public:
	CommandLineParser();
	CommandLineParser(const std::string& cmd);

	const std::string& commandString() const { return m_commandString; }
	void setCommandString(const std::string& cmd);
	const std::string& getCommandString();
	
	std::string command() const { return m_commandString.substr(0, m_commandSize); }
	std::string commandToLower() const;
	std::string CommandLineParser::parameterString() const { return m_commandString.substr(m_commandSize + (m_commandString.length() != m_commandSize ? 1 : 0)); };
	void setParameterString(const std::string& str);

	inline const std::vector<std::string>& parameterList() const { return m_parameterList; }
	const std::vector<std::string>& getParameterList();

private:
	void parseCommand();

	std::string m_commandString;
	std::vector<std::string> m_parameterList;
	
	size_t m_commandSize;
};
