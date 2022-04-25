#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;


// Leetcode 212. Word Search II   
 
class Node{
public:
    char ch;
    unordered_map<char,Node*>mp;
    bool isTerminal;
    string word;

    Node(char c){
        ch=c;
        isTerminal = false;
        // to keep track of the word formed so far
        word = "";
    }
};
 

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node('\0');
    }

    void insert(string word){
        Node* temp = root;

        for(char ch : word){
            if(temp->mp.count(ch)==0){
                Node* n = new Node(ch);
                temp->mp[ch] = n;
            }
            temp = temp->mp[ch];
        }
        temp->isTerminal = true;
        temp->word = word;
    }
};


 void dfs(vector<vector<char>>& board, vector<string>& words, vector<vector<bool>>&vis,
        unordered_set<string>&ans, Node* root, int i, int j, int m, int n){
        
        char ch = board[i][j];

        // base case, if char not in trie
        if(root->mp.count(ch)==0){
            return;
        }

        // if char found in trie
        vis[i][j] = true;
        root = root->mp[ch];
         
        if(root->isTerminal==true){
            ans.insert(root->word);
        }
    
        // perform 8-way dfs
        int dx[] = {0,0,1,1,1,-1,-1,-1};
        int dy[] = {1,-1,0,1,-1,0,1,-1};

        for(int k=0;k<8;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

        // condition to check for visited  or out of bounds
            if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                dfs(board,words,vis,ans,root,nx,ny,m,n);
            }
        }

        // backtracking
        vis[i][j] = false;
        return;
    }


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<char>> board = {{'o','a','a','n'},
                                  {'e','t','a','e'},
                                  {'i','h','k','r'}, 
                                  {'i','f','l','v'}};

    vector<string> words = {"oath","pea","eat","rain"};

    int m = board.size(), n = board[0].size();
    unordered_set<string> ans;
    vector<vector<bool>>vis(m,vector<bool>(n,false));    
    Trie t;

    for(auto word : words)
        t.insert(word);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dfs(board,words,vis,ans,t.root,i,j,m,n);
        }
    }
    
    for(auto word : ans){
        cout<<word<<"\n";
    }

    return 0;
}