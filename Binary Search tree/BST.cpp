#include"BST.h"
#include<iostream>
#include<vector>
#include<cstdlib>

/*
Constructor of the BST class
making the root of the tree null
*/
BST::BST()
{
	m_root=NULL;
}
/*
Distructor of BST to delete every
node which deletes the tree whole
*/
BST::~BST()
{
	while(m_root!=NULL)
		nodeDelete(m_root);
}
/*
Function to find the element from the tree
*/
void BST::treeFind(string key)
{
	treeSearch(m_root,key); 
	for(unsigned int i=0;i<find.size();i++)
	{
		Node *temp=find[i];
		cout<<temp->m_key<<"\t"<<temp->m_data<<"\t\n";
	}
	find.clear(); // clears the vector for the next use.
}
/*
Function with actual implementation 
of how the node is searched in the tree
*/
void BST::treeSearch(Node *m_root,string key)
{
	Node *temp=m_root;
	if( temp==NULL || key==temp->m_key)
	{
		if(temp != NULL )
		{
			find.push_back(temp);// the node found is pushed(stored) in the vector 
		}
	}
	if(temp!=NULL)
	{
		if( key < temp->m_key )
		{
			treeSearch(temp->m_left_child,key);		
		}	
		else
		{
			treeSearch(temp->m_right_child,key);
		}
	}
}
/*
Function to find the exact match of the 
node to be deleted.

*/
void BST::treeFindToDelete(Node *temp,string key,string data)
{
	if( temp == NULL || ( key==temp->m_key && data == temp->m_data ) )
	{
		if( temp != NULL)
		{
			findDelete.push_back(temp);
		}
	}
	if( temp!=NULL )
	{
		if( key < temp->m_key )
		{
			treeFindToDelete(temp->m_left_child,key,data);		
		}	
		else
		{
			treeFindToDelete(temp->m_right_child,key,data);
		}
	}

}

/*
Function to delete the particular node of the tree
*/
void BST::treeDelete(string strKey,string strData)
{
	treeFindToDelete(m_root,strKey,strData);
	for(unsigned int i=0 ; i<findDelete.size() ; i++)
	{
		Node *temp=findDelete[i];
		nodeDelete(temp);
	}
	findDelete.clear();
	

}
/*
Actual impplementation of the delete function of the node to be deleted
*/
void BST::nodeDelete(Node* temp)
{
	Node *y;
	//checking whether the node has left child
	if(temp->m_left_child == NULL)
	{
		transplant(temp,temp->m_right_child);
	}
	//checking whether the node has left child
	else if(temp->m_right_child == NULL)
	{
		transplant(temp,temp->m_left_child);	
	}
	//checking the node which is to be deleted is parent or not.
	else
	{
		y=treeMinimum(temp->m_right_child);
		if(y->m_parent != temp)
		{
			transplant(y,y->m_right_child);
			y->m_right_child = temp->m_right_child;
			y->m_right_child->m_parent=y;
		}
		transplant(temp,y);
		y->m_left_child=temp->m_left_child;
		y->m_left_child->m_parent=y;
	}	
	delete temp;
}
/*
Function to transform the tree depending on 
the node which is deleted.
*/
void BST::transplant(Node *u, Node *v)
{
	if(u->m_parent == NULL)
	{
		m_root=v;
	}
	else if(u == u->m_parent->m_left_child)
	{
		u->m_parent->m_left_child = v;
	}
	else
	{
		u->m_parent->m_right_child=v;
	}
	if(v != NULL)
	{
		v->m_parent=u->m_parent;
	}
}
/*
Funtion to traverse to the smallest node 
from the root or from subtree.
*/
Node* BST::treeMinimum(Node *x)
{
	while(x->m_left_child != NULL)
	{
		x=x->m_left_child;
	}
	return x;
}
/*
Function to print the tree.
*/
void BST::printTree()
{
		tree_walk(m_root);//function call to walk throught the tree.
}
/*
Function to traverse all over the tree and displaying each and every node with the depth
of the node.
*/
void BST::tree_walk(Node* temp)
{
	static int depth=-1;
	if(temp!=NULL)
	{
		depth++;
		tree_walk(temp->m_left_child);
		cout<<"\n"<<depth<<"\t"<<temp->m_key<<"\t"<<temp->m_data;
		tree_walk(temp->m_right_child);
		depth--;
	}
}
/*
Function to insert the element in the tree
depending on the key and comparing whether is small
or greater or equal.
*/
void BST::treeInsert(string key,string data)
{
	Node *nd=new Node(key,data);
	Node *y=NULL;
	Node *x=m_root;
	while(x!=NULL)
	{
		y=x;
		if(nd->m_key < x->m_key) 
		{
			x=x->m_left_child;
		}
		else
		{
			x=x->m_right_child;
		}
	}
	nd->m_parent=y;
	if(y==NULL)
		m_root=nd;
	else if( nd->m_key < y->m_key)
		y->m_left_child=nd;
	else
		y->m_right_child=nd;
}
void BST::quit()
{
	this->~BST();
	exit(0);
}
