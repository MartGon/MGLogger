#include <ConsoleLogger.h>

#include <iostream>

using namespace Log;

void ConsoleLogger::DoLog(const std::string& msg)
{
    std::cout << msg << '\n';
}

