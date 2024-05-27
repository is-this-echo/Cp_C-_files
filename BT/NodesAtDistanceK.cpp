#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val=data;
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

// to make hashmap of nodes mapped to their parent
void parentMap(Node* root, unordered_map<int, Node*> &m, Node* parent){
    if(root==nullptr)
        return;
    
    m[root->val]=parent;
    parentMap(root->left,m,root);
    parentMap(root->right,m,root);
}


// function uses BT as an undirected graph and using bfs we traverse till level k
void NodesAtDistanceK(Node* root, Node* target, int k, unordered_map<int,Node*> &m){
    unordered_map<int,bool> visited;
    queue<Node*>q;
    q.push(target);
    q.push(NULL);

    while(!q.empty() && k>0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL ){
            k--;
            if(!q.empty())
                q.push(NULL);
        }

        else {    
            visited[curr->val] = true;
            if(curr->left && !visited.count(curr->left->val))
                q.push(curr->left);

            if(curr->right && !visited.count(curr->right->val))
                q.push(curr->right);

            if(m[curr->val] && !visited.count(m[curr->val]->val))
                q.push(m[curr->val]);
        }

    }
    cout<<"Nodes at "<<k<<" distance from the target node -> "<<endl;
    while(q.front()!=NULL && !q.empty()){
        cout<<q.front()->val<<endl;
        q.pop();
    }
}



int main()
{
    Node* root = new Node(1);
    unordered_map<int,Node*> m;

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
    int k=1;

    // BFSTraversal(root);
    // cout<<"\n";
    parentMap(root,m,nullptr);
    NodesAtDistanceK(root,target,k,m);

    return 0;
}