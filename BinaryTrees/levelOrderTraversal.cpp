#include<iostream>
#include<queue>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;
    //constructor:-
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root) {
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1)
        return NULL;
    cout<<"Enter data for inserting in left of: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of: "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node *root) {
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        cout<<temp->data<<" ";
    }
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    return 0;
}
