#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void inorder(BinaryTreeNode<int> *root , vector<int> &ans) {
    if(root == NULL)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

void preorder(BinaryTreeNode<int> *root , vector<int> &ans) {
    if(root == NULL)
        return;
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}

void postorder(BinaryTreeNode<int> *root , vector<int> &ans) {
    if(root == NULL)
        return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int> > ans;
    vector<int> a1,a2,a3;
    inorder(root,a1);
    preorder(root,a2);
    postorder(root,a3);
    ans.push_back(a1);
    ans.push_back(a2);
    ans.push_back(a3);
    return ans;
}
