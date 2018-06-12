#pragma once

template <typename T>
struct Node
{
    Node<T>* next;
    Node<T>* prev;
    T data;

    Node(T _data, Node<T>* _next=nullptr, Node<T>* _prev=nullptr):data(_data),next(_next),prev(_prev){}

};
