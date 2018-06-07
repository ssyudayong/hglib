

#pragma once

#ifndef _HG_BUFFER_HPP_
#define _HG_BUFFER_HPP_

namespace hg
{
	class buffer : public std::enable_shared_from_this<buffer>
	{
	public:
		buffer();
		buffer(size_t bufsize);
		buffer(void * pdata, size_t datasize);
		buffer(size_t requestsize, void * pdata, size_t datasize);
		virtual ~buffer();
		void resize(size_t newsize);
		void clear();
		void free();
		unsigned char * get() const;
		void set_length(size_t value);
		size_t length() const;
		size_t size() const;
		bool empty() const;
		void to_base64(std::string& str);
		size_t from_base64(std::string& str);
	private:
		unsigned char * m_data;
		size_t m_size;
		size_t m_length;
	};
}

#endif // _HG_BUFFER_HPP_
