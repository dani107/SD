#pragma once

template <typename T>
struct Node
{
	Node<T>* left;
	Node<T>* right;
	T data;
	int key;

	Node(const T _data, const int _key)
	{
		data = _data;
		key = _key;
		left = nullptr;
		right = nullptr;
	}

};

