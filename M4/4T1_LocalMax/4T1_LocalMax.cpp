/*
CSC-249
4T1_LocalMax
Justin Mitchell
3/28/25
*/


#include <iostream>

using namespace std;

int main()
{

// Initialize the list of numbers and set the currentMax to the first value in the list
    int SIZE = 8;
    int valueList[SIZE] = {95,78,73,9,43,17,98,43};
    int currentMax = valueList[0];

// For loop that finds the local maxima
     for (int i = 0; i < SIZE; i++){

        if (valueList[i] > currentMax){
                currentMax = valueList[i];
        }


    }
//Print local max
     cout << "The local maxima is:  " << currentMax;

}
