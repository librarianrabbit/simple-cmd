#pragma once

#include "commandinterface.h"

class CommandManager;
class CommandLineParser;

class Command_Exit : public CommandInterface
{
public:
	Command_Exit();

	const char* command() { return "exit"; };

	const char* description() { return "Exit from the command prompt."; };
	const char* help() { return "Exit from the command promt.\nUsage: exit"; }

	bool hasParameters() { return false; }

	int exec(const CommandLineParser& parser);

private:
	bool* m_running;

	friend class CommandManager;
};
