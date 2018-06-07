

#pragma once

namespace hg
{
	class mutex
	{
	public:
		mutex();
		virtual ~mutex();
		void lock();
		bool try_lock();
		void unlock();
	private:
		void * m_mutex;
	};

	class mutex_lock
	{
	public:
		mutex_lock(mutex& m);
		virtual ~mutex_lock();
	private:
		mutex & m_mutex;
	};

	class sys_mutex
	{
	public:
		virtual ~sys_mutex();
		sys_mutex* create(const std::wstring& name, hg::error_code &ec);
	private:
		sys_mutex();
	private:
		void * m_mutex;
	};
}

#define MUTEX_CURRENT_SECTION(m) hg::mutex_lock __lock_mutex_current_section(m)
