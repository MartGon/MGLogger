#include <ComposedLogger.h>

using namespace Log;

void ComposedLogger::DoLog(const std::string& msg)
{
    for (auto& logger : loggers_)
        logger->Log(msg);
}

void ComposedLogger::SetVerbosity(Verbosity verbosity)
{
    for (auto& logger : loggers_)
        logger->SetVerbosity(verbosity);
    Logger::SetVerbosity(verbosity);
}

void ComposedLogger::DoFlush()
{
    for (auto& logger : loggers_)
        logger->Flush();
}