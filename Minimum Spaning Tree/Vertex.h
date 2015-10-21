/*--------------------------------------------

Vertex header file is defined..


---------------------------------------------*/

#ifndef VERTEX_H
#define VERTEX_H
#include<iostream>

using namespace std;

class Vertex
{

	public:

 		 string m_vertex;                //vertex
 		 string m_pred;                  //predecessor
 		 int m_key;                      //key/weight
       		 Vertex (string, string, int);   //parameterised constructor

};

#endif
