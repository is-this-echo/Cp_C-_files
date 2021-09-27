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


void NodesAtDistanceK(Node* root, Node* target, int k){


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
    root->left->right->right= new  Node(8);
    root->left->right->right->left = new Node(9);
    root->left->right->right->right = new Node(10);

    Node* target = root->left->right;
    int k=2;

    BFSTraversal(root);
    cout<<"\n";
    NodesAtDistanceK(root,target,k);

    return 0;
}