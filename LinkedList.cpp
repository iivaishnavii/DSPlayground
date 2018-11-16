/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node * next;
};
node *curr,*temp,*head;

class LinkedList{
public:
LinkedList()
{
    curr = NULL;
    temp = NULL;
    head = NULL;
}
node * createNode(int data)
{
    node* n= new node;
    n->data = data;
    n->next = NULL;
    if(head ==  NULL)
    {
        head = n;
    }
    else
    {
        curr= head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next = n;
    }
}
// void insertNode(node *root,int data){
//     curr = root;
//     if(curr == NULL)
//     {
//         root = createteNode(root,data);
//     }
//     else
//     {
//         while(curr->next!=NULL)
//         {
//             curr=curr->next;
//         }
//         curr->next = createteNode(root,data);
//     }
// }
void printList()
{
    curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<endl;
        curr= curr->next;
    }
}
bool isPalindrome()
{
    curr = head;
    if(curr==NULL)
    {
        return false;
    }
    if(curr->next == NULL)
    {
        return true;
    }
    else
    {
        vector<int> v;
        while(curr!=NULL)
        {
            v.push_back(curr->data);
            curr = curr->next;
        }
        
        int i=0;
        vector<int> orgVector = v;
        reverse(v.begin(),v.end());
        if(orgVector == v)
            return true;
        else
            return false;
        /*for(auto it=v.rbegin();it!=v.rend();it++)
        {   
            cout<<*it<<"\t"<<v[i]<<endl;
            if(v[i]==*it)
             {
                 
                 i++;
             }
            else
                return false;
        }
        return true;*/
        
    }
}
};
int main()
{
    LinkedList ll;
    ll.createNode(10);
    ll.createNode(30);
    ll.createNode(20);
    ll.createNode(10);
    cout<<"palindrome? "<<ll.isPalindrome();
    //ll.printList();
    return 0;
}
