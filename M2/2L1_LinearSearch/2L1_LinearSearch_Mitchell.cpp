/*
CSC 249
2L1 Linear Search
Justin Mitchell
2/23/25
*/

#include <iostream>

using namespace std;

int LinearSearch(string numbers[], int numbersSize, string key){
    for (int i = 0; i < numbersSize; i++){
        if (numbers[i] == key){
            return i;
        }
    }
    return -1;

}




int main()
{
    string numbers[] = {"plane", "train", "brain", "mane", "cane", "octane"};
    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Words: [" << numbers[0];

    for (int i =1; i < numbersSize; i++) {
        cout << ", " << numbers[i];
    }
    cout << "]" << endl;

    cout << "Enter a string for key in ALL LOWERCASE!: ";
    string key = "";
    cin >> key;

    int keyIndex = LinearSearch(numbers, numbersSize, key);

    if (keyIndex == -1) {
      cout << key << " was not found." << endl;
    } else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
    }

}
