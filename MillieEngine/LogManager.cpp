#include "LogManager.h"

namespace me {
	LogManager::LogManager()
	{
		setType("LogManager");
		m_p_f = nullptr;
		m_do_flush = false;
	}

	LogManager& LogManager::getInstance()
	{
		static LogManager instance;
		return instance;
	}

	int LogManager::startUp()
	{

		Manager::startUp();

		errno_t err = fopen_s(&m_p_f, LOGFILE_DEFAULT.c_str(), "w");
		if (err != 0 || m_p_f == nullptr)
		{
			std::cout << "Failed to create the log file." << std::endl;
			return -1;
		}
		else
		{
			std::cout << "Log file created successfully." << std::endl;
			writeLog("Log Manager Started %s", LM.getTimeString());
			return 0;
		}
	}

	void LogManager::shutDown()
	{


		LM.writeLog("Log Manager Shuting down %s", LM.getTimeString());
		if (m_p_f != nullptr)
		{
			fclose(m_p_f);
			m_p_f = nullptr;
		}

		Manager::shutDown();
	}

	int LogManager::writeLog(const char* fmt, ...) const
	{
		int result = -1;

		if (m_p_f != nullptr)
		{
			va_list args;
			va_start(args, fmt);
			result = vfprintf(m_p_f, fmt, args);
			fprintf(m_p_f, "\n");
			va_end(args);
		}

		if (m_do_flush)
		{
			fflush(m_p_f);
		}


		return result;
	}

	void LogManager::setFlush(bool new_do_flush)
	{
		m_do_flush = true;
	}
	char* LogManager::getTimeString()
	{
		static char time_str[30];
		tm p_time;
		time_t now;
		time(&now);
		localtime_s(&p_time, &now);
		sprintf_s(time_str, "%02d:%02d:%02d",
			p_time.tm_hour,
			p_time.tm_min,
			p_time.tm_sec
		);
		return time_str;
	}

}
