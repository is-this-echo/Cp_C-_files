/*
 Reverse linked list in groups of k

Input : 	1->2->3->4->5->6->7->8->NULL
Output : 	3->2->1->6->5->4->8->7->NULL

*/

#include<iostream>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;


class Node{
public:
    int val;
    Node* next;
};


Node* reverseK(Node* head, int k){
	int count=0;
	Node *prev=NULL, *curr=head, *fwd=head;

    while(curr!=NULL && count<k){
        fwd = fwd->next;
        curr->next = prev;
        
        prev = curr;
        curr=fwd;
        count++; 
    }

	if(curr!=NULL)
        head-> next  =reverseK(curr, k);

	return prev;
}


void push(Node** head_ref, int new_data){
    Node* new_node = new Node();

    new_node->val = new_data;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}


void printList(Node* node){
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    Node* head = NULL;
    //push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given linked list \n";
    printList(head);
    head = reverseK(head, 3);

    cout << "\nReversed Linked list \n";
    printList(head);

    return 0;
}