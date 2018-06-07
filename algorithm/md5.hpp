

#pragma once

namespace hg { namespace algorithm {
	class md5
	{
	public:
		typedef struct {
			unsigned char data[16];
		} value_type;
		static const size_t value_size;
	public:
		md5();
		virtual ~md5();
		void clear();
		void parse(const void * data, size_t size);
		hg::algorithm::md5::value_type dump();
		void fill(hg::algorithm::md5::value_type &data);
	private:
		void * m_impl;
	};
} } 
