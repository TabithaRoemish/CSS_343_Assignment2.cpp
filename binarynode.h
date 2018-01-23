// File Name: binarynode.h
// File contains: Binary Node declarations

// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// BinaryNode to help with BinarySearchTree class
// Uses template so that ItemType can be any type
// getLeftChildPtr and setLeftChildPtr used to get/set child nodes
// getItem/setItem used to set the data stored in this node
// BinarySearchTree requires <, > relationships to be defined for ItemType
// << for  BinaryNode is defined to print the ItemType as [BN: item ]
// binarynode.cpp file is included at the bottom of the .h file
// binarynode.cpp is part of the template, cannot be compiled separately

#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <iostream>

template<class ItemType>
class BinaryNode {
	// operator<<
	// Has to be defined in .h and not in cpp since it is not in
	// BinaryNode<ItemType>:: class
	friend std::ostream& operator<<(std::ostream& out, const BinaryNode<ItemType>& bn) {
		out << "[BN: " << bn.item << "]";
		return out;
	}
public:
	// default constructor
	BinaryNode();
	// constructor setting the data to be stored
	explicit BinaryNode(const ItemType& item);
	// destructor to cleanup
	virtual ~BinaryNode();
	// true if no children, both left and right child ptrs are nullptr
	bool isLeaf() const;
	// get left child, possibly nullptr
	BinaryNode* getLeftChildPtr() const;
	// set the left child ptr
	void setLeftChildPtr(BinaryNode* childPtr);
	// get right child, possibly nullptr
	BinaryNode* getRightChildPtr() const;
	// set the right child ptr
	void setRightChildPtr(BinaryNode* childPtr);
	// return the item stored
	ItemType getItem() const;
	// set the item stored to a new value
	void setItem(const ItemType& item);
private:
	// the data that will be stored
	ItemType item;
	// left child
	BinaryNode* leftPtr{ nullptr };
	// right child
	BinaryNode* rightPtr{ nullptr };
};

//#include "binarynode.cpp"



////////////////////////////

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() {
	//ctor
}

// destructor
template<class ItemType>
BinaryNode<ItemType>::~BinaryNode() {
	// If suffering from memory leaks, uncomment next line
	// std::cout << "Deleting " << *this << std::endl;
}

// constructor setting item
// left and right childPtr set to nullptr as default
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& item) : item{ item } {
}

// true if no children, both leftPtr and rightPtr are nullptrs
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
	return leftPtr == nullptr && rightPtr == nullptr;
}

// getter for left child
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
	return leftPtr;
}

// setter for left child
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode* childPtr) {
	leftPtr = childPtr;
}

// getter for right child
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
	return rightPtr;
}

// setter for left child
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode* childPtr) {
	rightPtr = childPtr;
}

// getter for item stored at node
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
	return item;
}

// setter for item stored at node
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& item) {
	this->item = item;
}

#endif // BINARYNODE_H