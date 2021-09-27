#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
	    left=right=NULL;
	}
};
 
Node* buildLevelOrder() {
	int d;
	queue<Node*> q;

	cin >> d;
	Node* root = new Node(d);
	q.push(root);

	while(!q.empty()){
		Node* current = q.front();
		q.pop();

		int c1, c2;
		cin >> c1 >> c2;
		if(c1!=-1){
			current->left = new Node(c1);
			q.push(current->left);
		}

		if(c2!=-1){
			current->right = new Node(c2);
			q.push(current->right);
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

// function to find sum of only left leaves
void sOLL(Node* root, int p, int &sum){
    if(root==NULL)
        return ;

    if(root->left==NULL && root->right==NULL && p==0){
        sum+=root->data;
        return ;
    }

    sOLL(root->left,0,sum);
    sOLL(root->right,1,sum);
}



int main()
{
	Node* root = buildLevelOrder();
	//sample input given in next line
	// 3 9 20 -1 -1 15 7 -1 -1 -1 -1
    int sum=0;
    sOLL(root,6,sum);
    // BFSTraversal(root);

    cout<<"Left leaves sum of tree is: "<<sum;
    return 0;
}