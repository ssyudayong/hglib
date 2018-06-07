
#pragma once

namespace hg { namespace xml {
	template<class T>
	class xml_node
	{
	public:
		typedef T character_type;
		typedef struct
		{
			character_type * data;
			size_t size;
		} data_type;
	private:
		data_type m_name;
		data_type m_value;
		std::vector<data_type> m_attributes;
		std::vector<xml_node> m_sub_nodes;
	};
} }