#include "Command_Help.h"
#include "CommandLineParser.h"
#include "CommandManager.h"
#include <iostream>

int Command_Help::exec(const CommandLineParser& parser)
{
	auto& parameters = parser.parameterList();

	if (parameters.size() > 0)
	{
		CommandInterface* command = m_manager->command(parameters.at(0));

		if (command && command->help())
		{
			std::cout << command->help() << "\n";
		}
		else
		{
			std::cout << "Invalid command.\n";
		}
	}
	else
	{
		for (auto& commandName : m_manager->commandList())
		{
			CommandInterface* command = m_manager->command(commandName);

			if (command)
			{
				std::cout << command->command();

				if (command->description())
				{
					std::cout << " - " << command->description();
				}

				std::cout << "\n";
			}
		}
	}

	return 0;
}
