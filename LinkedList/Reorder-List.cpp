/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rev(ListNode*head){
        if(head==nullptr)
            return head;

        ListNode *prev =NULL,*curr=head, *fwd=head;

        while(fwd){
            fwd = fwd->next;
            curr->next  = prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }


    void reorderList(ListNode* head) {
        ListNode *slow, *fast;
        slow = head; fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast=fast->next->next;
        }

        ListNode *ll2 = rev(slow->next);
        slow->next=NULL;
        ListNode *p1=head, *p2=ll2, *tail=ll2;

        while(tail){
            p1 = head->next;
            p2 = tail->next;

            head->next = tail;
            tail->next = p1;
            head = p1; tail=p2;
        }

    }
};



int main() {
    fastio();

    return 0;
}