#pragma once

#include <string>

class CommandPrompt
{
public:
	CommandPrompt();

	int run();

private:
	bool m_running;
};
