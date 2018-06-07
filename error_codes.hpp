
#pragma once

namespace hg
{
	namespace error_codes
	{
		enum : std::size_t
		{
#include "error_code_enum_value.inc"
		};
	}
	typedef size_t error_code;
	class error
	{	
	public:
		error();
		error(error_code c);
		error(error_code c, const std::wstring& w);
		virtual ~error();
		error_code code() const;
		const std::wstring& what() const;
		friend bool operator==(const hg::error& ec, hg::error_code& c);
		friend bool operator!=(const hg::error& ec, hg::error_code& c);
		bool success() const;
		void clear();
		void set_last_error();
		void set(unsigned long c);
		void set(error_code c);
		void set(error_code c, const std::wstring& w);
	private:
		error(const error&);
		const error& operator=(const error&);
	private:
		error_code m_code;
		std::wstring m_what;
	};
	
}
