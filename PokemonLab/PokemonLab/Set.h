#ifndef SET_H
#define SET_H
#include "SetInterface.h"
#include"BinarySearchTree.h"

template <typename T>
class Set : public SetInterface <T> {
private:
	BinarySearchTree<T> theTree;

public:
	bool insert(const T& item) {
		if (theTree.findNode(item) == true) {
			return false;
		}

		theTree.addNode(item);
		return true;
	}

	void clear() {
		theTree.clearTree();
	}

	size_t size() const {
		size_t toReturn = theTree.getNumNodes();
		return toReturn;

	}

	size_t count(const T& item) {
		if (theTree.findNode(item) == true) {
			return 1;
		}
		return 0;

	}

	std::string toString() const {
		return theTree.toString();
	}

	friend ostream& operator<< (ostream& os, Set<T>& theTree) {
		os << theTree.toString();
		return os;

	}



};



#endif // !SET_H

