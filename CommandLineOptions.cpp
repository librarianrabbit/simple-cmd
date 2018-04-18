#include "CommandLineOptions.h"
#include "CommandLineParser.h"

CommandLineOptions::CommandLineOptions()
{
}

CommandLineOptions::CommandLineOptions(const CommandLineParser& parser)
{
	getOptions(parser);
}

const std::map<std::string, std::string>& CommandLineOptions::getOptions(const CommandLineParser& parser)
{
	if (m_options.size() > 0)
	{
		m_options.clear();
	}

	auto parameters = parser.parameterList();

	if (parameters.size() == 0)
	{
		return m_options;
	}

	for (std::string& parameter : parameters)
	{
		getOption(parameter, m_options);
	}
}

void CommandLineOptions::getOption(const std::string& parameter, std::map<std::string, std::string>& options)
{
	auto it = parameter.begin();

	if (*it == '=')
	{
		options[parameter] = std::string();
		return;
	}

	for (; it != parameter.end(); ++it)
	{
		if (*it == '"')
		{
			++it;

			for (; it != parameter.end(); ++it)
			{
				if (*it == '"' && *(it - 1) != '\\') break;
			}

			if (it == parameter.end()) break;
		}
		
		if (*it == '=' && (*(it - 1) != '\\' || (it - 1) == parameter.begin()))
		{
			options[std::string(parameter.begin(), it)] = std::string((it + 1), parameter.end());
			return;
		}
	}

	options[parameter] = std::string();
}
