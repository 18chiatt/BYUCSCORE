#ifndef QUICKSORT_H
#define QUICKSORT_H
//header guard to prevent multiple inclusion

#include<ostream>
#include<sstream>
#include<string>
#include<iostream>
#define DEFAULT_CAPACITY 1
using namespace std;
#include"QSInterface.h"

//look, no global variable instantiations
template <typename T> //this is templated class to all class member functions
// must be implemented inside the definition
class QuickSort : public QSInterface<T> { //wow, it derives from QSInterface
private:
	T* theArray; //check out this epic PRIVATE data members
	int numElements;
	int capacityOfArray;
	int comparisons;
	int swaps;

public:
	QuickSort(int size) {
		numElements = 0;
		theArray = new T[size];
		capacityOfArray = size;
		comparisons = 0;
		swaps = 0;
	}
	~QuickSort(void) {
		deleteEverything();
	}

	QuickSort(void) {
		numElements = 0;
		capacityOfArray = DEFAULT_CAPACITY;
		theArray = nullptr;
		createArray(DEFAULT_CAPACITY);
		comparisons = 0;
		swaps = 0;
	}


	/** Dynamically allocate an initial array to the QuickSort class. */
	bool createArray(size_t capacityOfArray) {
		if (theArray != nullptr) {
			delete[] theArray;
		}
		theArray = nullptr;
		numElements = 0;
		
		theArray = new T[capacityOfArray];
		
		this->capacityOfArray = capacityOfArray;
		return true;

	}


	/** Add an element to the QuickSort array. Dynamically grow array as needed. */
	bool addElement(T element) {
		if ((numElements + 1) == capacityOfArray) {
			resize();
		}

		theArray[numElements] = element;
		numElements++;
		return true;

	}

	

	/** @return: comma delimited string representation of the array. */
	string toString() const { //wow, non mutating functions declared const
		stringstream output;

		if (numElements == 0) {
			return "Empty";
		}

		if (numElements > capacityOfArray) {
			cerr << "Big error! we have more elements than we have capacityOfArray for!!!"; 
			//inform user of something major going wrong
		}

		for (int i = 0; i < numElements; i++) {
			output << theArray[i] << ",";
		}
		string toReturn = output.str().substr(0, output.str().length() - 1);  //remove trailing comma
		return toReturn;	

	}




	/** The median of three pivot selection has two parts:
	1) Calculates the middle index by averaging the given left and right indices:
	middle = (left + right)/2
	2) Then bubble-sorts the values at the left, middle, and right indices.

	After this method is called, data[left] <= data[middle] <= data[right].

	@param left - the left boundary for the subarray from which to find a pivot
	@param right - the right + 1 boundary for the subarray from which to find a pivot
	@return the index of the pivot (middle index).
	Return -1 if	1) the array is empty,
	2) if either of the given integers is out of bounds,
	3) or if the left index is not less than the right index.
	*/
	int medianOfThree(size_t left, size_t right) {
		right--; //decrement right because it is one too high
		if (numElements == 0) {
			return -1;
		}
		if (left < 0 || left > numElements) {
			return -1;
		}

		if (right > numElements-1 || right < 0) {
			return -1;
		}

		if ((left > right)) {
			return -1;
		}

		int middleIndex = (left + right+1) / 2;

		while (theArray[left] > theArray[middleIndex] || theArray[middleIndex] > theArray[right]) {
			comparisons++;
			if (theArray[left] > theArray[middleIndex]) {
				
				swapData(theArray[left], theArray[middleIndex]);
				
			}
			comparisons++;
			if (theArray[middleIndex] > theArray[right]) {
				
				swapData(theArray[middleIndex], theArray[right]);
				
			}
		}

		return middleIndex;

		

	}
	/** Removes all items from the QuickSort array. */
	bool clear() {
		delete[] theArray;
		theArray = nullptr;
		createArray(capacityOfArray); //delete old array and create one with same capacity
		return true; //this empties array without changing capacity, per lab requirements
	}

	void deleteEverything(void) {
		delete[] theArray;
		theArray = nullptr; //clean up array

	}

	void resize(void) { //create new array w/ double capacity, delete old array
		if (theArray == nullptr) {
			createArray(capacityOfArray);
		}

		int oldcapacityOfArray = capacityOfArray;
		capacityOfArray = capacityOfArray * 2;
		T* newData = new T[capacityOfArray * 2];
		for (int i = 0; i < oldcapacityOfArray; i++) {
			newData[i] = theArray[i];
		}

		delete[] theArray;
		theArray = nullptr;
		
		theArray = newData;

	}

	
	/** Return number of elements in the QuickSort array. */
	size_t size() const { //wow, non mutating functions declared const
		return numElements;
	}
	/** Return size of the QuickSort array. */
	size_t capacity() const { //wow, non mutating functions declared const
		return capacityOfArray;

	}

	void swapData(T& left, T& right) {
		T rightValue = right;

		right = left;
		left = rightValue;
		swaps++;

	}

	bool doChecks(int left, int right, int pivot) const { //wow, non mutating functions declared const
		if (numElements == 0) {
			return false;
		}
		if (left < 0 || left > numElements - 1) {
			return false;
		}

		if (pivot < 0 || pivot > numElements - 1) {
			return false;
		}

		if (right < 0 || right > numElements) {
			return false;
		}

		if (!(left < right)) {
			return false;
		}

		if (pivot > right || pivot < left) {
			return false;
		}
		return true;
	}


	/** Partitions a subarray around a pivot value selected according
	to median-of-three pivot selection. Because there are multiple ways
	to partition a list, follow the algorithm on page 611.

	The values which are smaller than the pivot should be placed to the left of the pivot;
	the values which are larger than the pivot should be placed to the right of the pivot.

	@param left - left index for the subarray to partition.
	@param right - right index + 1 for the subarray to partition.
	@param pivotIndex - index of the pivot in the subarray.
	@return the pivot's ending index after the partition completes:
	Return -1 if	1) the array is empty,
					2) if any of the given indexes are out of bounds,
					3) if the left index is not less than the right index.
	*/
	int partition(size_t left, size_t right, size_t pivot) {
		if (doChecks(left, right, pivot) == false) {
			return -1;
		}

		T valueOfPivot = theArray[pivot];

		

		swapData(theArray[left], theArray[pivot]);
		int up = left+1;
		int down = right - 1;

		while (true) {
			
				
			
			while (!(theArray[up] >= theArray[left]) && up < numElements) { 
				
				comparisons++;

				up++;

				if (up > numElements - 1) { //this stopped my invalid memory reading issue
					break;
				}
			}
			

			while (!(theArray[down] <= theArray[left])) {
				comparisons++;

				down--;

				if (down < 0) {
					break;
				}
			}

			if (down <= up) {
				comparisons++;
				swapData(theArray[left], theArray[down]);
				return down;
			}
			else {
				comparisons++;
				swapData(theArray[up], theArray[down]);
				down--;
				up++;
			}


		}



	}

	void resetSwaps(void) {
		comparisons = 0;
		swaps = 0;
		return;
	}


	/** Sort all elements of the QuickSort array using median and partition functions. */
	bool sortAll(void) {
		resetSwaps();
		
		int indexToPartitionFrom = medianOfThree(0, numElements);
		int pivot = partition(0, numElements, indexToPartitionFrom);
		sort(0, pivot);
		sort(pivot, numElements); //invalid read
		return true;
		
	}

	/** Sort the elements of a QuickSort subarray using median and partition functions. */
	bool sort(size_t left, size_t rightPlusOne) {

		if (left == rightPlusOne - 1) {
			return true;
		}

		if ((rightPlusOne - 1) == left) {
			comparisons++;
			if (theArray[left] > theArray[rightPlusOne]) {
				swapData(theArray[left], theArray[rightPlusOne]);
				return true;
			}
		}


		int indexToPartionFrom = medianOfThree(left, rightPlusOne);
		int pivot = partition(left, rightPlusOne, indexToPartionFrom); 

		sort(left, pivot);
		sort(pivot, rightPlusOne); 
		return true;

	}

	int getComparisons(void) const{ //wow, non mutating functions declared const
		return comparisons;
	}

	int getSwaps(void) const{ //wow, non mutating functions declared const
		return swaps;
	}

	

	

	
	friend ostream& operator<< (ostream& os, QuickSort<T>& mySort) { //look at this public toString friend insertion operator
		os << mySort.toString();
		return os; //friend insertion operator
	}


};




#endif


