
#pragma once

#ifndef _HG_TYPE_DEF_HPP_
#define _HG_TYPE_DEF_HPP_

namespace hg
{
	typedef unsigned short			ushort;
	typedef wchar_t					wchar;
	typedef wchar_t *				pwchar;
	typedef const wchar_t *			cpwchar;
	typedef char *					pchar;
	typedef const char *			cpchar;
	typedef unsigned char			uchar;
	typedef unsigned char *			puchar;
	typedef const unsigned char *	cpuchar;
	typedef unsigned long			ulong;
	typedef unsigned long long		ullong;
	typedef unsigned int			uint;
	typedef void *					pvoid;
	typedef void *					handle;
	typedef unsigned long long		jsdatetime;

	template<typename outtype, typename intype>
	inline outtype implicit_cast(intype value) { return value; }

#pragma pack(1)
	typedef struct 
	{
		ushort year;
		ushort month;
		ushort week;
		ushort day;
		ushort hour;
		ushort minute;
		ushort second;
		ushort milliseconds;
	} sys_time;

	struct point
	{
		long x;
		long y;
		point();
		point(long lx, long ly);
	};

	struct rect
	{
		long left;
		long top;
		long right;
		long bottom;
		rect();
		rect(long vleft, long vtop, long vright, long vbottom);
		rect(hg::point& lt, hg::point& rb);
		rect(long vleft, long vtop, hg::point& rb);
		rect(hg::point& lt, long vright, long vbottom);
		long height() const;
		long width() const;
		hg::point lefttop() const;
		hg::point rightbottom() const;
		hg::point leftbottom() const;
		hg::point righttop() const;
	};
#pragma pack()
}

#endif // _HG_TYPE_DEF_HPP_
