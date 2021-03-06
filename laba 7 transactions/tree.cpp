#pragma once
#include "head\tree.h"

template<class T>
TreeNode<T> :: TreeNode(const T &a)
{
	val = a;
	left = right = nullptr;
}

template <class T>
T TreeNode <T> :: getValue()
{
	return val;
}

/////////////////////////////////////////////////////////////////////////////////////////
template<class T>
Tree<T> :: Tree()
{
	root = nullptr;
}

template<class T>
Tree<T> :: Tree(const Tree<T> &obj)
{
	root = rewriteTree(obj.root, nullptr);
}

template<class T>
void Tree<T> :: newNode(const T &x)
{
	TreeNode<T>* n = new TreeNode<T>(x);
	TreeNode<T>* ptr = NULL;
	TreeNode<T>* ptr1 = NULL;

	n->parent = n->left = n->right = nullptr;
	ptr = root;
	while (ptr != nullptr)
	{
		ptr1 = ptr;
		if (ptr->getValue() > x)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	n->parent = ptr1;
	if (ptr1 == nullptr)
		root = n;
	else
	{
		if (ptr1->getValue() > x)
			ptr1->left = n;
		else
			ptr1->right = n;
	}
	//return nullptr;
}

template<class T>
TreeNode<T>* Tree<T> :: deleteNode(TreeNode<T> *z)
{
	TreeNode<T>* y;
	TreeNode<T>* x;
	if (z->left == nullptr || z->right == nullptr)
		y = z;
	else
		y = findS(z->getValue());

	if (y->left != nullptr)
		x = y->left;
	else
		x = y->right;

	if (x != nullptr)
		x->parent = y->parent;

	if (y->parent == nullptr)
		root = x;
	else
	{
		if (y == (y->parent)->left)
			(y->parent)->left = x;
		else
			(y->parent)->right = x;
	}
	if (y != z)
	{
		z->val = y->getValue();
		delete y;
	}
	
	return y;
}

template<class T>
TreeNode<T>* Tree<T> :: findMax(TreeNode<T>* x)
{
	while (x->right != nullptr)
		x = x->right;
	return x;
}

template<class T>
TreeNode<T>* Tree<T> :: findMin(TreeNode<T>* x)
{
	while (x->left != nullptr)
		x = x->left;
	return x;
}

template<class T>
TreeNode<T>* Tree<T> :: findS(const T & val)
{
	TreeNode<T>* x = find(root, val);
	TreeNode<T>* y;
	if (x == nullptr)
		return nullptr;
	if (x->right != nullptr)
		return findMin(x->right);
	y = x->parent;
	while (y != nullptr && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

template<class T>
TreeNode<T>* Tree<T> :: find(TreeNode<T>* n, const T & val)
{
	if (nullptr == n || n->getValue() == val)
		return n;
	if (n->getValue() < val)
		return find(n->right, val);
	else
		return find(n->left, val);
}

template<class T>
void Tree<T> :: print(TreeNode<T>* tn)
{
	if(!tn) return;
	if(tn->left) print(tn->left);
	cout << tn->val << endl;
	if(tn->right) print(tn->right);
}

template<class T>
void Tree<T> :: clear(TreeNode<T>* n)
{
	if (n != nullptr)
	{
		clear(n->left);
		clear(n->right);
		deleteNode(n);
	}
}

template<class T>
TreeNode<T>* Tree<T> :: getRoot()
{
	return root;
}


template<class T>
bool Tree<T> :: findNode(T find_value)
	{ 
		TreeNode<T> *tn = find(root, find_value);

		if(tn) return true;
		else return false;
	}

template<class T>
TreeNode<T>*  Tree<T> :: rewriteTree(TreeNode<T> *treeOriginal, TreeNode<T> *parent)
{

    if (treeOriginal == NULL) 
		return NULL;

    TreeNode<T>* treeNew = new TreeNode<T>(treeOriginal->val);
    treeNew->parent = parent;

    treeNew->left = rewriteTree(treeOriginal->left, treeNew);
    treeNew->right = rewriteTree(treeOriginal->right, treeNew);

    return treeNew;	
}

