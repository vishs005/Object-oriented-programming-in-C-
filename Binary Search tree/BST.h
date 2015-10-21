#ifndef CSCI_311_BST_H
#define CSCI_311_BST_H

#include"Node.h"
#include<string>
#include<vector>


class BST {
    private:
        Node* m_root;
        int m_size;
	vector<Node *> find;
	vector<Node *> findDelete;
        // Returns the node with the lowest key-value within subtree x
        Node* tree_minimum(Node* x);

        // Replaces the subtree rooted at u by the subtree rooted at v
      

        void print_info(Node* x);
    public:
        BST();
        ~BST();
        // Creates node and inserts in tree while maintaining BST properties
        void treeInsert(string key, string data);
	void nodeDelete(Node*);
        // Prints the contents of each node and its depth
        void tree_walk(Node* x); 

        // Deletes every node with matching key/data 
        // while maintaining BST properties
        void treeDelete(string key, string data);
	//Find/ Search the node with matching key
	void treeFind(string);
	//Find/Search the node with matching key and data
	void treeSearch(Node*,string);
	//Function to move to lowest from the parent
	Node* treeMinimum(Node *x);
	//To transform the tree after deletion of the node
	void transplant(Node *, Node *);
	//Find the node which is to be deleted
	void treeFindToDelete(Node *,string , string);

        // Begins the tree_walk at m_root
        void printTree();
        void quit();
      //  void print_first_three();
};
#endif
