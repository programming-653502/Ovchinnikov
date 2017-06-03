#pragma once
#include "stdafx.h"
class BST 
{
private:
	struct Node
	{
		int data;
		Node* left;
		Node* right;
	};
	Node* root;
	void AddLeafPrivate(int data, Node* Ptr);
	void PrintInOrderPrivate(Node* Ptr);
	void RemoveNodePrivate(int data,Node* Parent);
	Node* ReturnNodePrivate(int data, Node* Ptr);
	int SmallestPrivate(Node* Ptr);
	void RemoveRootMatch();
	void RemoveMatch(Node* parent, Node* match, bool left);
	
public:
	BST();
	Node* CreateLeaf(int data);
	void AddLeaf(int data);
	void PrintInOrder();
	void RemoveNode(int data);
	Node* ReturnNode(int data);
	int Smallest();
};
