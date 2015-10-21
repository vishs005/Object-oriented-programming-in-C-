#include"Graph.h"
using namespace std;



Vertex *Graph::extract_min ()					//extracting the min, making vector smaller.
{
	  if (mine.size () == 0)
	    return NULL;

	  int size1 = mine.size () - 1;
	  Vertex *min = mine[0];
	  mine[0] = mine[size1];
	  mine.pop_back ();
	  minHeapifyG (0, size1 - 1);
	  return min;
}

void Graph::MST_prim()						//prim's algorithm
{
	  int count = 0;

	  int weight = 0;

	  map < string, inmap >::iterator n;
	  map < string, int >::iterator it;
	  map < string, inmap >::iterator find;

	  while (!mine.empty ())
	  {
	      		Vertex *u = extract_min ();		//extracting minimum of queue
	      		if(u->m_key == 100)
				cout << u->m_vertex << " NIL 0" << endl;
	     		else
	     		  	cout << u->m_vertex << " " << u -> m_pred << " " << u -> m_key << endl;

	     		 for(int i=0; i < mine.size(); i++)			//counting for printing purposes
				count++;

	      		 weight = u->m_key + weight;		//calculating the weight weight (+100)

	     		 find = g.find (u->m_vertex);		//finding the one we popped in adjacency list.

	     		 for (it = (*find).second.begin (); it != (*find).second.end (); it++)	//iterating through the adjacency list for the one we just popped off
			 {
				  for (int i = 0; i < mine.size (); i++)//iterating through priority queue, decreasing key as necessary
		  		  {
		  		       if (((*find).first == u->m_vertex && (*it).second < 100))
		      		       {
		       			    decreasekey ((*it).first, u->m_vertex, (*it).second);
		       		       }
		    		  }
			 }
	    }
	    cout << weight - 100 <<endl;	//by default keys have a weight of 100, so the first key has a weight of 100.
}													//must be accounted for!

void Graph::minHeapifyG (int i, int size)		//min-heapify function.
{
  	Minpriority cx;

  	int l = (2 * i) + 1;			//left child

  	int r = (2 * i) + 2;			//right child

  	int min;

	// to find the minimum.
  	if (l < size && mine[l]->m_key > mine[i]->m_key) //to check whether it is less than or greater than node to find the minimum
  	{
	      min = l;
	}
	else
	{
      	      min = i;
	}

  	if(r < size && mine[r]->m_key > mine[min]->m_key)
    	{
      	     min = r;
    	}
  	if (min != i)
    	{
      	     std::swap (mine[i], mine[min]); // swap the nodes.
      	     minHeapifyG (min, size);
        }
}

void Graph::decreasekey (string tar, string par, int key)  //sets key and parent for adjacent nodes freshly popped off queue.
{
	int i=0;
	while(i < mine.size())
  	{
	    	if (mine[i]->m_vertex == tar && key < mine[i]->m_key)
	      	{
			mine[i]->m_key = key;
			mine[i]->m_pred = par;
		}
	i++;
	}

    	heapsort ();					  //calling heapsort to resort priority queue.
}

void Graph::buildMinHeap (int size)			  //buiding minimum heap where root is smaller than child.
{
  	for (int i = (floor (mine.size () / 2) - 1); i >= 0; i--)
    		minHeapifyG (i, size);
}

void Graph::setPriority (vector < Vertex * >a)			//copying vector to graph class.
{
  	mine = a;
}

void Graph::addVertex (string a)				//inserting into outer map.
{
 	g.insert (make_pair (a, inmap ()));
}

void Graph::addEdge (string parent, string edge, int weight)	//inserting to inner map
{
	g[parent].insert (make_pair (edge, weight));
}

void Graph::heapsort()				//sorting according to heapsort algorithm.	
{
  	size = mine.size ();
  	buildMinHeap(size);
  	for (int i = size - 1; i >= 1; i--)
    	{
      		std::swap (mine[0], mine[i]);
      		size--;
      		minHeapifyG (0, size);
    	}
}
Graph :: Graph()
{}


