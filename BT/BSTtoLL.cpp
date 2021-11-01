#include<iostream>
#include<utility>
using namespace std;


class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        left=right=NULL;
    }
};


class LinkedList{
public:
    Node* head;
    Node* tail;
};


LinkedList BSTtoLL(Node* root){
    LinkedList l;

    if(root==nullptr){
        l.head = l.tail =NULL;
        return l;
    }

    // Each recursive call build as LL and sets the head and tail of ll
    // based on the type of children nodes

    if(root->left ==NULL && root->right==NULL)
        l.head =l.tail=root;
    
    else if(root->left==NULL && root->right!=NULL){
        LinkedList rightLL = BSTtoLL(root->right);

        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
    }
    else if(root->right==NULL && root->left!=NULL){
        LinkedList leftLL = BSTtoLL(root->left);

        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
    }
    else{
        LinkedList leftLL = BSTtoLL(root->left);
        LinkedList rightLL = BSTtoLL(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;
        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }

    return l;
}



int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    LinkedList ll = BSTtoLL(root);
    Node* temp = ll.head;

    while(temp){
        cout<<temp->val<<"-> ";
        temp=temp->right;
    }
    cout<<"NULL";
    return 0;
}