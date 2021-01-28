#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include"Linked List Interface.h"
#include<ostream>
#include<sstream>
#include<string>
using namespace std;


template <typename T>
class LinkedList : public LinkedListInterface<T> {
public:
	T data;
	LinkedList* next;

	class Iterator {
	public:
		LinkedList * iNode;
		~Iterator() {}
		bool operator!=(const Iterator& toCompare) const { return iNode != toCompare.iNode; }
		Iterator& operator++() { iNode = iNode->next; return *this; }
		T& operator*() const { return iNode->data; }
		Iterator(LinkedList * head) : iNode(head) {}
	};

	Iterator begin() {
		LinkedList<T>::Iterator toReturn (this);
		return toReturn;
	}
	Iterator end() {
		LinkedList<T>::Iterator toReturn(NULL);
		return toReturn;

	}
	




	LinkedList(T data) : data(data), next(nullptr) {}
	LinkedList(T data, LinkedList* next) : data(data), next(next) {}
	LinkedList() {
		this->next = nullptr;
		this->data = NULL;
	}


	size_t size(void)  {
		int number = 1;
		LinkedList<T> * tempPtr = this;
		while (tempPtr->next != nullptr) {
			tempPtr = tempPtr->next;
			number++;

		}

		return number;
	}


	bool empty(void) const{
		if (next == nullptr) {
			return true;
		}
		else {
			return false;
		}

	}
	void push_front(const T& value) {
		
		
		next = new LinkedList<T>(value, next);

	}

	string toString(void) {
		ostringstream output;
		LinkedList<T> * tempPtr = this;

		

		while (tempPtr != NULL) {
			output << tempPtr->data;
			if (tempPtr->next != NULL) {
				output << " ";
			}
			tempPtr = tempPtr->next;
		}		


		return output.str();
	}

	void pop_front(void) {
		
			
		T toStoreInData = next->data;
		LinkedList<T> * theNextPointer = next->next;
		delete next;
		data = toStoreInData;
		next = theNextPointer;
			
		

		
		

		

		
	}
	void clear(void) { //clear list
		while (&next != nullptr) {
			LinkedList<T> * toDelete = this;
			next = next->next;
			delete toDelete; //avoid memory leaks
			
		}
	
		

		
	}

	friend ostream& operator<< (ostream& os, LinkedList<T>& SNAP) {

		return os << SNAP.toString();
	}

	T& front(void) {
		
		
		//this function is protected behind a try catch code block so I can just return without checks

		return data;


		
	}

	void remove(const T& value) { //remove a value that is given in argument

		LinkedList<T> * currentlyScanning = this;
		LinkedList<T> * previouslyScanned = this;
		LinkedList<T> * tempPtr = next;

		while (currentlyScanning->next != nullptr) {

			
			if (currentlyScanning->data == value) {
				
				
				
				previouslyScanned->next = currentlyScanning->next;
				tempPtr = currentlyScanning->next;
				delete currentlyScanning;
				

			}
			else {
				previouslyScanned = currentlyScanning;
				tempPtr = currentlyScanning->next;
			}

			;
			currentlyScanning = tempPtr;
		}

		if (currentlyScanning->data == value) {
			
			delete currentlyScanning;
			previouslyScanned->next = nullptr;
		}

	}

	

	void reverse(void) { //REVERSE function
		

		LinkedList<T> * nextToWorkOn = this->next;
		LinkedList<T> * previous = this;
		this->next->next = nullptr;

		while (nextToWorkOn->next != nullptr) {
			LinkedList<T> * tempPtr = nextToWorkOn->next;
			nextToWorkOn->next = previous;
			previous = nextToWorkOn;
			nextToWorkOn = tempPtr;


		}

		nextToWorkOn->next = previous;

		next = nextToWorkOn;

		

	
		
		
	}



};




#endif // !LINKED_LIST_H
