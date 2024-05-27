#include<iostream>
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


pair<int,int>  maxSubsetSum(Node* root){
    if(root==NULL)
        return {0,0};

    // pair = <include,exclude>
    pair<int,int> l = maxSubsetSum(root->left);
    pair<int,int> r =  maxSubsetSum(root->right);
    
    int inc = root->val + l.second + r.second ;
    int exc = max(l.first, l.second) + max(r.first, r.second);

    return {inc,exc};
}


int main()
{   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->right->right = new Node(6);

    auto x = maxSubsetSum(root);
    cout<<max(x.first,x.second);
    
    return 0;
}