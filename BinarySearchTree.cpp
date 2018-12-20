// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include<math.h>
#include<stack>
using namespace std;
stack<int> s;
struct node{
    int val;
    node *left;
    node *right;
};
node* createNode(int d){
   node* newnode = new node;
   newnode->val =d;
   return newnode;
}
void inorderTraversal(node *root)
{
    if(root!=NULL)
    {
        inorderTraversal(root->left);
        cout<<root->val;
        inorderTraversal(root->right);
    }
    else
        return;
}
//count the number of nodes in a range
void inorderTraversalBST(node *root,int low,int high)
{
    if(root==NULL)
        return;
    if(root->val > low)
        inorderTraversalBST(root->left,low,high);
    if(root->val >=low && root->val <=high)
        count++;
    if(root->val < high)
    inorderTraversalBST(root->right,low,high);
}
void preorderTraversal(node * root)
{
    if(root!=NULL)
    {
        cout<<root->val;
        preorderTraversal( root->left);
        preorderTraversal(root->right);
        
}
    else{
        return;
    }
}
void postOrderTraversal(node * root)
{
    if(root!=NULL)
    {
        postOrderTraversal( root->left);
        postOrderTraversal(root->right);  
        cout<<root->val;
    }
    else{
        return;
    }
}
node* insertVal(int num,node *root)
{
    if(root == NULL)
        return createNode(num);
    if(num<root->val)
        root->left = insertVal(num,root->left);
    else 
        root->right = insertVal(num,root->right);
    return root;
}    

int height(node *root){
   if(root==NULL) 
       return 0;
   else
   {
       int lheight =height(root->left);
       int rheight =height(root->right);
       return max(lheight,rheight)+1;
   }
}  
bool searchBST(node *root,int ele)
{
    if(root == NULL)
        return false;
    if(ele > root->val)
        return searchBST(root->right,ele);
    else if(ele <root->val)
        return searchBST(root->left,ele);
    else if(ele == root->val)
        return true;
}
int diameter(node *root)
{
     if(root==NULL)
         return 0;
    
     int lheight = height(root->left);
     int rheight = height(root->right);
     int ldiameter = diameter(root->left);
     int rdiameter = diameter(root->right);
    
    return max((lheight+rheight),max(ldiameter,rdiameter));
     
    
    
}
/*bool searchBST(node *root,int a,int b){
      if(root ==NULL)
          return false;
     if(a==b==root) //a==b==root
         return true;
     if(a > root->data)
          return searchBST(root->right,a,b);
     else if(b < root->data)
         return searchBST(root->left,a,b);
     else if((a<=root->data)&&(b>root->data)){
         return(searchBST(root->left,a,root-1)&&searchBST(root->right,root+1,b));         
     }  
}*/
bool isBST(node *root)
{
 if(root == NULL)
     return true;
 if((root->left <= root) && (root->right>root))
 {
     return (isBST(root->left) && isBST(root->right));
 }
 else
     return false;   
    
}
int smallestElement(node * root)
{
     if(root->left == NULL)
     {
         cout<<"base condition"<<root->val<<endl;
         return root->val;
     }
    cout<<"traversing"<<root->val<<endl; 
    smallestElement(root->left);
    
    
}
int lowestCommonAncestor(node *root,int val1,int val2)\
{
    if(root == NULL)
        return 0;
     if((root->val > val1) && (root->val > val2))
        return lowestCommonAncestor(root->left,val1,val2);
     else if((root->val < val1) && (root->val < val2))
        return lowestCommonAncestor(root->right,val1,val2);
     else
        return root->val;  
}  
int lowestCommonAncestorRecursive(node *root,int val1,int val2)\
{
    if(root == NULL)
        return 0;
    while(1){
        
     if((root->val > val1) && (root->val > val2))
        root = root->left;
     else if((root->val < val1) && (root->val < val2))
        root = root->right;
     else
        return root->val;
    }
} 
int main(){
    cout << "Hello, World!" << endl;
    node* n = createNode(10);
    insertVal(100,n);
    insertVal(12,n);
    insertVal(31,n);
    insertVal(50,n);
    insertVal(6,n);
    //inorderTraversal(n);
    preorderTraversal(n);
    //findAncestors(n,12);
    //cout<<"is element present"<<searchBST(n,5);
    //cout<<"smallest element"<<smallestElement(n);
    //cout<<diameter(n);
    cout<<"LCA"<<lowestCommonAncestor(n,12,6)<<endl;
    cout<<"LCA"<<lowestCommonAncestorRecursive(n,50,6);
    return 0;
}
