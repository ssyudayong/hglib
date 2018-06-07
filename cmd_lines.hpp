

#pragma once

#pragma comment(lib, "Shell32.lib")

namespace hg
{
	class option_base
	{
	public:
		option_base(const std::wstring& name, const std::wstring& shortname) 
		{
			m_name = name; m_shortname = shortname;
		}
		virtual void set_value(void * data, size_t size = 0) {}
	protected:
		std::wstring m_name;
		std::wstring m_shortname;
	};
	template<class T>
	class option : option_base
	{
	public:
		typedef T value_type;
	public:
		option(const std::wstring& name, const std::wstring& shortname, T defaultvalue) :option_base(name, shortname)
		{
			m_default = defaultvalue;
		}
		T get_value(){ return m_value; }
		T get_default() { return m_default; }
		virtual void set_value(void * data, size_t size = 0)
		{
			if ((size != 0) && (size != sizeof(value_type))) { return; }
			T* p = (T*)data;
			m_value = *p;
		}
	private:
		T m_default;
		T m_value;
	};
	
	class cmd_lines
	{
	public:
		static size_t count();
		static const std::wstring& at(const int index);
	private:
		static void init_data();
	private:
		static std::vector<std::wstring> s_data;
		static bool s_inited;
	};
}


