#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 // 92. Reverse Linked List II, basically reverse ll in a given range 

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


// function to reverse linked list upto k nodes
pair<ListNode*,ListNode*> rev(ListNode* temp, int k){
    ListNode *prev=nullptr, *curr=temp, *fwd=temp;
    
    while(curr && k>0){
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        k--;
    }
    return {prev,curr};
}


ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head)
        return nullptr;
    
    int k = right-left+1;
    ListNode *l_ptr = head;
    
    // handling edge case, when left pointer starts from the first element
    if(left==1){
        auto x = rev(l_ptr,k);
        ListNode *prev = x.first, *curr = x.second;
        head->next = curr;
        
        return prev;
    }
    

    while(l_ptr){
        left--;
        
        if(left==1){
            ListNode* temp = l_ptr->next;
            auto x = rev(temp,k);
            
            ListNode *prev = x.first, *curr = x.second;
            l_ptr->next = prev;
            temp->next = curr;
            break;
        }
        
        l_ptr = l_ptr->next;
    }
    
    return head;
}
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}