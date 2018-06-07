

#pragma once

namespace hg
{
	void to(jsdatetime desc, hg::sys_time & src);
	void to(const hg::sys_time & src, jsdatetime &desc);
	//void to(const SYSTEMTIME & src, std::time_t &desc);
	//void to(std::time_t src, SYSTEMTIME &desc);
	void to(const hg::sys_time& src, std::time_t &desc);
	void to(std::time_t src, hg::sys_time &desc);
	void now_sys(hg::sys_time & st);
	void now_local(hg::sys_time & st);
	std::string to_iso8601_longA(const hg::sys_time& src);
	std::wstring to_iso8601_longW(const hg::sys_time& src);
	bool parse_iso8601_long(const std::string& src, hg::sys_time& st);
	bool parse_iso8601_long(const std::wstring& src, hg::sys_time& st);
}

