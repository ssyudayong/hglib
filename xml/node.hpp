
#pragma once

namespace hg { namespace xml {
	class document;
	class node
	{
		friend document;
	public:
		node();
		virtual ~node();
	private:
		std::string m_tag;
	};
} }