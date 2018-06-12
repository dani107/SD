#pragma once
#include"Tab.h"
#include"DoublyLinkedList.h"

class Browser
{
    private:


    DoublyLinkedList<Tab> tabs;
    Node<Tab>* momentTab;
    int countTab=0;
    time_t timesOpen;

    public:
        Browser();

        void PRINT();
        void INSERT(char*);
        void GO(char*);
        void BACK();
        void FORWARD();
        void REMOVE();





};
