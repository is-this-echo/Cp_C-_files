
/* Given a binary tree T, find the maximum path sum.
The path may start and end at any node in the tree.

1 <= Number of Nodes <= 7e4
-1000 <= Value of Node in T <= 1000
Input :
       1
      / \
     2   3
Output : 6, The path with maximum sum is: 2 -> 1 -> 3 */

#include<iostream>
#include<queue>
using namespace std;


class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;

	// left=right=NULL;

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

int maxPathSum(Node* root){

}


int main()
{
    
    return 0;
}