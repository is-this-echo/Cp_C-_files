#include<iostream>
#include<queue>
using namespace std;


class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=nullptr;
    }
};

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
			cout << current->data << " ";
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

void PrintAtLevelK(Node* root, int k){

    if(root==NULL)
        return;
    
    if(k==0)
        cout<<root->data<<" ";

    PrintAtLevelK(root->left,k-1);
    PrintAtLevelK(root->right,k-1);
}

int main()
{
    Node* root = new Node(1);

    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->left->right = new Node(5);
    root->right->right= new Node(6);
    root->left->right->left= new  Node(7);

    BFSTraversal(root);
    cout<<"\n";
    PrintAtLevelK(root,2);

    return 0;
}