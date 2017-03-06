/*
   COPYRIGHT (C) 2016 Nicholas Gallimore (nfg3) All rights reserved.
   CSII assignment 5 A
   Author.  Nicholas Gallimore
            nfg3@zips.uakron.edu
   Version. 1.01 09.09.2017

*/
// Implementation file for the CharList class

#include "charList.hpp"
#include <iostream>

// default constructor
CharList::CharList()
{
   head = nullptr;
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************

void CharList::displayList() const
{
   Node *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;
   short count = 0;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      std::cout << "[" << nodePtr->value << "] -> ";
      ++count;
      // Move to the next node.
      nodePtr = nodePtr->next;
      if (count % 10 == 0) {
        std::cout << std::endl;
        count = 0;
      }
   }
   std::cout << std::endl;
}

void CharList::clear() {
   Node *tmp;
   while (head) {
      tmp = head;
      head = head->next;
      delete tmp;
   }
}

// sorts the list
void CharList::sort() {
   Node* headCopy, *tmp;
   headCopy = head;
   head = nullptr;

   tmp = headCopy;

   while (tmp) {
      insertNode(tmp->value);
      tmp = tmp->next;
   }
   tmp = head;
   head = headCopy;
   clear();
   head = tmp;
}

// appends node to end of list
bool CharList::appendNode(char value)
{
   try {
      Node* node = new Node();
      node->value = value;
      node->next = nullptr;
      if (head == nullptr) {
         // empty list, just simply assign the new node's address to head
         head = node;
         
         return true;
      }
      else {
         // not empty list
         // find the last node
         Node* tmp = head;
         while (tmp->next != nullptr) {
            tmp = tmp-> next;
         }
         tmp->next = node;
      }
      return true;
   } catch(...) {
      return false;
   }
}

bool CharList::insertNode(char value) {
   try {
      Node* tmp, *prev;
      // create a new node
      Node* newNode = new Node();
      newNode->value = value;
      newNode->next = nullptr;

      // if list is empty
      if (head == nullptr) {
         head = newNode;
         newNode-> next = nullptr;
      }
      // searching the existing node value until the node's value greater than or equal to value
      tmp = head;
      prev = nullptr;
      while (tmp) {
         if (tmp->value >= value) {
            // insert the value before the node tmp and after the node prev
            if (prev == nullptr) {
               newNode->next = head;
               head = newNode;
            }
            else {
               newNode->next = tmp;
               prev->next = newNode;
            }
            return true; // after insertion
         }
         prev = tmp;
         tmp = tmp->next;
      }

      // at this point, there is no value in the list greater than or equal to value
      // it means we insert to end at this point ,
      // prev pointing to the last node
      prev->next = newNode;
      return true;

   }
   catch (...) 
   {
      return false;
   }
}

bool CharList::deleteNode(char value) {
   Node* tmp, *prev;
   tmp = head;
   prev = nullptr;
   while (tmp) {
      if (tmp->value == value) {
         // deletion
         if (prev == nullptr) {
            // it is the first element
            head = tmp->next;
            delete tmp;
         }
         else {
            prev->next = tmp->next;
            delete tmp;
         }
         return true;
      }
      prev = tmp;
      tmp = tmp->next;
   }
   return false;
}



// searches node
bool CharList::search(char value) {
   Node* tmp;
   tmp = head;
   while (tmp) {
      if (tmp->value == value) {
         return true;
      }
      tmp = tmp->next;
   }
   return false;
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************

CharList::~CharList()
{
   Node *nodePtr;   // To traverse the list
   Node *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}
