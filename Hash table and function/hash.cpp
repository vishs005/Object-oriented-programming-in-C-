#include"hash.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>


using namespace std;
/*******************
Function to remove the string from the has table
******************/
void Hash::remove(string word)
{
	int i;
	list<string> :: iterator it; // iterator to traverse over the list.
	double newAvgListLen=0; 
	for(i=0;i<HASH_TABLE_SIZE;i++)
	{
    	  for(it=hashTable[i].begin();it!=hashTable[i].end();it++)
	  {
	    if(word==*it)
     	    {
		hashTable[i].erase(it); // erase function to remove the string from the hashtable.
         	newAvgListLen=average();
 		avgLength=(newAvgListLen + avgLength)/2.0;  // average length of the list.
		break;
            }
	  }
	}
}
/*********************************
function to print the hashtable
******************************/
void Hash::print()
{
	int i;
	list<string>::iterator it;
	for(i=0;i<HASH_TABLE_SIZE;i++)
	{
		cout<<i<<":"<<"\t";
		
		for(it=hashTable[i].begin();it!=hashTable[i].end();it++)
		{
			cout<<*it<<", ";
		}
		cout<<endl;
		
	}
}
/*********************
function to build a hash table
*******************/
void Hash::processFile(string filename)
{

	string str;
	int index,count=0,check=0,i,coln=0;
	double newAvgListLen=0;
	collisions=0;

	list<string> :: iterator it;
	std::ifstream myFile(filename.c_str());//opening the file and file pointer pointing to first string in the file
	if(myFile.is_open())
	{	

		while(getline(myFile,str))
		{
			index=hf(str);
			hashTable[index].push_back(str); // add the string at the end of the list at particular index.
			newAvgListLen=average();
			avgLength=(newAvgListLen + avgLength)/2.0;

		}

	}

	for(i=0;i<HASH_TABLE_SIZE;i++)//loop to count the collision and the longest list in the hash table.
	{
		for(it=hashTable[i].begin();it!=hashTable[i].end();++it)
		{
			count++;
		}
		if(check<=count)
		{
			check=count;
		}
		count=0;
		if(hashTable[i].size()!=0)
		{
			coln=hashTable[i].size()-1;
			collisions+=coln;
		}
	}
	longestList=check;
	myFile.close();
}

/*****************************
function to calculate the average of the list at every insert and remove of the string in the list.
******************************/
double Hash::average()
{
	int i;
	double avg=0,sum=0;
	for(i=0;i<HASH_TABLE_SIZE;i++)
	{
		sum=sum + (double)hashTable[i].size();
	}
	avg=(sum/HASH_TABLE_SIZE);
	return avg;
}
/**************************
saving or copying the output in the other file name as filename passed as the string.
***********************/
void Hash::output(string filename)
{
	std::ofstream ofs(filename.c_str());
	int i;
	list<string>::iterator it;
	for(i=0;i<HASH_TABLE_SIZE;i++)
	{
		ofs<<i<<":"<<"\t";
		for(it=hashTable[i].begin();it!=hashTable[i].end();it++)
		{
			ofs<<*it<<", ";
		}
		ofs<<endl;
	}
}
/*****************************
Print the statistics of the hashtable like no of collisions,longest list in the table, average list length.
**************************/
void Hash::printStats()
{
	cout<<"Total collisions = "<<collisions<<endl;
	cout<<"Longest list = "<<longestList<<endl;
	cout<<"Average list length = "<<avgLength<<endl;
}

/*****************************
Function to search the string in the hashtable.
***********************/

bool Hash::search(string word)
{
	int i,flag=0;
	list<string> :: iterator it;
	for(i=0;i<HASH_TABLE_SIZE;i++)
	{

		for(it=hashTable[i].begin();it!=hashTable[i].end();it++)
		{
			if(word==*it)
			{
				flag=1;
				break;
			}
		}

	}

	if(flag==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


