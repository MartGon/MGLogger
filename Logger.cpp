#include <Logger.h>

#include <chrono>
#include <ctime>

using namespace Log;

const std::unordered_map<Verbosity, std::string> Logger::typeString = 
{ 
    {Verbosity::DEBUG, "DEBUG"}, {Verbosity::INFO, "INFO"}, {Verbosity::WARNING, "WARNING"},
    {Verbosity::VERBOSITY_ERROR, "ERROR"}, {Verbosity::CRITICAL, "CRITICAL"}
};

void Logger::Log(const std::string& msg)
{
    if(active)
        DoLog(msg);
}

void Logger::Log(const std::string& msg, Verbosity level)
{
    if (active && level >= verbosity_)
    {
        auto formattedMsg = FormatMsg(msg, level);
        DoLog(formattedMsg);
    }
}

void Logger::Flush()
{
    DoFlush();
}

std::string Logger::FormatMsg(const std::string& msg, Verbosity level)
{
    std::string formattedMsg = formatStr_;
    formattedMsg = ReplaceToken("%d", formattedMsg, GetFormattedDate());
    formattedMsg = ReplaceToken("%t", formattedMsg, typeString.at(level));
    formattedMsg = ReplaceToken("%m", formattedMsg, msg);

    return formattedMsg;
}

std::string Logger::GetFormattedDate()
{
    using namespace std::chrono;

    system_clock::time_point p = system_clock::now();
    std::time_t t = system_clock::to_time_t(p);
    char mbstr[100];
    std::strftime(mbstr, sizeof(mbstr), "%H:%M:%S", std::localtime(&t));

    return std::string(mbstr);
}

std::string Logger::ReplaceToken(const std::string& token, const std::string& msg, const std::string& data)
{
    std::string formattedMsg = msg;

    auto index = msg.find(token);
    if (index != std::string::npos)
        formattedMsg = formattedMsg.replace(index, token.length(), data);

    return formattedMsg;
}