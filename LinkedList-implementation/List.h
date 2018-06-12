#pragma once
template<typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& dt, Node* next = nullptr)
	{
		this->data = dt;
		this->next = next;
	}
};

template<typename T>
class List
{
private:
	Node<T>* head;
	void copy(const List& other);
	void empty();
public:
	List();
	~List();
	List(const List& other);
	List& operator=(const List& other);
	void add(const T&);
	bool remove(const T&);
	bool find(const T&) const;
	bool isEmpty() const;

};

template<typename T>
List<T>::List()
{
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	empty();
}

template<typename T>
List<T>::List(const List<T>& other)
{
	copy(other);
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this != &other)
	{
		empty();
		copy(other);
	}
	return *this;
}

template<typename T>
void List<T>::copy(const List<T>& other)
{
	if (other.head == nullptr)return;
	this->head = new Node<T>(other.head->data, nullptr);
	Node<T>* n = this->head, *it = other.head->next;
	while (it != nullptr)
	{
		n->next = new Node<T>(it->data, nullptr);
		n = n->next;
		it = it->next;
	}
}

template<typename T>
void List<T>::empty()
{
	while (head != nullptr)
	{
		Node<T>* remove = head;
		head = head->next;
		delete remove;
	}
	head = nullptr;
}

template<typename T>
void List<T>::add(const T& val)
{
	Node<T>* node = new Node<T>(val, this->head);
	if (node)
	{
		this->head = node;
	}
}

template<typename T>
bool List<T>::find(const T& val) const
{
	Node<T>* it = head;
	while (it)
	{
		if (it->data == val)return true;
		it = it->next;
	}
	return false;
}

template<typename T>
bool List<T>::remove(const T& val)
{
	if (head->data == val)
	{
		Node<T>* remove = head;
		head = head->next;
		delete remove;
		return true;
	}
	Node<T>* it = head;
	while (it->next)
	{
		if (it->next->data == val)
		{
			Node<T>* remove = it->next;
			it->next = it->next->next;
			delete remove;
			return true;
		}
	}
	return false;
}

template<typename T>
bool List<T>::isEmpty() const
{
	return this->head == nullptr;
}