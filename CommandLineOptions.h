#pragma once

#include <string>
#include <map>

class CommandLineParser;

class CommandLineOptions
{
public:
	CommandLineOptions();
	CommandLineOptions(const CommandLineParser& parser);

	const std::map<std::string, std::string>& getOptions(const CommandLineParser& parser);
	const std::map<std::string, std::string>& options() const { return m_options; }

private:
	void getOption(const std::string& parameter, std::map<std::string, std::string>& options);

	std::map<std::string, std::string> m_options;
};
