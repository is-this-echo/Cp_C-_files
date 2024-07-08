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
    
 
class Node
{
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

void InsertAtHead(Node* &head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node* n = new Node(data);
    n->next = head; 
    head = n;
}

void ReverseLLIterative(Node* &head)
{
    Node* prev = NULL;
    Node *curr = head, *fwd=head;

    while (curr)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    head = prev;
}

Node* ReverseLLRecursive(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    
    Node* revHead = ReverseLLRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return revHead;
}

void PrintLL(Node* head)
{
    while (head)
    {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << endl;
}

int main() {
    fastio();

    Node* head = NULL;

    InsertAtHead(head, 3);
    InsertAtHead(head, 0);
    InsertAtHead(head, 9);
    InsertAtHead(head, 16);
    InsertAtHead(head, 55);
    PrintLL(head);

    ReverseLLIterative(head);
    // head = ReverseLLRecursive(head);
    PrintLL(head);
    
    return 0;
}