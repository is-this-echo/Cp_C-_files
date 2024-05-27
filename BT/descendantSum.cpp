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


void BFSTraversal(Node* root) {
	queue<Node*>q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		Node* current = q.front();
		if (current == NULL) {
			cout << endl;
			q.pop();

			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << current->val << " ";
			q.pop();

			if (current->left) {
				q.push(current->left);
			}
			if (current->right) {
				q.push(current->right);
			}
		}
	}
	return;
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


int descendantSum(Node *root){
    if(root==NULL)
        return 0;
        
    if(!root->left && !root->right)
        return root->val;
    
    int temp = root->val;
    root->val = descendantSum(root->left)+descendantSum(root->right);

    return temp+root->val;

}


int main()
{
    Node* root = levelOrderBuild();
    // 10 11 -20 15 12 0 9 -1 -1 -1 -1 16 18 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    BFSTraversal(root);
    cout<<endl;
    int a = descendantSum(root);
    cout<<endl;
    BFSTraversal(root);

    return 0;
}