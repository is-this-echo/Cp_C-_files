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
    

class compare{
public : 
    bool operator()(const pair<int,char>&a, const pair<int,char>&b){
        return a.first<b.first;
    }
};

class Solution { 
public:
    string reorganizeString(string str) {
        priority_queue<pair<int,char>, vector<pair<int,char>>, compare>pq;
        unordered_map<char,int>mp;

        for(char ch : str){
            mp[ch]++;
        }

        for(auto mpair : mp){
            pq.push(make_pair(mpair.second, mpair.first));
        }

        string res="";
        pair<int,char>prev = {0,0};
        
        while(!pq.empty() || prev.second!=0){

            if(pq.size()==0 && prev.second!=0){
                return "";
            }

            pair<int,char> x = pq.top(); 
            pq.pop();

            res += x.second;
            x.first -= 1;

            if(prev.second!=0){
                pq.push(prev);
                prev = {0,0};
            }

            if(x.first>0){
                prev = {x.first, x.second};
            }
        }
        return res;
    }
};
    
    
int main() {
    fastio();

    Solution st;
    string ss = "aacabbbbbb";

    cout<<st.reorganizeString(ss);

    return 0;
}