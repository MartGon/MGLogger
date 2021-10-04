#pragma once

#include <Logger.h>

namespace Log
{
    class NullLogger : public Logger
    {
    private:
        void DoLog(const std::string& msg) override;
        void DoFlush() override;
    };
}