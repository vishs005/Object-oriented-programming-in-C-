#include"Node.h"

//Constructor assigning the key and data.
Node::Node(string key, string data)
{
	m_left_child=NULL;
	m_right_child=NULL;
	m_parent=NULL;
	m_key=key;
	m_data=data;
}
//destructor to make a node null.
Node::~Node()
{
	m_left_child=m_right_child=m_parent= NULL;
}
