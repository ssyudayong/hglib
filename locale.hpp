

#pragma once

namespace hg { namespace locales {
	int get_default_locale_id();
	void init_multilanguage_support(const std::wstring& ml_filepath, int default_locale_id, hg::error &error);
	void release_multilanguage_support();
	std::wstring format(const hg::sys_time & dt);
	static const std::wstring& locale_string(const std::wstring &src);
}}

#define LS(s) hg::locales::locale_string(s)
