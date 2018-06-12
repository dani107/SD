#pragma once
#include<iostream>
#include"Node.h"

using namespace std;

template <typename T>
class DoublyLinkedList
{
    private:
        Node<T>* first;
        Node<T>* last;
        int counter;

        Node<T>* goToElement(int);
        void destroy();
        void init();
        void copy(const DoublyLinkedList&);
        void copyReverse(const DoublyLinkedList<T>& st);

    public:
        DoublyLinkedList();//yes
        DoublyLinkedList(const DoublyLinkedList&);
        DoublyLinkedList& operator=(const DoublyLinkedList&);
        ~DoublyLinkedList();//yes

        bool isEmpty()const;//yes
        int getNumber0fElements()const;//yes
        void pushFront(const T&);//yes
        void pushBack(const T&);//yes
        T popFront();//yes
        T popBack();//yes
        void insertAfter(int,const T&);//yes
        void removeAt(int);//yes

        T getFirstElement()const;//yes
        T getLastElement()const;//yes


        T operator[](int);//yes


};

template <typename T>
T DoublyLinkedList<T>::operator[](int index)
{
   if(index < 0 || index >= this->counter)
    {
        cout<<"Index can't bigger than list length or be smaller than"<<endl;
        return 0;
    }
    return this->goToElement(index)->data;
}

template <typename T>
void DoublyLinkedList<T>::init()
{
    this->first=nullptr;
    this->last=nullptr;
    this->counter=0;

}

template <typename T>
bool DoublyLinkedList<T>::isEmpty()const
{
    return (this->first==nullptr) && (this->last==nullptr);
}

template <typename T>
void DoublyLinkedList<T>::destroy()
{
    while(!this->isEmpty())
    {
        popBack();
    }

}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    init();
}

template <typename T>
int DoublyLinkedList<T>::getNumber0fElements()const
{
    return this->counter;
}

template <typename T>
void DoublyLinkedList<T>::pushFront(const T& element)
{
    if(isEmpty())
    {
        Node<T>* node = new Node<T>(element,nullptr,nullptr);
        this->first=node;
        this->last=node;

    }
    else
    {
        Node<T>* temp = new Node<T>(element,first,last);
        first->prev=temp;

        this->first=temp;
        this->last->next=first;


    }
    this->counter++;

}

template <typename T>
void DoublyLinkedList<T>::pushBack(const T& element)
{
    if(isEmpty())
    {
        Node<T>* node = new Node<T>(element,nullptr,nullptr);
        this->first=node;
        this->last=node;

    }
    else
    {
        Node<T>* temp = new Node<T>(element,first,last);
        last->next=temp;

        this->last=temp;
        this->first->prev=last;


    }
    this->counter++;
}
template <typename T>
T DoublyLinkedList<T>::popFront()
{
    if(this->isEmpty())
    {
        cout<<"You can not remove element. List size is ";
        return 0;
    }
    else if(this->counter==1)
    {
           Node<T>* n = first;
           init();
           T x = n->data;
           delete n;
           return x;


    }
    else
    {
        Node<T>* temp = this->first;
        first=first->next;
        first->prev=last;
        T x = temp->data;

        delete(temp);
        this->counter--;
        return x;

    }

}

template <typename T>
T DoublyLinkedList<T>::popBack()
{
    if(this->isEmpty())
    {
        cout<<"You can not remove element. List size is ";
        return 0;
    }
    else if(this->counter==1)
    {
           Node<T>* n = last;
           init();
           T x = n->data;
           delete n;
           return x;


    }
    else
    {
        Node<T>* temp = this->last;
        last=last->prev;
        last->next=first;
        T x = temp->data;

        delete(temp);
        this->counter--;
        return x;

    }

}

template <typename T>
T DoublyLinkedList<T>::getFirstElement()const
{
    return this->first->data;
}

template <typename T>
T DoublyLinkedList<T>::getLastElement()const
{
    return this->last->data;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::goToElement(int index)
{
    int current = this->counter/2;
    if(index<0 || index>=this->counter)
      {
        cout<<"Index can't be smaller than 0 or bigger than list length"<<endl;
        return NULL;
      }
    else if(index<current)
    {
        Node<T>* temp=this->first;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
    else if(index>=current)
    {
        Node<T>* temp = this->last;
        for(int i=this->counter-1;i>index;i--)
        {
            temp=temp->prev;
        }
        return temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertAfter(int index, const T& element)
{
    if(!this->isEmpty())
    {
        if(index < 0 || index >= this->counter)
            cout<<"Index can't be smaller than 0 or bigger than list length"<<endl;
        else if(index == 0) pushFront(element);
        else if(index == this->counter-1) pushBack(element);
        else
        {

            Node<T>* node = new Node<T>(element,nullptr,nullptr);
            Node<T>* store_next=goToElement(index)->next;
            this->goToElement(index)->next = node;
            node->prev=this->goToElement(index);
            node->next=store_next;
            store_next->prev=node;

        }

        this->counter++;
    }

}

template <typename T>
void DoublyLinkedList<T>::removeAt(int index)
{
        if(!this->isEmpty())
    {
        if(index < 0 || index >= this->counter)
            cout<<"Index can't be smaller than 0 or bigger than list length"<<endl;
        else if(index == 0) popFront();
        else if(index == this->counter-1) popBack();
        else
        {

            Node<T>* temp = this->goToElement(index);
            Node<T>* store_next=goToElement(index)->next;
            Node<T>* store_prev=goToElement(index)->prev;
            store_next->prev=store_prev;
            store_prev->next=store_next;

            delete(temp);

        }

        this->counter--;
    }


}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other)
{
    init();
    copy(other);
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
    if(this!=&other)
    {
        destroy();
        init();
        copy(other);
    }
    return *this;

}

template <typename T>
void DoublyLinkedList<T>::copyReverse(const DoublyLinkedList<T>& st)
{

    Node<T>* node = st.first;
    for(size_t i = 0; i < st.getNumber0fElements(); i++)
    {
        this->pushBack(node->data);
        node = node->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::copy(const DoublyLinkedList<T>& st)
{

    DoublyLinkedList<T> reverse;
    reverse.copyReverse(st);

    this->copyReverse(reverse);
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
   destroy();
}
