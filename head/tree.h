#pragma once
#include "F://BSUIR//2 kurs//нно//laba 7 transactions/File.cpp"
//#include "File.cpp"

template <class T> class Tree;

template <class T>
struct TreeNode
{
	friend class Tree<T>;
public:
	explicit TreeNode(const T &a);
	T getValue();
protected:
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	T val;
};

template <class T>
class Tree
{
private:
	TreeNode<T> *root;
	static int size;
public:
	Tree();
	Tree(const Tree<T> &obj);
	void newNode(const T &);
	TreeNode<T>* deleteNode(TreeNode<T> *);
	void print(TreeNode<T>*);
	static TreeNode<T>* findMax(TreeNode<T>*);
	static TreeNode<T>* findMin(TreeNode<T>*);
	TreeNode<T>* find(TreeNode<T>*, const T &);
	TreeNode<T>* findS(const T &);
	void clear(TreeNode<T>*);
	TreeNode<T> *getRoot();
	bool findNode(T find_value);

	TreeNode<T>* rewriteTree(TreeNode<T> *treeOriginal, TreeNode<T> *parent);
	void write(TreeNode<T>* tn, File<T>& file);
	void writeFile(File<T>& file);
	void read(File<T>& file);
};