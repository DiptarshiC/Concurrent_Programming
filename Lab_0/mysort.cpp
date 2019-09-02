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
*@description:
*
*@param:
*
*@return:
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
*@description:
*
*@param:
*
*@return:
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
*@func:		myMerge
*
*@description:  merges vector after sorting
*
*@param:
*
*@return:void
*/
void myMerge(vector<int> &g1,int l, int m, int r)
{
	int i,j,k;
	int n1 = m - l + 1;
	int n2 =  r - m;
	vector<int> L;
	vector<int> R;

	for(i=0;i<n1;i++)
	{
		L.push_back(g1[l+i]);
	}

	for(j=0;j<n2;j++)
        {
                R.push_back(g1[m+1+j]);
        }

	i=0;/*Index of the first subarray*/
	j=0;/*Index of the second subbarray*/
	k=l;/*Index of the merged subarray*/
	while(i < n1 && j < n2)
	{
		if(L[i] < R[j])
		{
			g1[k]=L[i];
			i++;
		}

		else
		{
			g1[k]=R[j];
			j++;
		}

	k++;

	}

	while (i < n1)
	{
		g1[k] = L[i];

		i++;
		k++;
	}

	while (j < n2)
        {
                g1[k] = R[j];
                j++;
                k++;
        }


}

/**
*@func: 	myMergeSort
*
*@description:
*
*@param:
*
*@return:void
*/

void myMergeSort(vector<int> &g1, int l, int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		myMergeSort(g1,l,m);
		myMergeSort(g1,m+1,r);
		myMerge(g1,l,m,r);
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

int myPartition(vector<int> &g1,int l, int r)
{

	int i=l+1;
	int piv=g1[l];

	for(int j = l + 1;j <= r;j++)
	{
	/**
	rearrange the array by putting elements which are less than pivot
       	on one side and which are greater that on other.
	*/
		if(g1[j] < piv)
		{

			int temp = g1[i];
			g1[i] = g1[j];
			g1[j] = temp;

			i++;
		}

	}
	 int temp = g1[l];
         g1[l]=g1[i-1];
         g1[i-1]=temp;

	return i-1;
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

void myQuickSort(vector<int> &g1,int l, int r)
{

	int pivot_index=myPartition(g1 , l , r);

	myQuickSort(g1, l, pivot_index - 1);
	myQuickSort(g1, pivot_index + 1, r);

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
		/*Printing unsorted vector from reading a file*/
		std::cout << "Printing out the unsorted vector" << endl;
		myPrint(g1);

		#ifdef MERGESORT
		/*Sorting the vector using mergesort*/
		myMergeSort(g1,0,g1.size()-1);
		#endif /*MERGESORT*/

		#ifdef QUICKSORT
		/*Sorting the vector using quicksort*/
		myQuickSort(g1,0,g1.size()-1);
		#endif /*QUICKSORT*/

		#ifdef PRINT
		/*Now, printing the sorted vector*/
		std::cout << "Now, printing out the sorted vector" << endl;
		myPrint(g1);
		#endif /*PRINT*/

		myWriteFile(argv[2], g1);
		return 0;
	}
}






