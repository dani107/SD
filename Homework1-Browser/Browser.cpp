#include "Browser.h"


Browser::Browser()
{
   Tab t("about:blank");
   tabs.pushBack(t);
   momentTab=tabs.getFirst();
   this->countTab++;
}

void Browser::GO(char* url)
{
    Tab t2(url);
    momentTab->data=t2;//Не мога да си обясня,защо не ми присвоява timestamp-а на таба.

}

void Browser::INSERT(char* url)
{
    Tab cur(url);
    tabs.insertAfter(momentTab,cur);
    momentTab=momentTab->next;
    this->countTab++;
}

void Browser::FORWARD()
{
    if(momentTab->next != nullptr)
    momentTab=momentTab->next;
    else if(momentTab->next == nullptr)
        momentTab=tabs.getFirst();

}

void Browser::BACK()
{
    cout<<momentTab->data;
    if(momentTab->prev != nullptr)
    momentTab=momentTab->prev;
    else if(momentTab->prev == nullptr)
        momentTab=tabs.getLast();

    cout<<momentTab->data;
}

void Browser::REMOVE()
{
    if(countTab!=1)
    {

        Node<Tab>* huhu = momentTab;
        if(momentTab->next != nullptr) momentTab=momentTab->next;
        else if(momentTab->next == nullptr)
        momentTab=momentTab->prev;
        this->countTab--;
        //delete(huhu); Трябва да изтрия обекта,но по незнайна причина щом го направя програмата гърми.
    }
    else
    {
        Tab tab("about:blank");
        momentTab->data=tab;
    }


}

void Browser::PRINT()
{
    momentTab=tabs.getFirst();
    for(int c=0;c<countTab;c++)
        {
            cout<<momentTab->data;
            momentTab=momentTab->next;
        }

}


