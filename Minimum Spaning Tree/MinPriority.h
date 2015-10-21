/*-----------------------------
""MinPriority" header file is defined

-------------------------------*/

#ifndef MINPRIORITY_H
#define MINPRIORITY_H
#include "Vertex.h"
#include <vector>

class Minpriority
{

	public:

 		 typedef std::vector<Vertex*> queue;      // vector queue is declared 
		 
 		 int size;
		 queue q;			
  		 queue mine;
   		 queue myq() {return q;};
  		 void minheapinsert(Vertex*);        //minheapinsert prototype
  		 void minheapifyM (int, int);        //minheapifyM prototype
    		 void decreasekeyM (string, string,int);

	private:

 		 void buildminheapM (int);
  		 void heapsort1();

};

#endif
