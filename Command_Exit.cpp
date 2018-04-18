#include "Command_Exit.h"
#include "CommandLineParser.h"

Command_Exit::Command_Exit() : m_running(0)
{
}

int Command_Exit::exec(const CommandLineParser& parser)
{
	if (m_running)
	{
		*m_running = false;
		return 0;
	}

	return 1;
}
