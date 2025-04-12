/*
CSC-249
4H1 - Binary Search Gold Attempt
Justin Mitchell
4/12/25
*/




#include <iostream>
using namespace std;
//Binary Search Example
int BinarySearch(int* numbers, int numbersSize, int key) {

   int low = 0;
   int high = numbersSize - 1;

   while (high >= low) {

      int mid = (high + low) / 2;


      if (numbers[mid] < key) {
         low = mid + 1;
      }
      else if (numbers[mid] > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }

   return -1;
}
//The main for the binary search demo from textbook.
int searchDemo() {
   int numbers[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
   cout << "NUMBERS: [" << numbers[0];
   for (int i = 1; i < numbersSize; i++) {
      cout << ", " << numbers[i];
   }
   cout << "]" << endl;

   cout << "Enter an integer value: ";
   int key = 0;
   cin >> key;

   int keyIndex = BinarySearch(numbers, numbersSize, key);
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
   }
}


int numGuess(){


    string userReply = "";
    bool isNumCorrect = false;
    int low = 0;
    int high = 100;
    int counter = 0;

    while (!isNumCorrect){
        // Checks if guesses has hit 5.
        if (counter == 5){
            cout << "OUT OF GUESSES. :(";
            isNumCorrect = true;
            break;
        }


        //Guesses at mid point
        int guess = (high + low) / 2;
        cout << "Is your number: " << guess << endl;

        cout << "Please enter '<, >, or =' to indicate less, greater, and equal to respectively. : ";
        cin >> userReply;

        //Binary Search Algorithm with the correct guess and an exception handling else.
        if (userReply == ">"){
            cout << "Greater" << endl;
            low = guess + 1;
            counter++;
        } else if (userReply == "<"){

            cout << "Less" << endl;
            high = guess - 1;
            counter++;

        } else if (userReply == "="){
            cout << "Equal" << endl;
            isNumCorrect = true;
        } else {
            cout << endl << "Try again." << endl;

        }


    }





}

int main(){
    //Main Menu.
    string selector = "";
    bool isRunning = true;

    while (isRunning){
        cout << "1. Binary Search Demo" << endl;
        cout << "2. Binary Guess the Number Game" << endl;
        cout << "Please type a number to make a selection or enter 'q' to quit: ";

        cin >> selector;
        if (selector == "q"){
            isRunning = false;
        } else if (selector == "1"){
            searchDemo();

        } else if (selector == "2"){
            numGuess();
        } else {
            cout << endl << "Try again." << endl;

        }


        cout << endl;


    }






}













