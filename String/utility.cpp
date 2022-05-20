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
    
 

vector<string>split(string str, char ch){
    int n = str.length();
    vector<string>ans;
    string temp="";

    for(int i=0;i<n;i++){
        if(str[i]==ch){
            ans.push_back(temp);
            temp.erase();
            while(str[i]==ch && i<n) i++;
        }

       if(i<n) temp.push_back(str[i]);
    }

    ans.push_back(temp);

    return ans;
}



void tokenize(string s, string del = " "){
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        cout << s.substr(start, end - start) << endl;
        start = end + del.size();
        end = s.find(del, start);
    }
    cout << s.substr(start, end - start);
}


    
int main() {
    fastio();

    // string s = "Hi$%do$%you$%do$%!";

    // auto output = split(s,'-');

    // for(auto i : output)
    //     cout<<i<<" ";

    // Takes C++ string with any separator
    string a = "Hi$%do$%you$%do$%!";
    tokenize(a, "$%");

    return 0;
}