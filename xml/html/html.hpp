
#pragma once

namespace hg { namespace xml { namespace html {
	class document;
	class node;
	typedef std::shared_ptr<node> node_sp;
	class node : std::enable_shared_from_this<node>
	{
		friend document;
	private:
		std::string m_tag;
		std::string m_endtag;
		std::string m_value;
		std::string m_attribute;
		std::string m_data;
		node_sp m_prev;
		node_sp m_sub_first;
		bool m_close_loop;
	};

	class comment_node : public node
	{

	};
	
	class document
	{
	public:
		void parse_file(const std::string& filename);
		void parse_string(const std::string& src);
		void parse_string(const char * src, size_t size);
	private:
		node_sp parse_find_tag(const char * src, size_t size, size_t &len);
	private:
		std::vector<node_sp> m_nodes;
	};
} } }