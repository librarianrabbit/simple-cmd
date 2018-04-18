#include "CustomCommands.h"
#include "CommandManager.h"
#include "Command_Echo.h"
#include "Command_Sys.h"

namespace MiscCommands
{
	void registerMiscCommands(CommandManager& manager)
	{
		auto reg = [&manager](CommandInterface* command)
		{
			if (command && !manager.registerCommand(command))
			{
				delete command;
			}
		};

		reg(new Command_Echo);
		reg(new Command_Sys);
	}
}
