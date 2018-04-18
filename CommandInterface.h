#pragma once

class CommandLineParser;
class CommandManager;

class CommandInterface
{
public:
	CommandInterface() { }
	CommandInterface(CommandManager* manager) : m_manager(manager) { }

	virtual const char* command() = 0;

	virtual const char* description() { return 0; };
	virtual const char* help() { return 0; }

	virtual bool hasParameters() { return false; }

	virtual int exec(const CommandLineParser& parser) = 0;

protected:
	CommandManager* m_manager;

	friend class CommandManager;
};
