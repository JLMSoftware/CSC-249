/*
CSC-249
3L1 - The Stack
Justin Mitchell
3/12/25
*/
#include <iostream>

using namespace std;

class ArrayStack {
private:
   int allocationSize;
   int* array;
   int length;
   int maxLength;

   void Resize() {
      // Allocate new array and copy existing items
      int newSize = allocationSize * 2;
      int* newArray = new int[newSize];
      for (int i = 0; i < length; i++) {
         newArray[i] = array[i];
      }

      // Free old array and assign new
      delete[] array;
      array = newArray;
      allocationSize = newSize;
   }

public:
   ArrayStack(int optionalMaxLength = -1) {
      allocationSize = 1;
      array = new int[allocationSize];
      length = 0;
      maxLength = optionalMaxLength;
   }

   virtual ~ArrayStack() {
      delete[] array;
   }

   int GetLength() const {
      return length;
   }

   int GetMaxLength() const {
      return maxLength;
   }

   bool Push(int item) {
      // If at max length, return false
      if (length == maxLength) {
         return false;
      }

      // Resize if length equals allocation size
      if (length == allocationSize) {
         Resize();
      }

      // Push the item and return true
      array[length] = item;
      length++;
      return true;
   }

   int Pop() {
      length--;
      return array[length];
   }
};



















int main()
{
    ArrayStack unboundedStack;

    cout << "Adding values 1 through 10 into the stack.\n";
    for (int i = 1; i <= 10; i++){
        unboundedStack.Push(i);

    }

    cout << "Popping thrice." << endl;
    for (int i = 0; i < 3; i++){
        unboundedStack.Pop();
    }

    cout << "Adding some values to top of stack." << endl;
    unboundedStack.Push(420);
    unboundedStack.Push(32);
    unboundedStack.Push(255);



    cout << "The final stack looks like the following:\n";
    while (unboundedStack.GetLength() > 0) {
      cout << unboundedStack.Pop() << ", ";
   }

}
