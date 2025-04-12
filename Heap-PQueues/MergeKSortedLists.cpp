#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;


class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        next=nullptr;
    }
};

 
class Compare{
public:
    bool operator()(Node* a, Node* b){
        return a->val > b->val;
    }  
};


Node* mergeKLists(vector<Node*>& lists) {
    priority_queue<Node*,vector<Node*>,Compare>pq;

    if(lists.size()==0)
        return NULL;

    for(int i=0;i<lists.size();i++){
        Node* head=lists[i];
        while(head){
            pq.push(head);
            head=head->next;
        }
    }

    if(pq.empty())
        return NULL;
        
    Node* temp=pq.top();
    Node* head = temp;
    pq.pop();
    
    while(!pq.empty()){
        temp->next=pq.top();
        pq.pop();
        temp=temp->next;
    }

    temp->next=NULL;
    return head;
}



void solve(vector<vector<int>>lists){
    priority_queue<int,vector<int>,greater<int>>pq; 
    // min-heap

    for(auto list : lists){
        for(auto i : list){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

// Using k-pointer approach where the k-pointers are in a heap
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    class Triplet
    {
    public:
        int element;
        int arrIdx;
        ListNode* ptr;

        Triplet(int x, int y, ListNode* ptr) : element(x), arrIdx(y), ptr(ptr) {}
    };

    class Compare
    {
    public :
        bool operator()(Triplet a, Triplet b)
        {
            return a.element > b.element;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
    
        priority_queue<Triplet, vector<Triplet>, Compare> pq;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
                pq.push(Triplet(lists[i]->val, i, lists[i]));
        }

        if (pq.empty())
            return nullptr;

        Triplet x = pq.top();
        pq.pop();

        int elem = x.element;
        int arrIdx = x.arrIdx;
        ListNode* elemPtr = x.ptr;

        if (elemPtr->next)
            pq.push(Triplet(elemPtr->next->val, arrIdx, elemPtr->next));

        ListNode* head{nullptr};
        ListNode* temp = elemPtr;
        head = temp;

        while (!pq.empty())
        {
            x = pq.top();
            pq.pop();

            elem = x.element;
            arrIdx = x.arrIdx;
            elemPtr = x.ptr;

            temp->next = elemPtr;
            temp = temp->next;

            if (elemPtr->next)
                pq.push(Triplet(elemPtr->next->val, arrIdx, elemPtr->next));
        }
        return head;
        
    }
};
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    vector<Node*>lists;
    Node* l1 = new Node(-1);
    l1->next = new Node(-1);
    l1->next->next= new Node(-1);

    Node* l2 = new Node(-2);
    l2->next = new Node(-2);
    l2->next->next= new Node(-1);

    lists.push_back(l1);
    lists.push_back(l2);

    mergeKLists(lists);
    
   // vector<vector<int>> lists = {{1,3,4}, {1,4,5}, {2,6}};
   // solve(lists);

    return 0;
}