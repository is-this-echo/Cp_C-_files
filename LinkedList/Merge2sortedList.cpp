#include<iostream>
using namespace std;

#define ll long long
#define mod 998244353

double eps = 1e-12;
    
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {   
    if(!l1 && !l2)
        return nullptr;
    
    if(!l1 || !l2)
        return l1==nullptr ? l2 : l1;
    
    ListNode *p1, *p2,*head,*temp;
    p1=l1;p2=l2;
    
    if(p1->val <= p2->val){
        head = l1;
        p1=p1->next;
    }
        
    else {
        head=l2;
        p2=p2->next;
    }
        
    temp = head;       
    while(p1!=nullptr && p2!=nullptr){
        if(p1->val <=p2->val){
            temp->next=p1;
            temp=temp->next;
            p1=p1->next;
        }
        else{
            temp->next=p2;
            temp=temp->next;
            p2=p2->next;
        }
    }
    while(p1!=nullptr){
        temp->next=p1;
        // below 2 lines are not necessary as all elements of linked list lies in p1
        temp=temp->next;
        p1=p1->next;
    }
    while(p2!=nullptr){
        temp->next=p2;
    // below 2 lines are not necessary as all elements of linked list lies in p12
        temp=temp->next;
        p2=p2->next;
    }
    return head;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* x = mergeTwoLists(l1,l2);

    while(x!=nullptr){
        cout<<x->val<<" ";
        x=x->next;
    }
 
    return 0;
}