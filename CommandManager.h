#pragma once

#include <string>
#include <map>
#include <memory>
#include <vector>

class CommandInterface;

class CommandManager
{
public:
	CommandManager();
	~CommandManager();

	bool registerCommand(CommandInterface* command);

	CommandInterface* command(const std::string& command);

	std::vector<std::string> commandList();

	void setExitCommandPointer(bool* ptr);

private:
	void registerBuiltinCommands();

	std::map<std::string, CommandInterface*> m_commands;
};
