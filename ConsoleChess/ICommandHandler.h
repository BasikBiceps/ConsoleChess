#pragma once
#include <string>

class ICommandHandler
{
public:
	virtual void handle(const std::string& command) = 0;
};