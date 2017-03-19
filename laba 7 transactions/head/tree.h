#pragma once
template <class T> class Tree;

template <class T>
struct TreeNode
{
	friend class Tree<T>;
public:
	TreeNode(const T &a);
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
	TreeNode<T>* findMax(TreeNode<T>*);
	TreeNode<T>* findMin(TreeNode<T>*);
	TreeNode<T>* find(TreeNode<T>*, const T &);
	TreeNode<T>* findS(const T &);
	void clear(TreeNode<T>*);
	TreeNode<T> *getRoot();
	bool findNode(T find_value);

	TreeNode<T>* rewriteTree(TreeNode<T> *treeOriginal, TreeNode<T> *parent);

};