 #pragma GCC optimize("Ofast")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
 #pragma GCC optimize("unroll-loops")
 #include<bits/stdc++.h>
 using namespace std;
 
 #define ll long long
 #define INF 2e18
 #define mod 998244353
 double eps = 1e-12;
     
  
 
 void solve(){
     string s1,s2;
     cin>>s1>>s2;

     int val=0;

     for(char &ch:s1)
        ch = tolower(ch);

     for(char &ch:s2)
        ch = tolower(ch);

    for(int i=0;i<s1.length();i++){
        if(s1[i]>s2[i]){
            val=1;
            break;
        }
            
        else if(s1[i]<s2[i]){
            val=-1;
            break;
        }
            
        else
            continue;
    }
    cout<<val;
 }
     


 int main() {
     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

     solve();
     
     return 0;
 }