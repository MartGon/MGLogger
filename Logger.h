#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

namespace Log
{
    enum class Verbosity
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        CRITICAL
    };

    class Logger
    {
    public:

        virtual ~Logger() {};

        Verbosity GetVerbosity() const { return verbosity_;}
        void SetVerbosity(Verbosity verbosity) { this->verbosity_ = verbosity; };
        
        void Log(const std::string& msg);
        void Log(const std::string& msg, Verbosity level);
        void Flush();

        void LogDebug(const std::string& msg) { Log(msg, Verbosity::DEBUG); }
        void LogInfo(const std::string& msg) { Log(msg, Verbosity::INFO); };
        void LogWarning(const std::string& msg) { Log(msg, Verbosity::WARNING); };
        void LogError(const std::string& msg) { Log(msg, Verbosity::ERROR); };
        void LogCritical(const std::string& msg) { Log(msg, Verbosity::CRITICAL); };

    private:

        std::string FormatMsg(const std::string& msg, Verbosity level);
        std::string ReplaceToken(const std::string& token, const std::string& msg, const std::string& data);

        std::string GetFormattedDate();

        virtual void DoLog(const std::string& msg) = 0;
        virtual void DoFlush() {};

        std::string formatStr_ = "[%d]%t: %m";
        Verbosity verbosity_ = Verbosity::ERROR;
        static const std::unordered_map<Verbosity, std::string> typeString;
    };
}