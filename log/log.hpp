
#pragma once

namespace hg 
{ 
	namespace log 
	{
	namespace impl { class log_impl; }
	typedef std::shared_ptr<impl::log_impl> log_impl_sp;
	class console
	{
	public:
		static void info(const std::string& msg);
		static void error(const std::string& msg);
		static void info(const std::wstring& msg);
		static void error(const std::wstring& msg);
	};
	class filelog
	{
	public:
		filelog(const std::string& logname, const std::string& logfile);
		virtual ~filelog();
	private:
		log_impl_sp m_log;
	};
	class rotatinglog
	{
	public:
		rotatinglog(const std::string& logname, const std::string& logfile, size_t maxsize, size_t rotate);
	private:
		log_impl_sp m_log;
	};
	class dailylog
	{
	public:
		dailylog(const std::string& logname, const std::string& logfile, size_t hour, size_t minute);
	private:
		log_impl_sp m_log;
	};
	}

	typedef log::console clog;
}