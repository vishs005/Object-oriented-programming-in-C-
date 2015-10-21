#include"BSTapp.h"
#include"BST.h"
#include<iostream>
#include<cstdlib>


using namespace std;


	




/*
main loop to process the command lines till end of the file.
*/
void BSTapp::mainLoop()
{
	while(!cin.eof())
	{
		processCommand();// call of function to get the input from the user.
		cout<<endl;
	}
}

/*
Function to process the command and calling the appropriate funtion
depending on the function.
*/
void BSTapp::processCommand()
{
	string s;
	getline(cin , s);
	string command = s.substr(0, s.find(' '));
	if (command == "insert")	processInsert( s );		
	else if (command == "find")	processFind( s );
	else if (command == "delete")	processDelete( s );
	else if (command == "print")	processPrint();
	else if (command == "quit")	processQuit();

}
/*
Function to call the insert function saperating the key and data from the command or string
*/
void BSTapp::processInsert(string& s)
{
	s.erase(0,s.find(' ')+1);
	string keytoinsert=s.substr(0, s.find(' '));
	s.erase(0 , s.find(' ')+1);
	string data=s;
	tree.treeInsert(keytoinsert,data);
}
//-------------------------------------------------------------
/*
Function to call the function saperating the key to be searched.
*/
void BSTapp::processFind(string& s)
{
	s.erase(0,s.find(' ')+1);
	string keytofind = s.substr(0 , s.find(' '));
	tree.treeFind(keytofind);
	
}
//-----------------------------------------------------------
/*
Function to process the command to call the delete function
pass the data and the key as the string parameters.
*/
void BSTapp::processDelete(string& s)
{
	s.erase(0, s.find(' ')+1);
        string keytodelete=s.substr(0, s.find(' '));
        s.erase(0 , s.find(' ')+1);
        string data=s;
    	tree.treeDelete(keytodelete,data);
}
//-------------------------------------------------------------
/*
process the print command to print the whole tree
*/
void BSTapp::processPrint()
{
	tree.printTree();
}
//-------------------------------------------------------------
/*
Quit function to exit program and not saving anything.
*/
void BSTapp::processQuit()
{
	tree.quit();

}
//-------------------------------------------------------------
/*
main entry point of the program.
*/
int main()
{
	BSTapp bstapp;
	bstapp.mainLoop();
	return 0;
}
