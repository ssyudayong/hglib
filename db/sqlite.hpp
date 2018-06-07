

#pragma once

struct sqlite3;

namespace hg { namespace db { namespace sqlite {
	class connection
	{
	public:
		connection();
		virtual ~connection();
		bool open(const std::wstring& filename, hg::error_code& ec);
		void close();
		void set_password(const std::wstring& value);
	private:
		sqlite3 * m_db;
		std::string m_password;
	};
} } }
