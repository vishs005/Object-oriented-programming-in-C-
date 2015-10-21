
#include"Vertex.h"
/*--------------------------------------
Vertex constructor in which vertex is created,
its predecessor and key are intialized.

----------------------------------------*/
Vertex::Vertex (string vertex, string pred, int key)		
{
	m_vertex = vertex;
	m_pred = pred;
	m_key = key;
}
