
#pragma once

namespace hg { namespace net {
	class uri
	{
	public:
		typedef std::shared_ptr<std::vector<std::pair<hg::astring, hg::astring>>> parameters_type;
	public:
		uri();
		explicit uri(hg::astring& src);
		virtual ~uri();
		void clear();
		bool valid() const;
		hg::astring to_string() const;
		void set_scheme(const hg::astring& scheme);
		std::string get_authority() const;
		parameters_type get_parameters() const;
		static void encode(const std::string& str, const std::string& reserved, std::string& encodedStr);
		static bool decode(const std::string& str, std::string& decodedStr, bool plusAsSpace = false);
	protected:
		void parse(const hg::astring& src);
		void parse_path_etc(hg::astring::const_iterator& it, const hg::astring::const_iterator& end);
		void parse_path(hg::astring::const_iterator& it, const hg::astring::const_iterator& end);
		void parse_query(hg::astring::const_iterator& it, const hg::astring::const_iterator& end);
		void parse_fragment(hg::astring::const_iterator& it, const hg::astring::const_iterator& end);
		void parse_authority(hg::astring::const_iterator& it, const hg::astring::const_iterator& end);
		void parse_host_and_port(hg::astring::const_iterator& it, const hg::astring::const_iterator& end);
		unsigned short get_well_known_port() const;
	private:
		bool m_valid;
		hg::astring m_userinfo;
		unsigned short m_port;
		hg::astring m_host;
		hg::astring m_scheme;
		hg::astring m_path;
		hg::astring m_query;
		hg::astring m_fragment;
		static const hg::astring s_illegal;
		static const hg::astring s_reserved_path;
		static const hg::astring s_reserved_fragment;
	};
} }
