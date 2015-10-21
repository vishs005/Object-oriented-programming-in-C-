#ifndef CSCI_311_BSTapp_H
#define CSCI_311_BSTapp_H

#include"BST.h"


class BSTapp {
    private:
        BST tree;
    
        // Reads commands from stdin and executes appropriate BST functions
        void processCommand();
        // Splits a string into its elements seperated by spaces (' ').
        vector<string> split(string s);
	void processInsert(string &); // insert the node in the tree.
	void processFind(string &); // find the node from the tree.
	void processDelete(string & ); // deletes the particular node with matching of key and data.
	void processPrint(); // prints the tree.
	void processQuit(); // exiting the program.
     public:
	void mainLoop();
};
#endif
