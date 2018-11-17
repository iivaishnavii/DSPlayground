#include <iostream>
#include<vector>
using namespace std;

void magic(vector<int> temp)
{
    vector<int> t;
    if(temp.size()==1)
     {
         cout<<temp[0]<<endl;
         return;
     }
    for(int i=0;i<temp.size()-1;i++)
    {
        t.push_back(temp[i]+temp[i+1]);
    }
    magic(t);
    for(int i=0;i<t.size();i++)
    {
        cout<<t[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    
    vector<int> temp;
    temp.push_back(10);
    temp.push_back(9);
    temp.push_back(3);
    temp.push_back(50);
    temp.push_back(8);
    //magicisreal.push_back(temp);
    magic(temp);
    //printMagic();
    return 0;
}
