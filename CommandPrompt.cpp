#include "CommandPrompt.h"
#include "CommandLineParser.h"
#include "CommandManager.h"
#include "CommandInterface.h"
#include <iostream>
#include "CustomCommands.h"

CommandPrompt::CommandPrompt() : m_running(false)
{
}

int CommandPrompt::run()
{
	m_running = true;

	CommandLineParser parser;
	CommandManager manager;

	manager.setExitCommandPointer(&m_running);

	MiscCommands::registerMiscCommands(manager);

	do
	{
		std::cout << "> ";

		parser.getCommandString();

		CommandInterface* command = manager.command(parser.commandToLower());

		if (command)
		{
			if (command->hasParameters())
			{
				parser.getParameterList();
			}

			command->exec(parser);
		}

		std::cout << "\n";
	}
	while (m_running);

	return 0;
}
