// =================================================================
//
// File: my_list.h
// Author: Arturo Lopez Garcia - A01276405
// Date: 02/12/2023
// 
// =================================================================
#ifndef MY_LIST_H
#define MY_LIST_H
#include <string>
#include <sstream>
#include "custom_exception.h"
#include "my_header.h"

template <class T> class MyList;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class MyNode {
private:
	MyNode(T);
	MyNode(T, MyNode<T>*);

	T	    data;
	MyNode<T> *next;

	friend class MyList<T>;
};

// =================================================================
// Constructor. Initializes the data of the node. The variable next
// is initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
MyNode<T>::MyNode(T val) : data(val), next(nullptr) {
}

// =================================================================
// Constructor. Initializes both instance variables.
//
// @param val, stored value in the node.
// @param nxt, the next node.
// =================================================================
template <class T>
MyNode<T>::MyNode(T val, MyNode<T>* nxt) : data(val), next(nxt) {
}

// =================================================================
// Definition of the MyList class
// =================================================================
template <class T>
class MyList {
private:
	MyNode<T> *head;
	uint 	listSize;

public:
	MyList();
	~MyList();

	uint  getSize() const;
	bool isEmpty() const;
	bool contains(T) const;
	void clearList();
	std::string displayList() const;

	T    getFront() const;
	T    getBack() const;
	T    getElementAt(uint) const;

	void addFront(T);
	void addBack(T);
	void insertAt(T, uint);

	T    removeFront();
	T    removeBack();
	T    removeAt(uint);

	long int  findIndex(T) const;
};

// =================================================================
// Constructor. Initializes both instance variables to zero.
// =================================================================
template <class T>
MyList<T>::MyList() : head(nullptr), listSize(0) {
}

// =================================================================
// Destructor. Remove all items from the list.
// =================================================================
template <class T>
MyList<T>::~MyList() {
	clearList();
}

// =================================================================
// Returns if the list is empty or not
//
// @returns true if the list is empty, false otherwise.
// =================================================================
template <class T>
bool MyList<T>::isEmpty() const {
	return (head == nullptr);
}

// =================================================================
// Returns the number of items in the list.
//
// @returns listSize, the number of items in the list.
// =================================================================
template <class T>
uint MyList<T>::getSize() const {
	return listSize;
}

// =================================================================
// Determines if an item is in the list.
//
// @returns true if val is in the list, false otherwise
// =================================================================
template <class T>
bool MyList<T>::contains(T val) const {
	MyNode<T> *ptr;

	ptr = head;
	while (ptr != nullptr) {
		if(ptr->data == val) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

// =================================================================
// Remove all items from the list.
// =================================================================
template <class T>
void MyList<T>::clearList() {
	MyNode<T> *ptr, *temp;

	ptr = head;
	while (ptr != nullptr){
		temp = ptr->next;
		delete ptr;
		ptr = temp;
	}

	head = nullptr;
	listSize = 0;
}

// =================================================================
// String representation of the elements in the list.
//
// @returns a string containing all the elements of the list.
// =================================================================
template <class T>
std::string MyList<T>::displayList() const {
	std::stringstream aux;
	MyNode<T> *ptr;

	ptr = head;
	aux << "[";
	while (ptr != nullptr) {
		aux << ptr->data;
		if (ptr->next != nullptr) {
			aux << ", ";
		}
		ptr = ptr->next;
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Returns the first item in the list.
//
// @returns the object T at the beginning of the list.
// @throws NoSuchElement, if the list is empty.
// =================================================================
template <class T>
T MyList<T>::getFront() const {
	if (isEmpty()) {
		throw NoSuchElement();
	}

	return head->data;
}

// =================================================================
// Returns the last item in the list.
//
// @returns the object T at the end of the list.
// @throws NoSuchElement, if the list is empty.
// =================================================================
template <class T>
T MyList<T>::getBack() const {
	MyNode<T> *ptr;

	if (isEmpty()) {
		throw NoSuchElement();
	}

	ptr = head;
	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}
	return ptr->data;
}

// =================================================================
// Returns the element that is in the position indicated by index.
//
// @returns the element in index
// @throws IndexOutOfBounds, if index >= listSize.
// @Complexity	O(n)
// =================================================================
template <class T>
T MyList<T>::getElementAt(uint index) const {
	if(index >= listSize){
    	throw IndexOutOfBounds();
	}

	MyNode<T>* temp = head; 

    for(int i = 0; i < index; i++){
        temp = temp->next;
    }

    return temp->data;
}

// =================================================================
// Add an item to the beginning of the list. Increase the listSize.
// =================================================================
template <class T>
void MyList<T>::addFront(T val) {
	MyNode<T> *newNode;

	newNode = new MyNode<T>(val);
	newNode->next = head;
	head = newNode;
	listSize++;
}

// =================================================================
// Add an item to the end of the list. Increase the listSize.
// =================================================================
template <class T>
void MyList<T>::addBack(T val) {
	MyNode<T> *ptr, *newNode;

	if (isEmpty()) {
		addFront(val);
		return;
	}

	ptr = head;
	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}

	newNode = new MyNode<T>(val);
	newNode->next = ptr->next;
	ptr->next = newNode;
	listSize++;
}

// =================================================================
// Add an element in index (0 <= index <= listSize). The element that
// was in that position is shifted to the right.
//
// @throws IndexOutOfBounds, if index > listSize.
// @Complexity	O(n)
// =================================================================
template <class T>
void MyList<T>::insertAt(T val, uint index) {
	MyNode<T>* newNode = new MyNode<T>(val);

    if(index == 0){
		newNode->next = head;
		head = newNode;
	}else{
		MyNode<T>* temp = head;
		for(int i = 0; i < index - 1; i++){
			if(temp == nullptr){
                throw IndexOutOfBounds();
            }
			temp = temp->next;
		}
		newNode->next =		temp->next;
		temp->next = newNode;
	}

    listSize++;
}

// =================================================================
// Delete the item at the beginning of the list.
//
// @returns the element that was at the beginning of the list.
// @throws NoSuchElement if the list is empty
// =================================================================
template <class T>
T MyList<T>::removeFront() {
	T val;
	MyNode<T> *temp;

	if (isEmpty()) {
		throw NoSuchElement();
	}

	temp = head;

	head = temp->next;
	val = temp->data;

	delete temp;
	listSize--;
	return val;
}

// =================================================================
// Delete the item at the end of the list.
//
// @returns the element that was at the end of the list.
// @throws NoSuchElement if the list is empty
// =================================================================
template <class T>
T MyList<T>::removeBack() {
	MyNode<T> *ptr, *prev;
	T val;

	if (isEmpty()) {
		throw NoSuchElement();
	}

	if (listSize == 1) {
		return removeFront();
	}

	prev = nullptr;
	ptr = head;
	while (ptr->next != nullptr) {
		prev = ptr;
		ptr = ptr->next;
	}

	prev->next = ptr->next;
	val = ptr->data;

	delete ptr;
	listSize--;

	return val;
}

// =================================================================
// Delete the element found in index (0 <= index < listSize).
//
// @returns the element that was in index.
// @throws IndexOutOfBounds, if index >= listSize.
// @Complexity	O(n)
// =================================================================
template <class T>
T MyList<T>::removeAt(uint index) {
	if(index >= listSize){
    	throw IndexOutOfBounds();
	}

	T removedVal;

	if(index == 0){
		MyNode<T>* temp = head;
		head = head->next;
		removedVal = temp->data;
		delete temp;
	}else{
		MyNode<T>* temp = head;
		for(int i = 0; i < index - 1; i++){
			temp = temp->next;
		}
		MyNode<T>* removedNode = temp->next;
		temp->next = removedNode->next;
		removedVal = removedNode->data;
		delete removedNode;
	}

	listSize--;
	return removedVal;
}

// =================================================================
// Returns the position of an item in the list.
//
// @returns the position of an item in the list, -1 otherwise.
// @throws IndexOutOfBounds, if index >= listSize.
// @Complexity	O(n)
// =================================================================
template <class T>
long int MyList<T>::findIndex(T val) const {
	MyNode<T>* temp = head;
	int index = 0;
	for(int i = 0; i < listSize; i++){
		if(temp->data == val){
			return index;
		}
		temp = temp->next;
		index++;
	}

	return -1;
}

#endif /* MY_LIST_H */

