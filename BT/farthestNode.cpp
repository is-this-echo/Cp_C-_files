/*
Given a tree, for each node, output the distance to the node farthest from it.
Example:
1->2
1->3
Output: 1 2 2
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int x){
        val=x;
        left=right=nullptr;
    }
};

int depth(Node* root, unordered_map<int,int> &m){
    if(root==nullptr)
        return -1;
    
    int h1 = depth(root->left,m);
    int h2 = depth(root->right,m);

    int ans = max(h1,h2)+1;
    m[root->val] = ans;

    return ans;
}


void farthestNode(Node* root, unordered_map<int,int> &m, int parent){
    if(root==nullptr)
        return;
    
    farthestNode(root->left,m,root->val);
    m[root->val] = 1 + m[parent];
    



}



int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(7);
    root->left->right = new Node(3);

    unordered_map<int,int>  m;
    depth(root,m);

    for(auto nodePair : m)
        cout<<nodePair.first<<" -> "<<nodePair.second<<endl;
    

    return 0;
}