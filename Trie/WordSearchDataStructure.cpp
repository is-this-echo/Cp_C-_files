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
    

class WordDictionary
{
    struct Node;
    Node* root;

    struct Node
    {
        char ch;
        unordered_map<char, Node*> mp;
        bool isTerminal;

        Node(char ch) : ch(ch), isTerminal(false) {}
    };

    bool dfs(const string& word, Node* root)
    {
        for (int idx = 0; idx < word.length(); ++idx)
        {
            char ch = word[idx];
            if (ch != '.')
            {
                if (!root->mp.contains(ch))
                    return false;

                root = root->mp[ch];
            }
            else
            {
                for (const auto& [ch, node] : root->mp)
                {
                    if (dfs(word.substr(idx + 1), node))
                        return true;
                }
                return false;
            }
        }
        return root->isTerminal;
    }

public:
    WordDictionary() : root(new Node('\0')) {}

    void addWord(string word)
    {
        Node* temp = root;
        for (const char ch : word)
        {
            if (!temp->mp.contains(ch))
            {
                temp->mp[ch] = new Node(ch);
            }
            temp = temp->mp[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        return dfs(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

    
int main()
{
    fastio();

    return 0;
}