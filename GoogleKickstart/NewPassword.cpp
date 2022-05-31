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
    
 

void solve(){
    int n;
    string s;

    cin>>n;
    cin>>s;

    bool isLow=false, isUp=false, isSpcl = false, isDig=false;

    for(int i=0;i<n;i++){
        if(s[i]>='a' && s[i]<='z')
            isLow = true;

        if(s[i]>='A' && s[i]<='Z')
            isUp = true;
        
        if(s[i]=='@' || s[i]=='#' || s[i]=='*' || s[i]=='&')
            isSpcl = true;
        
        if(s[i]>='0' && s[i]<='9')
            isDig = true;
    } 

    if(!isLow)
        s+='a';

    if(!isUp)
        s+='A';

    if(!isSpcl)
        s+='#';

    if(!isDig)
        s+='9';

    while((int)s.length()<7){
        s += '3';
    }

    cout<<s<<"\n";

}


    
int main() {
    fastio();

    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        google(i);
        solve();
    }
    
    return 0;
}