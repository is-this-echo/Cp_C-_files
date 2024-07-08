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
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
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

void InsertInMiddle(Node* &head, int data, int pos)
{
    if (pos == 0)
        InsertAtHead(head, data);
        
    else
    {
        Node* temp = head;
        for (int i = 1; i < pos-1; ++i)
            temp = temp->next;
        
        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void PrintLL(Node* head)
{
    while (head != NULL)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
}
  
int main() {
    fastio();

    Node* head = NULL;

    PrintLL(head);
    InsertAtHead(head, 5);
    InsertAtHead(head, 1);
    InsertAtHead(head, 0);
    InsertAtHead(head, 24);
    InsertAtHead(head, 7);
    InsertInMiddle(head, 33, 3);
    PrintLL(head);
    
    return 0;
}