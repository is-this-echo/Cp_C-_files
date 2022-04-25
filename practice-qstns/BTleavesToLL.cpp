#include<iostream>
using namespace std;

#define ll long long
#define mod 1e9+7

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int d){
        val=d;
        left=right=nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
};
   

LinkedList BTLeavesToLL(Node* root){
     LinkedList lk;
     
    if(root==nullptr){
        lk.head=lk.tail=nullptr;
        return lk;
    }

    if(!root->left && !root->right)
        lk.head = lk.tail = root;
    

    else{
        LinkedList leftLL = BTLeavesToLL(root->left);
        LinkedList rightLL = BTLeavesToLL(root->right);

        lk.head = leftLL.head;
        leftLL.tail->right = rightLL.head;
        lk.tail = rightLL.tail;

    }

    return lk;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    LinkedList l = BTLeavesToLL(root);
    Node* head = l.head;
    Node* tail = l.tail;


    while(head){
        cout<<head->val<<" ";
        head = head->right;
    }
    
    return 0;
}