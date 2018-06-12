
#include <iostream>
#include "Tab.h"
#include"Browser.h"

using namespace std;


int main()
{

    Browser browse;

    browse.GO("youtube.com");

    browse.INSERT("fifi");

    browse.PRINT();



    return 0;
}
