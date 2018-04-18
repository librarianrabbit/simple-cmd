#pragma once

#include "CommandInterface.h"

class Command_Sys : public CommandInterface
{
public:
	const char* command() { return "sys"; };

	const char* description() { return "Execute system commands."; };
	const char* help() { return "Execute system commands.\nUsage: sys <command>"; }

	bool hasParameters() { return true; }

	int exec(const CommandLineParser& parser);
};

