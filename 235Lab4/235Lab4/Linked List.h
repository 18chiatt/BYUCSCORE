#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include<string>
#include<ostream>
#include<sstream>
using namespace std;
template <typename T>
class LinkedList { 
public:
	struct Node {
		T data;
		Node* next;
		Node(T d, Node * n) : data(d), next(n) {};
		Node(T d) {
			this->data = d;
			next = NULL;
		}
	};
	Node * head;

	LinkedList() { head = NULL; }
	~LinkedList() {}

	void push_front(T value) {
		head = new Node(value, head);
	}

	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		else {
			return false;
		}

	}

	string toString(void) {
		ostringstream output;
		Node * myPointer = head;

		while (myPointer != NULL) {
			output << " " << myPointer->data;
			myPointer = myPointer->next;
		}
		return output.str();

	}

	friend ostream& operator<< (ostream& os, LinkedList& SNAP) {

		return os << SNAP.toString();
	}

	void clear(void) {
		while (head->next != NULL) {
			Node * tempPtr = head->next;
			delete head;
			head = tempPtr;

		}
		delete head;
		head = NULL;

	}
	void deepClear(void) {
		delete head;
	}


	class Iterator {
	public:
		Node* iNode;
	public:
		Iterator(Node * head) : iNode(head) {}
		bool operator!=(Iterator toCompare) {
			return iNode != toCompare.iNode;
		}
		Iterator& operator++ () {
			
			
			iNode = iNode->next; 
			return *this;
		}
		T& operator*() {
			return iNode->data;
		}
		Node* getHead() {
			return iNode;
		}
		void setHead(Node* toSet) {
			iNode = toSet;
		}
		bool hasNext(void) {
			if (iNode == nullptr) {
				return false;
			}
			else {
				return true;
			}
		}

	};

	Iterator begin(void) {
		return LinkedList::Iterator(head);

	}
	Iterator end(void) {
		return LinkedList::Iterator(NULL);
	}

	Iterator find(Iterator first, Iterator last, const T& value) {
		while (first != last) {
			if (*first == value) {
				return first;
			}
			else {
				++first;
			}
		}

		Iterator toReturn(NULL);
		return toReturn;

	}

	Iterator insert(Iterator position, const T& value) {
		Node* ptr = position.getHead();
		T tempData = ptr->data;
		Node* tempNode = ptr->next;
		ptr->data = value;




		ptr->next = new Node(tempData, tempNode);

		return position;
	}

	Iterator insertAfter(Iterator& position, const T& value) {
		LinkedList<T>::Iterator tempIter= position;
		if (!(++tempIter != NULL)) {
			Node * toModify = position.getHead();
			T toInsert = value;
			toModify->next = new Node(toInsert);
			return position;
		}

		++position;
		insert(position, value);
		return position;

	}
	Iterator Erase(Iterator& begin, Iterator& toErase) {
		Iterator tempIter = toErase;
		++tempIter;
		Node * toErasePtr = toErase.getHead();
		Node * nextToErasePtr = tempIter.getHead();

		if (tempIter.hasNext()) {
			toErasePtr->data = nextToErasePtr->data;
			toErasePtr->next = nextToErasePtr->next;
			delete nextToErasePtr;
			
		}
		else {
			Iterator iter = begin;
			Iterator oneAhead = iter;
			++oneAhead;
			while (oneAhead != toErase) {
				++begin;
				++oneAhead;
			}
			++iter;
			//assume oneAhead = toErase
			//assume iter = one before toErase
			Node * toEdit = iter.getHead();
			toEdit->next = nullptr;
			delete oneAhead.getHead();

			
		}

		
		return toErase;
	}

	Iterator replace(Iterator start, Iterator end, T oldValue, T newValue) {

		while (start != end) {
			if (*start == oldValue) {
				*start = newValue;
			}
			++start;
		}
		return start;

	}

	




};

#endif // !LINKED_LIST_H
