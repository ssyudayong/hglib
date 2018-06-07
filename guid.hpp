#pragma once

#pragma comment(lib, "Rpcrt4.lib")

namespace hg
{
	std::string new_uid_strA();
	std::wstring new_uid_strW();

	#ifdef UNICODE
	#define new_uid_str new_uid_strW
	#else
	#define new_uid_str new_uid_strA
	#endif // UNICODE
}

