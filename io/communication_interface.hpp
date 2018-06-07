#pragma once

namespace hg { namespace io {
	class communication_interface
	{
	public:
		virtual void open(hg::error& error) = 0;
		virtual void close() = 0;
		virtual void read(void * buffer, size_t buffersize, size_t &readsize, size_t timeout_msec, hg::error& error) = 0;
		virtual void write(const void * buffer, size_t buffersize, size_t &writesize, size_t timeout_msec, hg::error& error) = 0;
		virtual bool is_connected() = 0;
	};
} }
