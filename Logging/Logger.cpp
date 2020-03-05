#include "Logger.h"

Logger::Logger(std::ostream& out, Level minLogLevelk) : m_out(out), m_minLogLevel(minLogLevelk)
{
}

void Logger::Log(const std::string& message, Level level)
{
	if (level < m_minLogLevel)
		return;
	switch (level)
	{
	case Logger::Level::Debug:
		m_out << "[Debug] ";
		break;
	case Logger::Level::Info:
		m_out << "[Info] ";
		break;
	case Logger::Level::Warning:
		m_out << "[Warning] ";
		break;
	case Logger::Level::Error:
		m_out << "[Error] ";
		break;
	default:
		break;
	}
	m_out << message << std::endl;

	//m_out.flush();
}
