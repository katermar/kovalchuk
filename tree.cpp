#pragma once
#include "head/tree.h"
#include "head/Header.h"
#include "head/File.h"

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

template <class T>
TreeNode<T>* TreeNode<T>::getLeft() const
{
	return left;
}

template <class T>
TreeNode<T>* TreeNode<T>::getRight() const
{
	return right;
}

template <class T>
TreeNode<T>* TreeNode<T>::getParent() const
{
	return parent;
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
	TreeNode<T>* ptr;
	TreeNode<T>* ptr1 = nullptr;

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
void Tree<T> :: write(TreeNode<T>* tn, File<T> &file)
{
	if(!tn) return;
	if(tn->left) write(tn->left, file);
	try
	{
		file.write(tn->val);
	}
	catch (FileException exception)
	{
		exception.what();
	}
	if(tn->right) write(tn->right, file);
}

template<class T>
void Tree<T> :: writeFile(File<T> &file)
{	
	try
	{
		file.makeEmpty();
		file.openFile();
		write(this->getRoot(), file);
	}
	catch (FileException exception)
	{
		exception.what();
	}
	catch (exception ex)
	{
		ex.what();
	}
}

template<class T>
void Tree<T> :: read(File<T> &file)
{
	T obj;
	try
	{
		if (file.getFilename().find(".DAT") == string::npos)
			//while (!file.isVeryEnd())
				while (true)
				{
					//T obj;
					file.openFile();
					file.read(obj);
					if(file.isVeryEnd()) break;
					if (!obj.isNull()) this->newNode(obj);
					//else break;
				}
		else
			for (int i = 0; i < file.fileSize(); i++)
			{
				//T obj;
				file.openFile();
				file.read(obj, i);
				if (!obj.isNull()) this->newNode(obj);
				else break;
			}
	}
	catch (FileException exception)
	{
		exception.what();
	}
	catch (exception ex)
	{
		ex.what();
	}
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

	if (treeOriginal == nullptr) 
		return nullptr;

	TreeNode<T>* treeNew = new TreeNode<T>(treeOriginal->val);
	treeNew->parent = parent;

	treeNew->left = rewriteTree(treeOriginal->left, treeNew);
	treeNew->right = rewriteTree(treeOriginal->right, treeNew);

	return treeNew;	
}

///////////////////////////////////////////////////////////////////////////
template <class T>
bool TreeIterator<T>::hasNext()
{
	return nextNode != nullptr;
}

template <class T>
TreeIterator<T>::TreeIterator(TreeNode<T>* root)
{
	prevNode = nullptr;
	nextNode = root;
	if(nextNode == nullptr)
		return;
	while (nextNode->left != nullptr)
		nextNode = nextNode->left;
	node = nextNode;
}

template <class T>
void TreeIterator<T>:: operator++()
{
	if(!hasNext()) throw new exception("No next member\n");
	TreeNode<T>* r = nextNode;
	prevNode = node;
	// if you can walk right, walk right, then fully left.
	// otherwise, walk up until you come from left.
	if(nextNode->right != nullptr){
		nextNode = nextNode->right;
		while (nextNode->left != nullptr)
			nextNode = nextNode->left;
		node = r;
		return;
	} else while(true){
		if(nextNode->parent == nullptr){
			nextNode = nullptr;
			node = r;
			return;
		}
		if(nextNode->parent->left == nextNode){
			nextNode = nextNode->parent;
			node = r;
			return;
		}
		nextNode = nextNode->parent;
	}
}

template <class T>
TreeNode<T>* TreeIterator<T>::operator*()
{
	return node;
}

template <class T>
bool TreeIterator<T>::operator==(const TreeIterator<T>& x) 
{
	return x.node == this->node;
}

template <class T>
bool TreeIterator<T>::operator!=(const TreeIterator<T>& x) 
{
	return x.node != this->node;
}

template <class T>
void TreeIterator<T>::operator--()
{
	node = prevNode;
}
