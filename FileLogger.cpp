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
    fMutex.lock();
    if (IsOk())
        logFile << msg << "\n";
    fMutex.unlock();
}

void FileLogger::DoFlush()
{
    if(fThread.joinable())
        fThread.join();

    fThread = std::thread([this]()
    {
        this->fMutex.lock();

        logFile.flush();

        this->fMutex.unlock();
    });
}