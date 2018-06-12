#pragma once
#include"Node.h"
#include<string>
static int coun = 0;

template <typename T>
class Tree
{
private:

	Node<T>* root;
	void addElementHelper(const T&,const int, Node<T>*&);
	void printHelper(Node<T>*&);
	bool findHelper(const T&,const int, Node<T>*&);
	T findMax(Node<T>*& root);
	bool deleteItem(const T&,const int, Node<T>*&);
	void destroyAllwithKey(Node<T>*&,const int);
	void destroy();
	void destroyHelper(Node<T>*);
	

public:
	Tree();
	int removeall(const int);
	bool search(const T&,const int);
	void insert(const T&,int);
	void printTree();
	bool remove(const T&,const int key);
	~Tree();



};

template <typename T>
Tree<T>::Tree()
{
	this->root = nullptr;
}

template <typename T>
int Tree<T>::removeall(const int key)
{
	this->destroyAllwithKey(this->root,key);
	return coun;
}

template <typename T>
void Tree<T>::destroyAllwithKey(Node<T>*& node,const int key)
{
	if (node)
	{
		destroyAllwithKey(node->left, key);
		destroyAllwithKey(node->right, key);
		
		if (node->key == key)
		{
			deleteItem(node->data, node->key, node);
			coun++;
		}
		
	}
}

template <typename T>
void Tree<T>::printTree()
{
	printHelper(root);
}

template<typename T>
void Tree<T>::insert(const T& element,const int key)
{
	addElementHelper(element,key,this->root);
}

template <typename T>
void Tree<T>::addElementHelper(const T& data, int key, Node<T>*& root)
{
	if (!root)
	{
		root = new Node<T>(data, key);
	}
	else
	{
		if (data == root->data)
		{
			return;
		}

		if (data > root->data)
		{
			addElementHelper(data, key, root->right);
		}

		if (data<root->data)
		{
			addElementHelper(data, key, root->left);
		}

	}
}

template <typename T>
void Tree<T>::printHelper(Node<T>*& root)
{
	if (root)
	{
		printHelper(root->left);

		cout << "Data:" << root->data << " ";

		printHelper(root->right);
	}
}

template <typename T>
bool Tree<T>::search(const T& value,const int key)
{
	return this->findHelper(value, key, root);
		
}

template <typename T>
bool Tree<T>::findHelper(const T& value,const int key, Node<T>*& root)
{
	if (root)
	{
		if (root->data < value)
			findHelper(value,key, root->right);
		else if (root->data>value)
		{
			findHelper(value,key, root->left);
		}
		else if (root->data == value)
		{
			if(root->key == key)
			return true;
			else
			{
				return false;
			}
			
		}
		
	}
	else 
	{
		return false;
	}
	
	
		
}

template<typename T>
T Tree<T>::findMax(Node<T>*& root)
{
	Node<T>* item = root;

	while (item->right)
	{
		item = item->right;
	}

	return item->data;
}

template <typename T>
bool Tree<T>::remove(const T& value,const int key)
{
	return deleteItem(value, key, root);	
}

template <typename T>
bool Tree<T>::deleteItem(const T& value,const int key, Node<T>*& node)
{
	if (node)
	{
		if (value < node->data)
		{
			deleteItem(value, key, node->left);
		}
		else if (value > node->data)
		{
			deleteItem(value, key, node->right);
		}
		else if (value == node->data)
		{
			if (node->key == key)
			{
				if (node->left && node->right)
				{
					T max = findMax(node->left);

					node->data = max;
					deleteItem(max, key, node->left);

				}
				else if (node->left)
				{
					Node<T>* toDel = node;
					node = node->left;
					delete toDel;

				}
				else
				{
					Node<T>* toDel = node;
					node = node->right;
					delete toDel;

				}

				return true;

			}
			else
				return false;


		}
		else
			return false;
	}
	else
	return false;
	
}

template <typename T>
void Tree<T>::destroy()
{
	this->destroyHelper(this->root);
}

template <typename T>
void Tree<T>::destroyHelper(Node<T>* node)
{
	if (node)
	{
		destroyHelper(node->left);
		destroyHelper(node->right);

		delete node;
	}
}

template <typename T>
Tree<T>::~Tree()
{
	this->destroy();
}
