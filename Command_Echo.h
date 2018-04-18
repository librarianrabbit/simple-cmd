#pragma once

#include "CommandInterface.h"

class Command_Echo : public CommandInterface
{
public:
	const char* command() { return "echo"; };

	const char* description() { return "Show text on console screen."; };
	const char* help() { return "Show text on console screen.\nUsage: echo <message>"; }

	bool hasParameters() { return true; }

	int exec(const CommandLineParser& parser);
};

