#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
    node* findLastRight(node* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
node* helper(node* root) {
            if (root->left == NULL) 
            {
                return root->right;
            } 
            else if (root->right == NULL)
            {
                return root->left;
            } 
            node* rightChild = root->right;
            node* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
            return root->left;
    }

node* deleteNode(node* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == key) {
            return helper(root);
        }
        node *dummy = root;
        while (root != NULL) {
            if (root->data > key) {
                if (root->left != NULL && root->left->data == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->data == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    

 
pair<bool,int> isValidBst(node *root,long mini,long maxi)
{
    if(!root)return {true,-1};
    if(root->data >= maxi or root->data <= mini)return {false,root->data};

    pair<bool,int> a= isValidBst(root->left,mini,root->data);
    pair<bool,int> b=isValidBst(root->right,root->data,maxi); 
    if(a.first==false)return a;
    else if(b.first==false)return b;
    return {true,-1};
}
void print(node *root)
{
    
    if(root->left)print(root->left);
    cout<<root->data;
    if(root->right)print(root->right);
}
 

int main()
{
    struct node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->left = newNode(9);
    root->right->right = newNode(14);
 
    pair<bool,int> ans=isValidBst(root,LONG_MIN,LONG_MAX);
    if (ans.first==true)
        cout<<"Is BST";
    else{
        cout<<"Not a bst";
        node * a=deleteNode(root,ans.second);
        //cout<<ans.second;
    }
    
    
    return 0;
}