#ifndef CSCI_311_NODE_H
#define CSCI_311_NODE_H
#include<string>
using namespace std;

class Node{
    friend class BST;
    private:
        Node* m_left_child; // creating a instance of the node which will be the left node.
        Node* m_right_child; // creating a instance of the node which will be the right node.
        Node* m_parent; //creating a instance of the node of parent node.
        string m_key; // declaring the key as a string.
        string m_data; // declaring the key as a string.
    public:
       // Node(Node*, Node*, Node*, string, string);
        Node(string, string); // parametrised constructor.
	~Node(); // destructor.
};
#endif
