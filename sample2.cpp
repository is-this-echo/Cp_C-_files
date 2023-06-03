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



class Node {
public:
    char ch;
    unordered_map<char,Node*>mp;
    bool isTerminal;

    Node(char c) : ch(c), isTerminal(false){}; 
};

class Trie {
   Node * root;
public:
    Trie(){
        root = new Node('\0');
    }

    void insert(string str)
    {
        Node *temp = root;
        for(char ch : str){
            if(temp->mp.count(ch) == 0){
                Node *n  = new Node(ch);
                temp->mp[ch] = n;
            }
            temp = temp->mp[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string str)
    {
        Node *temp = root;
        for(char ch : str){
            if(temp->mp.count(ch) == 0){
                return false;
            }
            temp = temp->mp[ch];
        }
        return temp->isTerminal;
    }
};


int main() {
    fastio();

    Trie t;
    int n;
    string query;
    
    string words[] = {"apple", "lichi", "mango", "banana", "guava", "apricot", "orange"};
    string queries[] = {"dragon fruit", "ape", "litter", "mang", "orange"};
    
    for(auto word : words)
        t.insert(word);
    
    while(cin>>query){
        if(t.search(query))
            cout<<"Word found"<<endl;
        else 
            cout<<"Not found"<<endl;
    }
    
    return 0;
}