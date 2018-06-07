

#pragma once

#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "Setupapi.lib")

namespace hg { namespace io {
	namespace impl{ class serial_port_impl; }
	
	class serial_port : public hg::io::communication_interface
	{
	public:
		typedef struct
		{
			unsigned long baudrate;
			unsigned char parity;
			unsigned char datasize;
			unsigned char stopbits;
		} comm_state_se;
	public:
		serial_port();
		virtual ~serial_port();
	public:
		static void enum_ports(std::vector<std::wstring> &list, hg::error& error);
		void set_dcb_se(const comm_state_se& value);
		void set_portname(const std::wstring &value);
	public:	// hg::io::communication_interface
		virtual void open(hg::error& error);
		virtual void close();
		virtual void read(void * buffer, size_t buffersize, size_t &readsize, size_t timeout_msec, hg::error& error);
		virtual void write(const void * buffer, size_t buffersize, size_t &writesize, size_t timeout_msec, hg::error& error);
		virtual bool is_connected();
	private:
		std::unique_ptr<impl::serial_port_impl> m_impl;
	};
} }

