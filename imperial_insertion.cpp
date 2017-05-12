/*

INSERTION SORT with random numbers of n, where n = 1000, 10000, 100000

Implemented in C++ by JOSEPH MARVIN R. IMPERIAL, BSCS 3A 
In compliance for the final project for Design and Analysis of Algorithm (DAA)
Date Submitted: March 27, 2017

Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. (Wikipedia)

*/

//HEADERS
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream> //library needed to write to files
#include <ctime>
#include <ctime>

using namespace std;

void insertion(int);


main()
{
	//seed
	srand (time(NULL));
	
	//clock variables
	int start, stop;
	
	//starts the clock to measure speed
	start=clock();

	//sorting begins
	cout << "Sorting 1000 random numbers...";
	insertion(1000);
	cout << "Done!";
	
	//stops clock
	stop=clock();
	
	//calculates and displays time taken by program
	cout << "\nExecution time of n = 1000: " << (stop-start)/double(CLOCKS_PER_SEC) << " seconds\n";
	
	start=clock();
	cout << "\nSorting 10000 random numbers...";
	insertion(10000);
	cout << "Done!";
	stop=clock();
	cout << "\nExecution time of n = 10000: " << (stop-start)/double(CLOCKS_PER_SEC) << " seconds\n";
	
	start=clock();
	cout << "\nSorting 100000 random numbers...";
	insertion(100000);
	cout << "Done!";
	stop=clock();
	cout << "\nExecution time of n = 100000: " << (stop-start)/double(CLOCKS_PER_SEC) << " seconds\n";
	
}



// INSERTION SORT FUNCTION
void insertion(int n){
	
	//Opens file for writing/appending
	ofstream insertionFile;
	insertionFile.open("insertionOutput.txt",std::ofstream::app);
	
	// File creation
	insertionFile << "Insertion Sort, n = " << n;
	insertionFile << "\n\n";
	
	// Variable and array declaration
	int array[n];
	int x,i,j,tobs;
	
	// Fills the array with random numbers of range n
	for(x=0; x<n; x++){
		array[x] = rand() % n + 1;
	}
	
	// Sorting starts, n-1 to exclude the start element
	for(i=1;i<=n-1;i++)
    {
    	// tobs acquires value of first element
        tobs=array[i];
        j=i-1;
 
 		// Condition 1: checks is tobs is less than the next element
 		// Condition 2: checks if position is greater/equal than 0
        while((tobs < array[j]) && (j >= 0))
        {
        	//finds the correct position 
            array[j+1]=array[j];  
            j=j-1;
        }
 
 		// tobs will be inserted at correct position
        array[j+1]=tobs;    
    }
    

	for(x=0; x<n; x++){
		//writing sorted array to file
		insertionFile << array[x] << " ";
	}
	
	insertionFile << "\n\n";
}


