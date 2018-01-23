// File Name: binarysearchtree.h
// File Contains: binary search tree declarations

// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// BinarySearchTree class
// Creates a BST to store values
// Uses BinaryNode which holds the data
// Uses templates to store any type of data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarynode.h"

//extra includes
#include<list>

using namespace std;

template<class ItemType>
class BinarySearchTree {
public:
	// constructor, empty tree
	BinarySearchTree();
	// constructor, tree with root
	explicit BinarySearchTree(const ItemType& rootItem);
	// copy constructor
	BinarySearchTree(const BinarySearchTree<ItemType>& bst);
	// destructor
	virtual ~BinarySearchTree();
	// true if no nodes
	bool isEmpty() const;
	// 0 if empty, 1 if only root, otherwise
	// max height of subtrees + 1
	int getHeight() const;
	// number of nodes and data in tree
	int getNumberOfNodes() const;
	// add a new item
	// return true if succesasfull
	// false if item already in tree or some other reason to fail
	bool add(const ItemType& item);
	// true if item is in tree
	bool contains(const ItemType& item) const;
	// dispaly a sideways ascii representation of tree
	void displaySideways() const;
	// inorder traversal: left-root-right
	// takes a function that takes a single parameter of ItemType
	// the function can modify the data in tree, but the
	// tree structure is not changed
	void inorderTraverse(void visit(ItemType&)) const;
	// create dynamic array, copy all the items to the array
	// and then read the array to re-create this tree
	void rebalance();
	// delete all nodes in tree and set root to nullptr
	void clear();
	// given an array of length n
	// create this tree to have all items in that array
	// with the minimum height
	bool readTree(ItemType arr[], int n);
	// trees are equal if they have the same structure
	// AND the same item values at all the nodes
	bool operator==(const BinarySearchTree<ItemType> &) const;
	// not == to each other
	bool operator!=(const BinarySearchTree<ItemType> &) const;
private:
	// root of the tree
	BinaryNode<ItemType>* rootPtr{ nullptr };
	// add a new node, helper function for add
	BinaryNode<ItemType>* placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
	// find the node with given vale, helper function for contains
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const;
	// helper function for displaySideways to work recursively
	void sideways(BinaryNode<ItemType>* current, int level) const;
	// other functions....
};

//#include "binarysearchtree.cpp"

#endif // BINARYSEARCHTREE_H

// based on code from Zander
// display ascii version of tree sideways
template<class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const {
	sideways(rootPtr, 0);
}

// display ascii version of tree sideways recursively
template<class ItemType>
void BinarySearchTree<ItemType>::sideways(BinaryNode<ItemType>* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->getRightChildPtr(), level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << current->getItem() << endl;        // display information of object
		sideways(current->getLeftChildPtr(), level);
	}
}


/////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() {
	//ctor
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
	clear();
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
	rootPtr = new BinaryNode<ItemType>(rootItem);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& bst) {
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
	return (rootPtr == nullptr) ? true : false;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
	list<ItemType> treeList;
	treeList.push_front(rootPtr*);
	list<ItemType>::iterator it = treeList.begin();
	int level = 1;
	int babyCount = 0;
	int countDown = 1;
	while (it != treeList.end())
	{
		if (it->leftPtr != nullptr)
		{
			babyCount++;
			treeList.push_front(it->leftPtr);
		}
		if (it->rightPtr != nullptr)
		{
			babyCount++;
			treeList.push_front(it->rightPtr);
		}
		it++; // advance iterator
		if (countDown = 1)
		{
			level++;
			countDown = babyCount;
			babyCount = 0;
		}
		else
			countDown--;
	}

	return level;
}


template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
	int num = 0;
	list<ItemType> treeList;
	treeList.push_front(rootPtr*);
	list<ItemType>::iterator it = treeList.begin();
	while (it != treeList.end())
	{
		if (it->leftPtr != nullptr)
			treeList.push_front(it->leftPtr);

		if (it->rightPtr != nullptr)
			treeList.push_front(it->rightPtr);

		it++;
	}
	num = treeList.size();

	return num;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& item) {
	if (rootPtr == nullptr)
		rootPtr = new BinaryNode<ItemType>(item);
	else
	{
		//if item greater
		//if null
			//add new on right
		// if not null
			//call add on right

		//if item less
		//if null
			//add new on left
		//if not null
			//call add on left

		//if item==
			//return false;
	}
	return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& item) const {
	return true;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
	return nullptr;
}  // end placeNode

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const {
	return nullptr;
}  // end findNode

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
}  // end inorder

template<class ItemType>
void BinarySearchTree<ItemType>::rebalance() {
}

template<class ItemType>
bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n) {
	return true;
}


template<class ItemType>
bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType>& other) const {
	return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType>& other) const {
	return true;
}

