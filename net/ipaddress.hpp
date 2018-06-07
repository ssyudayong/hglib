#pragma once

#pragma comment (lib, "Ws2_32.lib")

namespace hg { namespace net { 
	class ipaddress;
	typedef std::shared_ptr<ipaddress> ipaddress_sp;
	class socket;
	class ipaddress
	{
		friend socket;
		struct addr_impl;
	public:
		ipaddress();
		virtual ~ipaddress();
		bool load(const void * paddr, int length);
		std::string ipstringA() const;
		std::string __inline ipv4stringA() const;
		std::string __inline ipv6stringA() const;
		unsigned short __inline port() const;
		bool ipequal(const ipaddress& ipaddr) const;
		unsigned short __inline family() const;
		addr_impl* obj() const;
		bool is_v4() const;
		bool is_v6() const;
		size_t length() const;
	private:
		addr_impl * m_impl;
		std::size_t m_length;
		unsigned short m_port;
	public:
		static const std::size_t Ipv4Size;
		static const std::size_t Ipv6Size;
	};
}}
