#include<iostream>
#include<climits>
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


bool compare(Node* root, long int lb, long int rb){    
    if(root==nullptr)
        return true;
    
    if(lb < root->val && root->val < rb){
        bool lstree = compare(root->left,lb,root->val);
        bool rstree = compare(root->right,root->val,rb);
        
        return lstree && rstree;
    }
    else
        return false;
}


bool isValidBST(Node* root) {
    if(root==nullptr)
        return true;
    
    long int lb = LONG_MIN;
    long int rb = LONG_MAX;
    
    return compare(root,lb,rb);
}



int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->right->left = new Node(4);
    root->right->right = new Node(8); 

    if(isValidBST(root))
        cout<<"Valid BST!!"<<endl;
    else
        cout<<"Invalid BST!!"<<endl;

  
    return 0;
}