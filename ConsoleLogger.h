#pragma once

#include <Logger.h>

namespace Log
{
    class ConsoleLogger : public Logger
    {
    private:
        void DoLog(const std::string& msg) override;
    };
}
