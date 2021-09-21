#pragma once

#include <memory>
#include <vector>

#include <Logger.h>

namespace Log
{
    class ComposedLogger : public Logger
    {
    public:
        void AddLogger(std::unique_ptr<Logger> logger) { loggers_.push_back(std::move(logger)); };

        void SetVerbosity(Verbosity verbosity);

    private:
        
        void DoLog(const std::string& msg) override;
        void DoFlush() override;

        std::vector<std::unique_ptr<Logger>> loggers_;
    };
}