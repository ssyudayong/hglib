

#pragma once

#pragma comment (lib, "Ws2_32.lib")

#ifndef SOCKET
#define SOCKET unsigned int
#endif

namespace hg { namespace net {
	class socket
	{
	public:
		socket(SOCKET s);
		socket(int af, int type, int protocol);
		virtual ~socket();
		socket * accept();
		void close();
		int bind(const hg::net::ipaddress& addr);
		int connect(const hg::net::ipaddress& addr);
		int listen(int backlog);
		int receive(char * buf, int len, int flags);
		int send(const char * buf, int len, int flags);
		int set_option(int level, int optname, const char *optval, int optlen);
		int get_option(int level, int optname, char *optval, int *optlen);
		int get_sockname(hg::net::ipaddress& addr);
	private:
		SOCKET m_socket;
	};
} }
