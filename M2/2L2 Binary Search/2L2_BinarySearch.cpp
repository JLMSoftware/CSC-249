
/*
CSC 249
2L2 Binary Search
Justin Mitchell
2/23/25
*/


#include <iostream>
using namespace std;

int BinarySearch(float numbers[], int numbersSize, float key){
    int mid = 0;
    int low = 0;
    int high = numbersSize - 1;

    while (high >= low){
        mid = (high + low) /2;
        if (numbers[mid] < key) {
            low = mid + 1;
        } else if (numbers[mid] > key ){

            high = mid - 1;
        } else {

            return mid;
        }


    }

    return -1;
}


int main()
{
    float numbers[8] = {0.25, 0.44, 0.7, 1.0, 1.24, 3.2, 4.5, 8.7};
    int NUMBERS_SIZE = 8;
    int i = 0;
    float key = 0;
    int keyIndex = 0;

    cout << "Numbers: ";
    for (i = 0; i < NUMBERS_SIZE; ++i){
        cout << numbers[i] << " ";
    }

    cout << endl;

    cout << "Enter a value: ";
    cin >> key;

    keyIndex = BinarySearch(numbers, NUMBERS_SIZE, key);

    if (keyIndex == -1){
        cout << key << " was not found." << endl;
    } else {

        cout << "Found " << key << " at index " << keyIndex << ".";
    }

}
