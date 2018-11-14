#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binarySearch(vector<int> v,int start,int end,int ele)
{
    // if(v.size()==1 && v[start]!=ele)
    //     return false;
    if(start <= end)
    {
    int mid =(start +end)/2;
    if(ele > v[mid])
        return binarySearch(v,mid+1,end,ele);
    else if(ele < v[mid])
        return binarySearch(v,start,mid-1,ele);
    else if(ele==v[mid])
        return mid;
    }
    return start;
}
int main()
{
    
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(30);
    v.push_back(-10);
    v.push_back(0);
    v.push_back(100);
    sort(v.begin(),v.end());
    cout<<binarySearch(v,0,v.size()-1,-20);
    return 0;
}
