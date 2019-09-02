/**
*@file: 	mysort.cpp
*
*@note: 	A program that reads from a particular file of unique integers and outputs
*		a sorted file and outputs the sorted list.
*
*@description:	The program uses QuickSort and MergeSort techniques to sort a given array of
*		integers.Since, the size of the text file is not constant,I have utlized a
*		vector as the container for all the elements. The size of the vector being
*		dynamic can be used to hold an arbitrary number of integers. Once they are
*		sorted inside the vector,they can be written into a file.
*
*@author: 	Diptarshi Chakraborty
*
*@date:
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
*@func:		myReadFile
*
*@description: This function takes the file name as an input and then prints the elements to a vector
*	       A vector is a dynamic array that is provided by the C++ STL.
*
*@param:       char *s(A array of characters representing file names), vector<int> &g1(a vector containing integers)
*
*@return:     vector<int> &g1(Elements inside the array changes)
*/

void myReadFile(char *s,vector<int> &g1)
{
	ifstream fin;
	fin.open(s);
	int i;
	while(fin>>i)
        {
                /*Read a Line from File*/
                g1.push_back(i);
        }

}

/**
*@func:         myWriteFile
*
*@description: This function takes the file name as an input and then prints the elements to a vector
*	       A vector is a dynamic array that is provided by the C++ STL.
*
*@param:       char *s(A array of characters representing file names), vector<int> &g1(a vector containing integers)
*
*@return:      vector<int> &g1(Elements inside the array changes)
*/

void myWriteFile(char *s,vector<int> &g1)
{
        ofstream fout;
        fout.open(s);
	string line;
        int i;
	for(int i=0;i<g1.size();i++)
        {
		fout << g1[i] << endl;
        }

	fout.close();

}


/**
*@func: 	myVectorTest
*
*@description:  Prints and test a vector
*
*@param:
*
*@return:
*/

void myVectorTest(vector<int> &g1)
{

	for(int i=0;i<50;i++)
	{
		g1.push_back(i);
	}

}

/**
*@func: 	myReversePrint
*
*@description:  Reverse prints a vector
*
*@param:
*
*@return:
*/

void myReversePrint(vector<int> g1)
{
	for(int i=g1.size()-1 ;i>=0; i--)
	{
		std::cout << g1[i] <<endl;
	}

}

/**
*@func:         myReverseFill
*
*@description:  Fills the vector with numbers from 50 to 1
*
*@param:
*
*@return:
*/

void myReverseFill(vector<int> &g1)
{
        for(int i=50 ;i>=0; i--)
        {
                g1.push_back(i);
        }

}

/**
*@func:		myPrint
*
*@description:  Prints all the elements of a given vector
*
*@param:	vector<int> g1
*
*@return:	void
*/

void myPrint(vector<int> g1)
{
	for(int i=0;i<g1.size();i++)
	{
		std::cout << g1[i] << endl;
	}
}

/**
*@func:         myQuickSort
*
*@description:
*
*@param:        vect<int> &g1,int l, int r
*
*void:          void
*/

int myPartition(vector<int>& g1,int l, int r)
{

	int pivot_index=(l+r)/2;
	int pivot=g1[pivot_index];

	int i=l;
	int j=r;

	while(i<=j)
	{
		while(g1[i] < pivot)
		{
			i++;
		}
		while(g1[j] > pivot)
		{
			j--;
		}


		if(i<=j)
		{
			int temp=g1[i];
			g1[i]=g1[j];
			g1[j]=temp;
			i++;
			j--;
		}
	}

	return i;
}


/**
*@func:		myQuickSort
*
*@description:
*
*@param:	vect<int> &g1,int l, int r
*
*void		void
*/

void myQuickSort(vector<int>& g1,int l, int r)
{

	if(l < r)
	{
		int pivot_index=myPartition(g1 , l , r);
		myQuickSort(g1, l, pivot_index - 1);
		myQuickSort(g1, pivot_index + 1, r);
	}
}

/**
*@func:         main
*
*@description:	main function of the program
*
*@param:	int argc, char **argv
*
*@return:	int
*/

int main(int argc, char **argv)
{

	char s[] = "--name";

	int flag=0; /*Sets a flag variable*/

	for(int i=0;i<6;i++)
	{
		if(argv[1][i] != s[i])
		{
			flag=1;
		}

	}

	if(flag==0)
	{
		std::cout << "Diptarshi Chakraborty" << endl;
		return 0;
	}
	else
	{

		vector<int> g1;
		myReadFile(argv[1],g1);

		#ifdef QUICKSORT
		/*Sorting the vector using quicksort*/
		myQuickSort(g1,0,g1.size()-1);
		#endif /*QUICKSORT*/

		myWriteFile(argv[2], g1);
		return 0;
	}
}
