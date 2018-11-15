/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dictContains(string s)
{
    string dictionary[]={"Hello","ice","baby"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for(int i=0;i< size;i++)
    {
        if(s.compare(dictionary[i])==0)
            return true;
    }
    return false;
}
bool wordBreak(string str){
    int size= str.size();
    if(size == 0)
        return true;
    for(int i=1;i<=size;i++)
    {
        if((dictContains(str.substr(0,i)))
          &&wordBreak(str.substr(i,size-i)))
            return true;
    }
    return false;
}

int main()
{
    cout<<wordBreak("ie");

    return 0;
}
