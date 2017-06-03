#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "BST.h"
using namespace std;

BST::BST() 
{
	root = NULL;
}
BST::Node* BST::CreateLeaf(int data) 
{
	Node* N = new Node;
	N->data = data;
	N->left = NULL;
	N->right = NULL;
	return N;
}
void BST::AddLeaf(int data) 
{
	AddLeafPrivate(data, root);
}
void BST::AddLeafPrivate(int data, Node* Ptr) 
{
	if (root == NULL) 
	{
		root = CreateLeaf(data);
	}
	else if (data < Ptr->data) 
	{
		if (Ptr->left != NULL) 
		{
			AddLeafPrivate(data, Ptr->left);
		}
		else 
		{
			Ptr->left = CreateLeaf(data);
		}
	}
	else if (data > Ptr->data)
	{
		if (Ptr->right != NULL)
		{
			AddLeafPrivate(data, Ptr->right);
		}
		else
		{
			Ptr->right = CreateLeaf(data);
		}
	}
	else
	{
		cout << "the data" << data << "has already been added to the tree\n";
	}
}
void BST::PrintInOrder() 
{
	PrintInOrderPrivate(root);
}
void BST::PrintInOrderPrivate(Node* Ptr) 
{
	if (root != NULL) 
	{
		if (Ptr->left != NULL) 
		{
			PrintInOrderPrivate(Ptr->left);
		}
		cout << Ptr->data << " ";
		if (Ptr->right != NULL) 
		{
			PrintInOrderPrivate(Ptr->right);
		}

	}
	else 
	{
		cout << "The tree is empty\n";
	}
}
void BST::RemoveNode(int data) 
{
	RemoveNodePrivate(data,root);
}

void BST::RemoveNodePrivate(int data,Node* Parent) 
{
	if (root != NULL) 
	{
		if (root->data == data)
		{
			RemoveRootMatch();
		}
		else
			if (data < Parent->data && Parent->left != NULL)
			{
				Parent->left->data == data ?
					RemoveMatch(Parent, Parent->left, true) :
					RemoveNodePrivate(data, Parent->left);
			}
			else if (data < Parent->data && Parent->right != NULL)
			{
				Parent->right->data == data ?
					RemoveMatch(Parent, Parent->right, false) :
					RemoveNodePrivate(data, Parent->right);
			}
			else
			{
				cout << "node with data: " << data << " wasn't found in the tree\n";
			}
	}
	else
	{
		cout << "hey tree still empty, maybe you forget to fill it?";
	}
}

BST::Node* BST::ReturnNode(int data) 
{
	return ReturnNodePrivate(data, root);
}
BST::Node* BST::ReturnNodePrivate(int data, Node* Ptr) 
{
	if (Ptr != NULL)
	{
		if (Ptr->data == data)
		{
			return Ptr;
		}
		else 
		{
			if (data < Ptr->data)
			{
				ReturnNodePrivate(data, Ptr->left);
			}
			else 
			{
				ReturnNodePrivate(data, Ptr->right);
			}
		}
	}
	else
	{
		return NULL;
	}
}
int BST::Smallest() 
{
	return SmallestPrivate(root);
}
int BST::SmallestPrivate(Node* Ptr)
{
	if (root == NULL)
	{
		cout << "tree still emtpy";
		return -1;
	}
	else
	{
		if (Ptr->left != NULL)
		{
			return SmallestPrivate(Ptr->left);
		}
		else
			return Ptr->data;

	}
}
void BST::RemoveRootMatch() 
{
	if (root != NULL)
	{
		Node* DelPtr = root;
		int RootData = root->data;
		int smallestInRightSubstree;
		//case 0-0 children 
		if (root->left == NULL && root->right == NULL) 
		{
			root = NULL;
			delete DelPtr;
		}
		//case 1-1 children
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			DelPtr->right = NULL;
			delete DelPtr;
			cout << "the root with data " << RootData << " was deleted";
			cout << "The new root contains data " << root->data << endl;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			DelPtr->left = NULL;
			delete DelPtr;
			cout << "the root with data " << RootData << " was deleted";
			cout << "The new root contains data " << root->data << endl;
		}

		//case 2-2 children
		else 
		{
			smallestInRightSubstree = SmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubstree, root);
			root->data = smallestInRightSubstree;
			cout << "the root data contains data " << RootData << " was overwriten with key" << root->data << endl;
		}
	}

}
void BST::RemoveMatch(Node* parent, Node* match, bool left) 
{
	if (root != NULL) 
	{
		Node* DelPtr;
		int matchData = match->data;
		int smallestInRightSubtree;
		//case 0-0 children

		if (match->left == NULL && match->right == NULL) 
		{
			DelPtr = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete DelPtr;
			cout << "node containig data " << matchData << " was removed\n";
		}
		//case 1-1 children

		else if (match->left == NULL && match->right != NULL) 
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			DelPtr = match;
			delete DelPtr;
			cout << "Node with data " << matchData << " was removed\n";
		}
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			DelPtr = match;
			delete DelPtr;
			cout << "Node with data " << matchData << " was removed\n";
		}
		//case 2-2 children
		else
		{
			smallestInRightSubtree = SmallestPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match->data = smallestInRightSubtree;
			cout << "Node with data " << matchData << " was removed\n";
		}
	}
	else 
	{
		cout << "you still don't that that tree is empty, don't act dumb\n";
	}
}