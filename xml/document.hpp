
#pragma once

namespace hg { namespace xml {
	class document
	{
	public:
		document();
		virtual ~document();
		void parser_file(const std::string &filename, hg::error_code &ec);
		void clear_tag_attribute(const std::string& tagname);
		void clear_tag(const std::string &tagname);
		void clear_script();
		void clear_value(const std::string& value);
		void clear_format_value();
		void clear_tag_value(const std::string &tagname);
		void clear_null_tag();
		void dump_file(const std::string &filename);
	private:
		hg::error_code parser_impl(node* cur, node* parent, node* prev, const char * data, size_t& size);
	private:
		std::vector<hg::xml::element_sp> m_elements;
	};
} }
