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

 // Given head of a linked list, you need to group odd and even indexed nodes, connect them 
 // and return the head of the resulting LL, pointer manipulations are to be done inplace.
class Node
{
public: 
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};


void solve(Node* head)
{
    Node *odd, *even, *temp;
    odd = head;
    even = head->next;
    temp = even;

    while (odd && odd->next && even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = temp;
}


void printLL(Node* head)
{
    while(head)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"Null";
    cout<<"\n\n";
}


// 328. Odd Even Linked List, O(n) time complexity and O(1) space complexity
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
class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        using Node = ListNode;

        if (!head)
            return nullptr;

        Node* odd = head;
        Node* even = head->next;
        Node* evenStart = even;

        while (even && odd)
        {
            odd->next = even->next;
            if (odd->next)
                odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenStart;
        return head;
    }
};

// i = 7
// j = null
// 2->3->6->7
// 1->5->4->null

/*
odd = 7
even = null
1->3->5->7->2->4->6->8->null
*/


int main() {
    fastio();

    Node *n = new Node(1);
    n->next = new Node(2);
    // n->next->next = new Node(3);
    // n->next->next->next = new Node(4);
    // n->next->next->next->next = new Node(5);
    // n->next->next->next->next->next = new Node(6);
    // n->next->next->next->next->next->next = new Node(7);

    printLL(n);
    solve(n);
    printLL(n);

    return 0;
}