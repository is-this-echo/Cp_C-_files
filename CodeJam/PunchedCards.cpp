/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": "<<"\n";}
    
 
 void printplus(int x){
     cout<<"+";
     for(int i=0;i<x;i++){
        cout<<"-";
        cout<<"+";
     }
     cout<<"\n";
 }


 void printdots(int x, int i){
     if(i==0)
        cout<<".";
    else
        cout<<"|";

     for(int i=0;i<x;i++){
         cout<<".";
         cout<<"|";
     }
     cout<<"\n";
 }


void solve(){

    int r,c;
    cin>>r>>c;

    cout<<"..";
    printplus(c-1);

    for(int i=0;i<r;i++){
        printdots(c,i);
        printplus(c);
    }

}
    


int main() {
    fastio();;

    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        google(i);
        solve();
    }
    return 0;
}