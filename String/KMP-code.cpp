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
    
 
// O(n+m) time complexity

int  kmp(string s, int len){
    int n = s.length();

    // 1-indexed array
    
    vector<int>lps(n+1);
    int i=0,j=-1;
    lps[0]=-1;

    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j = lps[j];
        }
        i++; j++;
        lps[i] = j;
    }
 
    // for(int i=0;i<=n;i++){
    //     cout<<lps[i]<<" ";
    // }

    for(int i=1;i<=n;i++){
        if(lps[i]==len){
            return 1;
        }
    }

   return 0;
}


    
int main() {
    fastio();

    string pat, txt;
    cin>>pat;
    cin>>txt;

    // if the pattern is present in the string, it gets reflected in the lps array, 
    // as that pattern will always be present as a suffix, also if the pattern or the string contains
    // the # symbol, we can use any other symbol instead to form the bigger string
    int pat_len = pat.length();
    bool ans = kmp(pat + "#" + txt, pat_len);

    cout<<(ans==1 ? "YES" : "NO");

    
    return 0;
}