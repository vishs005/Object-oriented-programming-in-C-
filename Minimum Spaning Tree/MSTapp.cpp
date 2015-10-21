
#include"MSTapp.h"
#include"Graph.h"
#include"Vertex.h"
#include<math.h>
#include<stdlib.h>

void MSTapp::start ()
{
 	 string vertex;
 	 string edge;
 	 int weight;
 	 Graph l;
 	 Minpriority min;

 	 while (cin.peek () != '\n')				  //while not a new line, get input
 	 {
  		    cin >> vertex;
  		    l.addVertex (vertex);			  //add vertex to adj list
  		    Vertex *p = new Vertex (vertex, "NIL", 100);  // intialise the vertex will NILL and Infinity which in this case is 100	
  		    min.minheapinsert (p);			  //insert vertex into priority queue
  	 }

 	 while (cin >> vertex)					  //get the inputs of next line that is edges and their weights.
   	 {
    		   cin >> edge;
    		   cin >> weight;
		
    		   l.addEdge (vertex, edge, weight);
   		   l.addEdge (edge, vertex, weight);
   	 }

 	 std::vector < Vertex * >a = min.myq ();		  //creating a copy of pri queue to use in Graph class.
 	 l.setPriority (a);

  	 l.MST_prim ();						  // MST_prim is called where prims algorithm is used
}

int main ()
{
 	 MSTapp l;
 	 l.start();
}
