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
    char ch;
    unordered_map<char, Node*>mp;
    bool isTerminal;

    Node(char x) : ch(x), isTerminal(false) {};
 };


class SuffixTrie
{
    Node* root;
public:
    SuffixTrie(): root(new Node('\0')) {};

    void insert_helper(string word)
    {
        Node* temp = root;
        for (auto c: word)
        {
            if (temp->mp.count(c) == 0)
            {
                Node* n = new Node(c);
                temp->mp[c] = n;
            }
            temp = temp->mp[c];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node* temp = root;
        for (auto c : word)
        {
            if (temp->mp.count(c) == 0)
                return false;
            
            temp = temp->mp[c];
        }
        return temp->isTerminal;
    }

    void insert(string word)
    {
        for (int i=0; word[i]!='\0'; ++i)
            insert_helper(word.substr(i));
    }
};


int main() {
    string input = "hello";
    string suffixes[] = {"hello", "eloo", "o", "ell"};

    SuffixTrie t;
    t.insert(input);
    
    for (auto sfx : suffixes)
    {
        if (t.search(sfx))
            cout << "Yes \n";
        else
            cout << "No \n";
    }
    return 0;
}