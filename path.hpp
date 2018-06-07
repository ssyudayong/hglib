
#pragma once

#ifndef _HG_PATH_HPP_
#define _HG_PATH_HPP_

namespace hg
{
	bool file_exist(const std::string &filename);
	bool file_exist(const std::wstring &filename);
	bool file_exist(const wchar_t * filename);
	bool file_exist(const char * filename);
	std::string file_find_extensionA(const std::string &filename);
	std::wstring file_find_extensionW(const std::wstring &filename);
	std::wstring file_remove_externsionW(const std::wstring &filename);
	// 功能：获取程序文件目录
	// 注意：没有最后的斜杠
	const std::wstring& exe_path();
	const std::wstring& exe_fullname();
	bool valid_path(const std::wstring &path);
	bool valid_path(const std::string &path);
	void get_path_items(const std::wstring& path, std::vector<std::wstring>& items, bool allowpath = false);
	std::wstring path_file_name(const std::wstring &path);
	std::wstring path_add_backslash(const std::wstring &path);
	std::wstring path_remove_backslash(const std::wstring &path);

	#ifdef UNICODE
	#define file_find_extension file_find_extensionW
	#define file_remove_externsion file_remove_externsionW
	#else
	#define file_find_extension file_find_extensionA
	#endif // UNICODE
}

#endif // _HG_PATH_HPP_
