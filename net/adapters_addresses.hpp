

#pragma once

#pragma comment(lib, "Iphlpapi.lib")

namespace hg { namespace net {
	namespace address_family
	{
		typedef enum : unsigned long
		{
			both = 0,
			ipv4 = 2,
			ipv6 = 23
		}value_type;
	}
	namespace adapters_address_list_flags
	{
		enum : unsigned long
		{

			skip_unicast = 0x0001, //Do not return unicast addresses.

			skip_anycast = 0x0002, // Do not return IPv6 anycast addresses.

			skip_multicast = 0x0004, //Do not return multicast addresses.

			skip_dns_server = 0x0008, //Do not return addresses of DNS servers.

			include_prefix = 0x0010, //Return a list of IP address prefixes on this adapter.When this flag is set, IP address prefixes are returned for both IPv6 and IPv4 addresses.
											//This flag is supported on Windows XP with SP1 and later.

			skip_friendly_name = 0x0020, //Do not return the adapter friendly name.

			include_wins_info = 0x0040, //Return addresses of Windows Internet Name Service(WINS) servers.
												//This flag is supported on Windows Vista and later.

			include_gateways = 0x0080, //Return the addresses of default gateways.
												//This flag is supported on Windows Vista and later.

			include_all_interfaces = 0x0100, //Return addresses for all NDIS interfaces.
//This flag is supported on Windows Vista and later.

			include_all_compartments = 0x0200, //Return addresses in all routing compartments.
//This flag is not currently supported and reserved for future use.

			include_tunnel_bindingorder = 0x0400 //Return the adapter addresses sorted in tunnel binding order.This flag is supported on Windows Vista and later.
		};
	}
	typedef struct
	{
		union
		{
			struct  
			{
				unsigned short  sa_family;
				char    sa_data[14];
			} ipv4;
			struct
			{
				short   sin6_family;
				u_short sin6_port;
				u_long  sin6_flowinfo;
				struct  in6_addr sin6_addr;
				u_long  sin6_scope_id;
			} ipv6;
		} data;
		size_t size;
	} socket_address;
	class adapters_address;
	typedef std::vector<adapters_address> adapters_address_list;
	class adapters_address
	{
	public:
		struct unicast_address
		{
			socket_address address;
		};
	public:
		static void get_adapters_address_list(address_family::value_type family, unsigned long flags, adapters_address_list &list);
	private:
		std::wstring m_desc;
		std::wstring m_friendname;
		std::vector<unicast_address> m_unicast_address_list;
	};
	
	
} }