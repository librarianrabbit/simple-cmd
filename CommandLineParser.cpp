#include "CommandLineParser.h"
#include <iostream>

CommandLineParser::CommandLineParser() : m_commandSize(0)
{
}

CommandLineParser::CommandLineParser(const std::string& cmd) : m_commandSize(0)
{
	m_commandString = cmd;

	parseCommand();
}

void CommandLineParser::setCommandString(const std::string& cmd)
{
	m_commandSize = 0;

	m_commandString = cmd;

	parseCommand();
}

const std::string& CommandLineParser::getCommandString()
{
	m_commandSize = 0;

	std::string temp;

	if (m_commandString.length() > 0)
	{
		m_commandString.clear();
	}

	do
	{
		std::cin >> temp;

		m_commandString.append(temp);

		char ch = std::cin.peek();

		if (ch == ' ')
		{
			do
			{
				std::cin.ignore(1);
			}
			while ((ch = std::cin.peek()) == ' ');
		}

		if (ch == '\r' || ch == '\n') break;

		m_commandString.append(" ");
	}
	while (true);

	parseCommand();

	return m_commandString;
}

std::string CommandLineParser::commandToLower() const
{
	std::string command = m_commandString.substr(0, m_commandSize);
	
	for (auto& ch : command)
	{
		if (isupper(ch))
		{
			ch = tolower(ch);
		}
	}

	return command;
}

void CommandLineParser::setParameterString(const std::string& str)
{
	if (m_parameterList.size() > 0)
	{
		m_parameterList.clear();
	}

	m_commandString.replace(m_commandString.begin() + m_commandSize, m_commandString.end(), " " + str);
}

const std::vector<std::string>& CommandLineParser::getParameterList()
{
	if (m_parameterList.size() > 0)
	{
		m_parameterList.clear();
	}

	auto it = m_commandString.begin() + m_commandSize;

	for (; it != m_commandString.end(); ++it)
	{
		if (*it == ' ') continue; // skip spaces before next param

		auto start = it;

		for (; it != m_commandString.end(); ++it)
		{
			if (*it == '"') // handle quoted parameters, "param with space and \" quote with backslash"
			{
				++it;

				for (; it != m_commandString.end(); ++it)
				{
					if (*it == '"' && *(it - 1) != '\\')
					{
						break;
					}
				}
			}

			if (it == m_commandString.end() || *it == ' ') break;
		}

		if (it > start)
		{
			m_parameterList.push_back(std::string(start, it));
		}

		if (it == m_commandString.end()) break;
	}

	return m_parameterList;
}

void CommandLineParser::parseCommand()
{
	size_t pos = m_commandString.find_first_of(' ');

	if (pos == std::string::npos)
	{
		m_commandSize = m_commandString.length();

		return;
	}

	m_commandSize = pos;

	if (m_parameterList.size() > 0)
	{
		m_parameterList.clear();
	}
}
