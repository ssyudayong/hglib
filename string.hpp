/// *********************************************************************************************
/// @file   string.hpp
/// @brief  string function
/// @author yu dayong
/// @date 	2018-04-12
/// *********************************************************************************************

#pragma once

#ifndef _HG_STRING_HPP_
#define _HG_STRING_HPP_

namespace hg
{
	typedef std::wstring wstring;
	typedef std::string  astring;
	std::wstring c2w(const std::string & src);
	std::wstring c2w(const wchar_t * src);
	std::string w2c(const std::wstring & src);
	std::string w2c(const char * src);
	std::wstring utf8tow(const std::string & str);
	std::wstring utf8tow(const char * str);
	std::string wtoutf8(const std::wstring & str);
	std::string wtoutf8(const wchar_t * str);
	std::size_t findcount(const std::string& str, char c);
	std::size_t findcount(const std::wstring& str, wchar_t c);
	bool is_digit(const std::wstring& value);
	bool is_digit(const std::string& value);
	void replace_all(std::wstring& src, const std::wstring &sub, const std::wstring &rs);
	void replace_all(std::string& src, const std::string &sub, const std::string &rs);
	void hexstring(std::wstring& desc, const std::wstring& src);
	void hexstring(std::string& desc, const std::wstring& src);
	void hexstring(std::wstring& desc, const std::string& src);
	void hexstring(std::string& desc, const std::string& src);
	void hexstring(std::wstring& desc, const void * src, size_t len);
	void hexstring(std::string& desc, const void * src, size_t len);
	bool base64_encode(const std::string &in, std::string *out);
	bool base64_encode(const char *input, size_t input_length, char *out, size_t out_length);
	bool base64_decode(const std::string &in, std::string *out);
	bool base64_decode(const char *input, size_t input_length, char *out, size_t out_length);
	void to_lower(std::string& src);
	void to_lower(std::wstring& src);
	void * find(const void * src, size_t size, const void * fs, size_t fssize);
	bool to(const hg::astring& src, unsigned short &value);
	void to_hex(char c, char * pc);
}

#endif // _HG_STRING_HPP_
