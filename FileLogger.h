#pragma once

#include <Logger.h>

#include <fstream>
#include <filesystem>

namespace Log
{
    class FileLogger : public Logger
    {
    public:
        void OpenLogFile(const std::filesystem::path& path);
        bool IsOk() const;

    private:
        void DoLog(const std::string& msg) override;
        void DoFlush() override;

        std::ofstream logFile;
        std::filesystem::path path;
    };
}