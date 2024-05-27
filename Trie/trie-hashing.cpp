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
    unordered_map<char, Node*> child;
    bool isTerminal;

    Node(char ch) : ch(ch), isTerminal(false) {}
};


class Trie 
{
public:
    Node * root;
    Trie() : root(new Node('\0')) {};

    void insert(string word)
    {
        Node* temp = root;
        for (auto ch : word)
        {
            if (temp->child.count(ch) == 0)
            {
                Node * n = new Node(ch);
                temp->child[ch] = n;
            }
            temp = temp->child[ch];
        }
        temp->isTerminal = true;
    }
};

// Time complexity : O(w*n + d*w) : w*n for trie creation, d*w for searching in trie
void searchHelper(Trie& t, const string& document, int i, unordered_map<string, bool>& mp)
{
    Node* temp = t.root;
    for (int j = i; j < document.length(); ++j)
    {
        char ch = document[j];
        if (temp->child.count(ch) == 0) return;

        temp = temp->child[ch];
        if (temp->isTerminal)
        {
            string out = document.substr(i, j-i+1);
            mp[out] = true;
        }
    }
    return;
}

void documentSearch(const string& document, const array<string, 5>& words)
{
    // 1.Insert all words in the trie
    Trie t;
    for (const auto w : words)
        t.insert(w);

    // 2.Searching the Trie for the documents
    unordered_map<string, bool> mp;
    for (int i = 0; i < document.length(); ++i)
        searchHelper(t, document, i, mp);
    
    // 3.Check which words are present in the hashmap
    for (const auto w : words)
        cout << w << " : " << (mp[w] ? "True" : "False") << endl;
      
    return;
}


int main() {

    const string& document = "little cute cat loves to code in c++, java & python";
    const array<string, 5>& words = {"cute cat", "ttle", "cat", "quick", "big"};

    documentSearch(document, words);
    
    return 0;
}