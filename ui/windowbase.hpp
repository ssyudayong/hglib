
#pragma once

#ifndef HWND_IMPL
#define HWND (void *)
#define HINSTANCE (void *)
#define HMENU (void *)
#endif

namespace hg { namespace ui {
	class windowbase
	{
	public:
		windowbase();
		virtual ~windowbase();
		HWND impl() const;
		HWND parent_impl() const;
		HWND parent_impl(hg::error_code &ec) const;
		hg::error_code show(int mode);
		hg::error_code close();
		hg::error_code destroy();
		hg::error_code clientrect(hg::rect &value) const;
		hg::error_code rect(hg::rect &value) const;
		bool valid() const;
		bool enabled() const;
		bool visible() const;
		hg::error_code create_instance(
			hg::ulong    dwExStyle,
			hg::cpwchar   lpClassName,
			hg::cpwchar   lpWindowName,
			hg::ulong     dwStyle,
			hg::rect lrect,
			windowbase*      hWndParent,
			HMENU     hMenu);
		static hg::error_code message_loop();
	protected:
		virtual long message_proc(HWND hwnd, unsigned int uMsg, unsigned int wParam, int lParam);
	protected:
		hg::error_code create_instance();
		
		hg::error_code create_instance(
			hg::ulong    dwExStyle,
			hg::cpwchar   lpClassName,
			hg::cpwchar   lpWindowName,
			hg::ulong     dwStyle,
			int       x,
			int       y,
			int       nWidth,
			int       nHeight,
			windowbase*      hWndParent,
			HMENU     hMenu);
		hg::error_code create_instance(hg::ulong dwExStyle, hg::cpwchar lpClassName, hg::cpwchar lpWindowName, hg::ulong dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu);
	private:
		HWND m_hwnd;
		int m_position_x;
		int m_position_y;
		int m_height;
		int m_width;
		windowbase* m_parent;
		long m_proc;
	private:
		static std::map<HWND, windowbase*> s_hwnd_window_map;
		static std::mutex s_hwnd_window_map_mutex;
		static windowbase* hwnd_window_map_find(HWND hwnd);
		static void hwnd_window_map_append(HWND hwnd, windowbase* pwb);
		static void hwnd_window_map_remove(HWND hwnd);
	private:
		static HWND create_hwnd_instance(
			hg::ulong    dwExStyle,
			hg::cpwchar   lpClassName,
			hg::cpwchar   lpWindowName,
			hg::ulong     dwStyle,
			int       x,
			int       y,
			int       nWidth,
			int       nHeight,
			HWND      hWndParent,
			HMENU     hMenu,
			HINSTANCE hInstance,
			hg::pvoid    lpParam);
	protected:
		static long __stdcall window_proc_static(HWND hwnd, unsigned int uMsg, unsigned int wParam, int lParam);
	};
} }

