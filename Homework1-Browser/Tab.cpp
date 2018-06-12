
#include "Tab.h"
void Tab::destroy()
{
    delete[]this->URL;
}
void Tab::copy(const Tab& other)
{
    mystrcpy(URL,other.URL);
}
void Tab::mystrcpy(char* &dest,char* src)
{
    int len=strlen(src)+1;
    dest=new char[len];
    strcpy(dest,src);
}
Tab::Tab()
{
    this->URL=nullptr;
    this->timesOpen=time(0);

}
Tab::Tab(char* URL)
{
    mystrcpy(this->URL,URL);

    this->timesOpen=time(0);
}
Tab::Tab(const Tab& other)
{
    copy(other);
}
Tab& Tab::operator=(const Tab& other)
{
    if(this!=&other)
    {
        destroy();
        copy(other);
    }
    return *this;
}
Tab::~Tab()
{
    destroy();
}

char* Tab::getUrl()const
{
    return this->URL;
}

time_t Tab::getTime()const
{
    return this->timesOpen;
}

void Tab::setUrl(char* URL)
{
    delete[]URL;
    mystrcpy(this->URL,URL);
}

ostream & operator<<(ostream& os, const Tab& tab)
{
    os<<tab.URL<<endl;
    char* stamp = ctime(&tab.timesOpen);
    os<<"Current local time and date:"<<stamp<<endl;
    return os;
}
