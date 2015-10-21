/*----------------------------------------------

All the methods of Min priority are implemented
----------------------------------------------*/

#include "MinPriority.h"
#include<iostream>
#include<math.h>
using namespace std;



void Minpriority::heapsort1()				     //heap sort implementation, vector start at 0.
{
  	size = mine.size ();                                 //returning the size.
	int i = size-1;
	while(i>=1)
 	{
 	     std::swap (mine[0], mine[i]);
 	     size--;
 	     minheapifyM (0, size);
	     i--;
 	}
}
void Minpriority::minheapinsert (Vertex *a)
{
 	 q.push_back (a);					//insert into heap
}

void Minpriority::minheapifyM (int i, int size)			//similar to algorithm in book, modified for min-heapify
{

 	 Minpriority cx;

 	 int l = (2 * i) + 1;					// retrival of Left node

 	 int r = (2 * i) + 2;					// retrival of right node

  	 int min;
   	 cout << l ;
    	 cout << mine[l]->m_key ;
   	 cout << mine[i]->m_key;
   	 cout << size;

	 if (l < size && mine[l]->m_key > mine[i]->m_key)
    	 {
      		min = l;
    	 }
  	 else
    	 {
      		min = i;
    	 }

  	 if (r < size && mine[r]->m_key > mine[min]->m_key)
    	 {
       		min = r;
    	 }

  	 if (min != i)
    	 {
      		std::swap (mine[i], mine[min]);
      		minheapifyM (min, size);
    	 }
}



void Minpriority::buildminheapM (int size)				//building max heap, vector starting at 0.
{
 	 for (int i = (floor (mine.size () / 2) - 1); i >= 0; i--)
    		minheapifyM (i, size);
}

void Minpriority::decreasekeyM (string tar, string par, int key)	//sets key and parent for adjacent nodes freshly popped off the queue
{
	 int i = 0;
	 while(i < mine.size())
	 {
     		if (mine[i]->m_vertex == tar && key < mine[i]->m_key)
      		{
        		mine[i]->m_key = key;
        		mine[i]->m_pred = par;
      		}
		i++;
	 }
    	 heapsort1 ();								//calling heapsort to resort priority queue.
}


