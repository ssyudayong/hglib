

#pragma once

namespace hg { namespace net {
	class io_completion_port
	{
	public:
		io_completion_port(size_t threadcount = 1);
		virtual ~io_completion_port();
	private:
		hg::handle m_impl;
	};
} }
