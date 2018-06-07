
#pragma once

namespace hg { namespace algorithm {
	void base64_encode(const void * src, size_t size, std::string &desc);
	bool base64_decode(const void * src, size_t srcsize, void * desc, size_t descsize, size_t &outsize, hg::error_code&ec);
} }

