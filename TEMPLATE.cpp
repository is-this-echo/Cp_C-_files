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
    
   
class Node{
public:
    int val;
    Node *next;

    Node(int d){
        val = d;
        next = nullptr;
    }
 };


Node* revl(Node *head, Node *node){
    if(node->next==NULL){
        head = node;
        return node;
    }
    
    Node*n = revl(head, head->next);
    n->next = node;
    node->next = NULL;
    
    return n;
}
    

int main() {
    fastio();

    Node *li = new Node(1);
    
    li->next = new Node(2);
    li->next->next = new Node(3);
    li->next->next->next = new Node(4);

    auto x = revl(li,li);

    
    return 0;
}