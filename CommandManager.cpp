#include "CommandManager.h"

// Built-in commands
#include "Command_Exit.h"
#include "Command_Help.h"

CommandManager::CommandManager()
{
	registerBuiltinCommands();
}

CommandManager::~CommandManager()
{
	for (auto& it : m_commands)
	{
		if (it.second)
		{
			delete it.second;
			it.second = 0;
		}
	}

	m_commands.clear();
}

bool CommandManager::registerCommand(CommandInterface* command)
{
	if (!command->command()) return false;

	std::string cmd;

	const char* c = command->command();

	for (const char* it = command->command(); *it != '\0'; ++it)
	{
		cmd.append(1, tolower(*it));
	}

	if (m_commands.find(cmd) != m_commands.end()) return false;

	command->m_manager = this;

	m_commands[cmd] = command;

	return true;
}

CommandInterface* CommandManager::command(const std::string& command)
{
	auto cmd = m_commands.find(command);

	if (cmd != m_commands.end())
	{
		return cmd->second;
	}

	return 0;
}

std::vector<std::string> CommandManager::commandList()
{
	std::vector<std::string> list;

	for (auto& command : m_commands)
	{
		list.push_back(command.first);
	}

	return list;
}

void CommandManager::registerBuiltinCommands()
{
	auto reg = [this](CommandInterface* command)
	{
		if (command && !registerCommand(command))
		{
			delete command;
		}
	};

	reg(new Command_Help);
	reg(new Command_Exit);
}

void CommandManager::setExitCommandPointer(bool* ptr)
{
	auto cmd = m_commands.find("exit");

	if (cmd != m_commands.end())
	{
		Command_Exit* exit = reinterpret_cast<Command_Exit*>(cmd->second);

		if (exit)
		{
			exit->m_running = ptr;
		}
	}
}
