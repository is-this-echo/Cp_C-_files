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
    
 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
}; 
*/

class Solution {
    using Llist = pair<Node*, Node*>; // head, tail

    // Intuition : Consider we already have a function that flattens a multi-level
    // linked list, now make the necessary node connections once our black-box 
    // function returns the head and tail of the flattened list.
    // Now, magically you problem is solved, think of edge cases and also don't forget
    // the base case of all backtracking problems, if (!head) return {nullptr, nullptr};
    Llist helper(Node* head)
    {
        Node *temp = head, *prev = head;
        Llist getList = {nullptr, nullptr};

        while (temp)
        {
            if (temp->child)
            {
                getList = helper(temp->child);
                temp->child = nullptr;
                Node* nextPtr = temp->next;

                temp->next = getList.first;
                getList.first->prev = temp;
                getList.second->next = nextPtr;

                if (nextPtr) // consider case when last node has child
                    nextPtr->prev = getList.second;
            }
            prev = temp;
            temp = temp->next;
        }
        return {head, prev};
    }

public:
    Node* flatten(Node* head) {
        Llist ans = helper(head);

        return ans.first;
    }
};

    
int main() {
    fastio();
    
    return 0;
}