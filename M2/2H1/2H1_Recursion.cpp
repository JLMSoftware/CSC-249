/*
CSC 249
2H1 Recursive Functions
Justin Mitchell
3/2/25
*/


#include <iostream>
using namespace std;








//Prototypes
int BinarySearchI(int numbers[], int numbersSize, int key);
int BinarySearchR(int numbers[], int low, int high, int key);
int FiboNumR(int termIndex);
int FiboNumI(int termIndex);











int main()
{
    cout << "This is the iterative Binary Search.\n";
//Section for Doing iterative Binary Search
    int numbers[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Enter an integer value: ";
    int key = 7;
    cin >> key;

    int keyIndex = BinarySearchI(numbers, numbersSize, key);
    if (keyIndex == -1) {
      cout << key << " was not found." << endl;
    }
    else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
    }

//Section for doing recursive binary search with the same numbers as the binary
    cout << "This is the recursive Binary Search.\n";
    keyIndex = BinarySearchR(numbers, 0, numbersSize - 1, key);

    if (keyIndex == -1) {
      cout << key << " was not found." << endl;
    }
    else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
    }





    cout << "\nFibonacci Sequence Section!\n";


 //Does the fibonacci sequence and shows user their number from a given term index using both iterative and recursive forms of the same function.
    cout << "Please enter the index for a Fibonacci sequence number.\n";
    int indexNumber;
    cin >> indexNumber;
    int fNumber1 = FiboNumR(indexNumber);
    int fNumber2 = FiboNumI(indexNumber);
    cout << "Your recursive Fibonacci number is: " <<fNumber1 << endl;
    cout << "Your iterative Fibonacci number is also: " <<fNumber2 << endl;


}



int BinarySearchI(int numbers[], int numbersSize, int key){
   //Reused from 2L2
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


int BinarySearchR(int numbers[], int low, int high, int key){
    // Base case: if the range is invalid
    if (low > high) {
        return -1;  // Element not found
    }

    // Calculate middle index
    int mid = low + (high - low) / 2;

    // Check if the key matches the middle element
    if (numbers[mid] == key) {
        return mid;  // Found the element, return its index
    }

    // If the key is greater, search in the right half
    if (numbers[mid] < key) {
        return BinarySearchR(numbers, mid + 1, high, key);
    }
    // If the key is smaller, search in the left half
    return BinarySearchR(numbers, low, mid - 1, key);

}

int FiboNumR(int termIndex){
    if(termIndex == 0){
        return 0; //Returns 0 for 0
    } else if (termIndex == 1){
        return 1; // Returns 1 for 1
    } else {
        //returns the fibonacci number for the last two terms added together.
        return FiboNumR(termIndex - 1) + FiboNumR(termIndex - 2);

    }
}

int FiboNumI(int termIndex){

   //Use cases for when the terms are 1, 0, and less than 0.
    if (termIndex <= 0) {
        return 0;
    }
    if (termIndex == 1) {
        return 1;
    }


    //starts out with the current term being 1 and the previous being two
    int prev = 0;
    int current = 1;

    //starts loop at index 2 and goes until loop reaches termIndex
    for (int i = 2; i <= termIndex; ++i) {
        //Calculates the next term
        int next = prev + current;
        //Moves forward in the sequences one term.
        prev = current;
        current = next;
    }
    //returns the term
    return current;

}




