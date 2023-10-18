#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left=right=NULL;
    }
    
};

Node* levelOrderBuild(){
    int d,c1,c2;
    queue<Node*> q;

    cin>>d;
    if(d==-1)
        return NULL;

    Node* root = new Node(d);
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        cin>>c1>>c2;
        
        if(c1!=-1){
            curr->left = new Node(c1);
            q.push(curr->left);
        }

        if(c2!=-1){
            curr->right = new Node(c2);
            q.push(curr->right);
        }
        
    }
    return root;
}


void iterativePreOrder(Node* root){
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* curr = s.top();
        cout<<curr->val<<" "; 
        s.pop();

        if(curr->right)
            s.push(curr->right);
        
        if(curr->left)
            s.push(curr->left);
    }

}


int main()
{
    Node* root = levelOrderBuild();
    // 10 11 -20 15 12 0 9 -1 -1 -1 -1 16 18 -1 -1 -1 -1 -1 -1

    iterativePreOrder(root);

    return 0;
}