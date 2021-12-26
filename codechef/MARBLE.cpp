#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    


bool  isVowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return true;

    return false;
}


void solve(){
    int n;
    cin>>n;

    string s,p;
    cin>>s>>p;

    string c=s , d=p;
    int ans=INT_MAX,oprtn=0;

    for(char ch='a';ch<='z';ch++){
        for(int i=0;i<n;i++){
            if(s[i]=='?')
                s[i]=ch;
            if(p[i]=='?')
                p[i]=ch;
        }

        oprtn=0;

        for(int i=0;i<n;i++){
            if(s[i]==p[i])
                continue;

            else if(isVowel(s[i]) && isVowel(p[i]))
                oprtn+=2;

            else if(!isVowel(s[i]) && !isVowel(p[i]))
                oprtn+=2;
            
            else
                oprtn+=1;        
        }
        ans = min(ans,oprtn);
       // cout<<ans;
        s=c,p=d;
    }

    cout<<ans<<'\n';

}



    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}