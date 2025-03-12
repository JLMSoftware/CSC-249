
/*
CSC-249
3T1 -Single Linked List
Justin Mitchell
3/6/25
*/


#include <iostream>
using namespace std;

//Node Class
class Node {
public:
   int data;
   Node* next;

   Node(int initialData) {
      data = initialData;
      next = nullptr;
   }
};




//LinkedList class
class LinkedList {
private:
   Node* head;
   Node* tail;

public:
   LinkedList() {
      head = nullptr;
      tail = nullptr;
   }

   virtual ~LinkedList() {
      Node* currentNode = head;
      while (currentNode) {
         Node* toBeDeleted = currentNode;
         currentNode = currentNode->next;
         delete toBeDeleted;
      }
   }

   void Append(Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         tail->next = newNode;
         tail = newNode;
      }
   }

   void Prepend(Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         newNode->next = head;
         head = newNode;
      }
   }

   void PrintList(std::ostream& printStream, const std::string& separator = ", ") {
      Node* node = head;
      if (node) {
          // Head node is not preceded by separator
          printStream << node->data;
          node = node->next;
      }
      while (node) {
         printStream << separator << node->data;
         node = node->next;
      }
      printStream << std::endl;
   }


   void InsertAfter(Node* currentNode, Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else if (currentNode == tail) {
         tail->next = newNode;
         tail = newNode;
      }
      else {
         newNode->next = currentNode->next;
         currentNode->next = newNode;
      }
   }

   void RemoveAfter(Node* currentNode) {
      if (currentNode == nullptr && head) {
         // Special case: remove head
         Node* nodeBeingRemoved = head;
         head = head->next;
         delete nodeBeingRemoved;

         if (head == nullptr) {
             // Last item was removed
             tail = nullptr;
         }
      }
      else if (currentNode->next) {
         Node* nodeBeingRemoved = currentNode->next;
         Node* succeedingNode = currentNode->next->next;
         currentNode->next = succeedingNode;
         delete nodeBeingRemoved;
         if (succeedingNode == nullptr) {
            // Remove tail
            tail = currentNode;
         }
      }
   }
};





int main()
{
    LinkedList numList;
    Node* nodeA = new Node(11);
    Node* nodeB = new Node(22);
    Node* nodeC = new Node(33);
    Node* nodeD = new Node(44);
    Node* nodeE = new Node(55);
    Node* nodeF = new Node(66);

    //adds nodes in just some order
    numList.Append(nodeB);
    numList.Append(nodeC);
    numList.Append(nodeE);
    numList.Prepend(nodeD);
    numList.InsertAfter(nodeC, nodeA);
    numList.InsertAfter(nodeE, nodeF);

    cout << "List after adding nodes: ";
    numList.PrintList(cout);

    numList.RemoveAfter(nullptr);
    numList.RemoveAfter(nodeE);
    numList.RemoveAfter(nodeB);
    cout << "List after removing Head, Center, and Tail nodes: ";
    numList.PrintList(cout);

}
