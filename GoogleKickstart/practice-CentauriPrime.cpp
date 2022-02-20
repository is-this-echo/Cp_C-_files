#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
bool isVowel(char s){
    if(s =='a' || s =='e' || s =='i' || s =='o' || s =='u')
        return true;
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin>>tc;

    for(int tt=0;tt<tc;tt++){
        string s;
        cin>>s;

        int n = s.size();
        char ch = s[n-1];

        if(ch=='y' || ch=='Y')
            cout<<"Case "<<"#"<<tt+1<<": "<<s<<" is ruled by nobody."<<"\n";
        
        else if(isVowel(tolower(ch)))
            cout<<"Case "<<"#"<<tt+1<<": "<<s<<" is ruled by Alice."<<"\n";
        
        else
            cout<<"Case "<<"#"<<tt+1<<": "<<s<<" is ruled by Bob."<<"\n";
  
    }
    
    return 0;
}