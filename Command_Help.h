#pragma once

#include "CommandInterface.h"

class CommandLineParser;

class Command_Help : public CommandInterface
{
public:
	const char* command() { return "help"; };

	const char* description() { return "Show a list of commands or help about a command."; };
	const char* help() { return "Show a list of commands.\nUsage: help\n\nShow help information about a command.\nUsage: help <command>"; }

	bool hasParameters() { return true; }

	int exec(const CommandLineParser& parser);
};
