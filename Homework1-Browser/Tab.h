#pragma once
#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;

class Tab
{
    private:
    char* URL;
    time_t timesOpen;

    void mystrcpy(char* &dest,char* src);
    void destroy();
    void copy(const Tab&);
    public:
        Tab();
        Tab(char*);
        Tab(const Tab&);
        Tab& operator=(const Tab&);
        char* getUrl()const;
        time_t getTime()const;
        void setUrl(char*);
        virtual ~Tab();
        friend ostream& operator<<(ostream& os,const Tab& tab);

};
