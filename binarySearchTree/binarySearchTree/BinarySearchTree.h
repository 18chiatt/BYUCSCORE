#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include<iostream>
#include<string>
#include<sstream>
#include<stdbool.h>
#include"Node.h"
#include "BSTInterface.h"

using namespace std;




template<typename T>
class BinarySearchTree : public BSTInterface <T>{
private:
	
	Node<T>* root;


public:

	BinarySearchTree<T> &getThis(void) {
		return *this;
	}
	BinarySearchTree(void) {
		root = nullptr;
	}
	BinarySearchTree(T data) {
		root = new Node<T>(data);
	}
	~BinarySearchTree(void) {
		clearTree();
	}

	Node<T> * getRoot(void) {
		return root;
	}

	int getNumNodes(Node <T> * toFindSubNodesOf) {
		//recursive function to count nodes
		if (toFindSubNodesOf == nullptr) {
			return 0;
		}
		return 1 + getNumNodes(toFindSubNodesOf->left) + getNumNodes(toFindSubNodesOf->right);
	}

	int getNumNodes(void) {
		if (root == nullptr) {
			return  0;
		}
		return getNumNodes(root->left) + getNumNodes(root->right) + 1;
	}

	bool removePointer(Node<T>* toRemove, Node<T>* currNode) {

		if (currNode == nullptr) {
			return false;
		}
		if (currNode->left == toRemove) {
			currNode->left = nullptr;
			return true;
		}

		if (currNode->right == toRemove) {
			currNode->right = nullptr;
			return true;
		}
		return (removePointer(toRemove, currNode->left) || removePointer(toRemove, currNode->right));


	}

	bool removePointer(Node<T>* toRemove) {
		//this function sets all pointers to deleted nodes as nullptr
		//failing to do this causes invalid pointers in tree

		if (toRemove == root) {
			root = nullptr;
			return true;
		}
		return removePointer(toRemove, root);



	}

	bool findNode(T toFind) {
		if (findNode(toFind, root) == nullptr) {
			return false;
		}
		return true;	
		
	}

	Node<T> * findNode(const T toFind, Node<T>* toSearchFrom) {
		if (toSearchFrom == nullptr) {
			Node<T> * toReturn(NULL); //indicate error
			return toReturn;

		}
		if (toFind == toSearchFrom->Data) {
			return toSearchFrom;
		}

		if (toFind > toSearchFrom->Data) {
			return findNode(toFind ,toSearchFrom->right);
		}

		if (toFind < toSearchFrom->Data) {
			return findNode(toFind ,toSearchFrom->left);
		}


	}

	bool addNode(const T& data, Node<T>* toAddTo) {
		if (data == toAddTo->Data) {
			return false;
		}
		if (data < toAddTo->Data) {
			//if it's less
			if (toAddTo->left == nullptr) {
				toAddTo->left = new Node<T>(data);
				
				return true;
			}
			


			return addNode(data, toAddTo->left);
		}
		//if it is greater

		if (toAddTo->right == nullptr) {
			toAddTo->right = new Node<T>(data);
			return true;
		}
		return addNode(data, toAddTo->right);
	}

	bool addNode(const T& data) {
		if (root == nullptr) { //incase root is null
			root = new Node<T>(data);
			return true;

		}
		else return addNode(data, root);

	}

	

	




	Node<T> * findInlinePredecessor(Node<T> * toFindOf) {
		
		if (toFindOf->left == nullptr) {
			return nullptr;
		}
		

		Node<T> * oneToLeft = toFindOf->left;
		if (oneToLeft->right == nullptr) {
			return oneToLeft;
		}
		Node<T> * next = oneToLeft->right;

		while (next->right != nullptr) {
			next = next->right;
		}
		return next;

	}

	Node<T> * findInlineSucecessor(Node<T> * toFindOf) {

		if (toFindOf->right == nullptr) {
			return nullptr;
		}


		Node<T> * oneToRight = toFindOf->right;
		if (oneToRight->left == nullptr) {
			return oneToRight;
		}
		Node<T> * next = oneToRight->left;

		while (next->left != nullptr) {
			next = next->left;
		}
		return next;

	}

	bool clearTree() { //continually remove root
		while (root != nullptr) {
			removeNode(root->Data, root);
		}
		return true;
	}

	friend ostream & operator<<(ostream& toOutputTo, BinarySearchTree<T>& root) { //allow tree to be output with <<
		toOutputTo << root.toString();
		return toOutputTo;
	}

	

	

	bool removeNode(const T& data, Node<T> * toRemove) { //remove nodes
		if (toRemove == nullptr) {
			return false;
		}
		if (data < toRemove->Data) {
			return removeNode(data, toRemove->left);
		}

		if (data > toRemove->Data) {
			return removeNode(data, toRemove->right);
		}

		if (data == toRemove->Data) {

			if (toRemove->right == nullptr && toRemove->left == nullptr) {
				removePointer(toRemove);
				delete toRemove;
				return true;
			}
			Node<T> * inlinePredecessor = findInlinePredecessor(toRemove);
			
			if (inlinePredecessor != nullptr) {
				toRemove->Data = inlinePredecessor->Data;
				return removeNode(inlinePredecessor->Data, inlinePredecessor);
			}
			else {
				//inline predecessor is not found
				//try swapping it with inline sucessor
				Node<T> * inlineSucessor = findInlineSucecessor(toRemove);

				if (inlineSucessor != nullptr) {
					toRemove->Data = inlineSucessor->Data;
					return removeNode(inlineSucessor->Data, inlineSucessor);
				}
				
				removePointer(toRemove);
				delete toRemove;

				return true;
			}


			


		}
		return false;
	}

	bool removeNode(const T& data) {
		if (findNode(data) == false) {
			return false;
		}
		return removeNode(data,root);

	}


	



	bool outLevel(Node<T>* root, int level, stringstream& out) const //code that professor gave us
	{
		
		if (root == NULL) return false;
		if (level == 1)
		{
			
			
			out << " " << root->Data;
			if ((root->left != NULL) || (root->right != NULL)) return true;
			return false;
		}
		if ((level == 2) && !root->left && root->right) out << " _";
		bool left = outLevel(root->left, level - 1, out);
		bool right = outLevel(root->right, level - 1, out);
		if ((level == 2) && root->left && !root->right) out << " _";
		return left || right;
	}

	

	string toString() const
	{
		stringstream out;
		if (root == NULL) out << " empty";
		else
		{
			int level = 0;
			do
			{
				out << endl << "  " << ++level << ":";
			} while (outLevel(root, level, out));
		}
		return out.str();
	}

	

};





#endif // !BINARY_SEARCH_TREE_H

