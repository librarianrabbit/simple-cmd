#include "Command_Sys.h"
#include "CommandLineParser.h"
#include <cstdlib>

int Command_Sys::exec(const CommandLineParser& parser)
{
	std::string command = parser.parameterString();
	
	if (command.length() == 0) return 0;

	return system(command.c_str());
}
