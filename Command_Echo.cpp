#include "Command_Echo.h"
#include "CommandLineParser.h"
#include <iostream>

int Command_Echo::exec(const CommandLineParser& parser)
{
	std::cout << parser.parameterString() << "\n";
	return 0;
}
