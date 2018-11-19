/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
class Tree{
    public:
    node* createNode(int data)
    {
        node* newnode = new node;
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    void insertIntoBinaryTree(node *root,int data)
    {
        queue<node *> q;
        q.push(root);
        while(!q.empty())
        {
            node* temp=q.front();
            //cout<<temp->data<<"\t";
            q.pop();
            if(root->left!=NULL)
            {
                root->left = createNode(data);
                break;
            }
            else
                q.push(temp->left);
            if(root->right!=NULL)
            {
                root->right = createNode(data);
                break;
            }
            else
                q.push(temp->right);
        }
        
    }
    void inorderTraversal(node *root)
    {
        if(root == NULL)
            return;
        inorderTraversal(root->left);
        cout<<root->data<<"\t";
        inorderTraversal(root->right);
    }
    //program to store sum of all nodes in left subtree
    int SumOfLeftSubTree(node * root)
    {
        if(root==NULL)
            return 0;
        if((root->left==NULL) && (root->right==NULL))
            return root->data;
        int lsum = SumOfLeftSubTree(root->left);
        int rsum = SumOfLeftSubTree(root->right);
        root->data=root->data+lsum;
        return root->data+rsum;
    }
    int SumOfSubTree(node * root)
    {
        if(root==NULL)
            return 0;
        if((root->left==NULL) && (root->right==NULL))
            return root->data;
        int lsum = SumOfLeftSubTree(root->left);
        int rsum = SumOfLeftSubTree(root->right);
        root->data=root->data+lsum+rsum;
        return root->data;
    }
    node* mergeBinaryTrees(node *t1,node *t2)
    {
       if (!t1) 
        return t2; 
    if (!t2) 
        return t1; 
    t1->data += t2->data; 
    t1->left = mergeBinaryTrees(t1->left, t2->left); 
    t1->right = mergeBinaryTrees(t1->right, t2->right); 
    return t1; 
    }
    
};
int main()
{
    
    Tree t;
    node* root = t.createNode(10);
    t.insertIntoBinaryTree(root,20);
    t.insertIntoBinaryTree(root,30);
    t.insertIntoBinaryTree(root,40);
    cout<<"before left sum updataion"<<endl;
    t.inorderTraversal(root);
    t.SumOfLeftSubTree(root);
    cout<<endl;
    cout<<"after left sum updataion"<<endl;
    t.inorderTraversal(root);
    cout<<endl;
    cout<<"after all sum updataion"<<endl;
    t.SumOfSubTree(root);
    t.inorderTraversal(root);
    cout<<endl;
    cout<<"two trees merging"<<endl;
    Tree t2;
    node *root1=t2.createNode(1);
    t2.insertIntoBinaryTree(root1,2);
    t2.insertIntoBinaryTree(root1,3);
    //t2.insertIntoBinaryTree(root1,4);
    t2.mergeBinaryTrees(root,root1);
    t2.inorderTraversal(root);
    return 0;
}
