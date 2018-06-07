
#pragma once

namespace hg { namespace xml {
	namespace element_type
	{
		enum : int
		{
			tag_element,
			tag_end_element,
			value_element,
			delete_element
		};
	}
	class element;
	typedef std::shared_ptr<element> element_sp;
	class element : public std::enable_shared_from_this<element>
	{
	public:
		bool closed_loop() const;
		bool format_element() const;
	public:
		static void parser(const char * pdata, size_t size, std::vector<element_sp>& list);
	private:
		static size_t parser_value(const char * pdata, size_t size, std::vector<element_sp>& list);
		static size_t parser_tag(const char * pdata, size_t size, std::vector<element_sp>& list);
		static size_t parser_endtag(const char * pdata, size_t size, std::vector<element_sp>& list);
	public:
		std::string data;
		std::string tag;
		int type;
	};
} } 
