#include <FileLogger.h>

using namespace Log;

void FileLogger::OpenLogFile(const std::filesystem::path& path)
{
    logFile.open(path, std::ios::trunc);

    this->path = path;
}

bool FileLogger::IsOk() const
{
    return logFile.is_open() && !logFile.bad();
}

void FileLogger::DoLog(const std::string& msg)
{
    if (IsOk())
        logFile << msg << "\n";
}

void FileLogger::DoFlush()
{
    logFile.close();
    logFile.open(path, std::ios::app);
}