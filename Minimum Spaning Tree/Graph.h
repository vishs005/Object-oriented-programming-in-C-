
/*-------------------------------
Graph Header file is defined


---------------------------------*/

/*----------------------------------------

Graph header file is defined.


------------------------------------------*/

#ifndef GRAPH_H
#define GRAPH_H

#include<map>
#include<iostream>
#include "MinPriority.h"
#include "Vertex.h"
#include <math.h>

using namespace std;


class Graph
{

	public:

	  Graph();				   //default constructor 
	  typedef std::vector < Vertex * >queue;   // queue is created
	  queue mine;
	  int size;  
	  
	  void print ();
	  void MST_prim ();
	  Vertex *extract_min ();
	  void addVertex (string);                 //function prototype of addVertex.
	  void minHeapifyG (int, int);		   //function prototype of minHeapifyG
	  void addEdge (string, string, int);
	  void decreasekey (string, string, int); //function to update the key is it is smaller than the first one
	  void setPriority (vector < Vertex * >);
	
	private:

	  void heapsort ();
	  void buildMinHeap (int);
	  typedef map < string, int > inmap;
	  typedef map < string, inmap > graph;
	  graph g;

};

#endif
