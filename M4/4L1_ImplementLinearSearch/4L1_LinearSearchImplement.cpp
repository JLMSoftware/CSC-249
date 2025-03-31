/*
CSC-249
4L1_LinearSearch
Justin Mitchell
3/31/25
*/

#include <iostream>
using namespace std;

LinearSearch( int numbers[], int numbersSize, int key){

    int i = 0;

    for (i = 0; i < numbersSize; i++){
            if(numbers[i] == key){
                return i;
            }



    }
    return -1;
}




int main()
{

    int numbers [] = {2, 4, 7, 10, 11, 32, 45, 87};
    int NUMBERS_SIZE = 8;
    int i = 0;
    int key = 0;
    int keyIndex = 0;

    cout << "NUMBERS: ";
    for(i =0; i < NUMBERS_SIZE; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Please enter a value to search for: ";
    cin >> key;

    keyIndex = LinearSearch(numbers, NUMBERS_SIZE, key);

    if (keyIndex == -1){
        cout << key << " was not found." << endl;

    } else {
        cout << "Found " << key << " at index " << keyIndex << ".";

    }






}
