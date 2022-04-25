#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
// Leetcode 25. Reverse Nodes in k-Group 


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


 // function to undo reversal if nodes are not multiple of k
ListNode* rev(ListNode* temp){
    ListNode *prev=nullptr, *curr=nullptr, *fwd=nullptr;
    curr=fwd=temp;
    
    while(curr){
        fwd = curr->next;
        curr->next = prev;
        prev=curr;
        curr=fwd;
    }
    return prev;
}


// main logic function
ListNode* helper(ListNode* head, int k){
    if(head==nullptr)
        return head;
    
    ListNode *prev=nullptr, *curr=nullptr, *fwd=nullptr;
    curr=fwd=head;
    int cnt=k;
    
    while(curr && cnt>0){
        fwd = curr->next;
        curr->next = prev;
        
        prev=curr;
        curr=fwd;
        cnt--;
    }
    
    // if no. of nodes are not multiple of k, then undo the reversal
    if(cnt>0)
        prev = rev(prev);
    
    else
        head->next = reverseKGroup(curr,k);
    
    return prev;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    return helper(head,k);
}

    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}