
// 19. Remove Nth Node From End of List

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    


class Node{
public:

    int val;
    Node* next;
};

 
Node* removeNthFromEnd(Node* head, int n) {
    // a map can also be used, simple code than this one
    stack<Node*> stk;
    Node *temp = head, *last=nullptr;
    
    while(head){
        stk.push(head);
        head= head->next;
    }

    while(n--){
        last = stk.top();
        stk.pop(); 
    }
    
    if(stk.empty())
        return last->next;
    
    stk.top()->next = last->next;
    return temp;
    
}
  
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



    
    return 0;
}