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
void google(int t) {cout << "Case #" << t << ": ";}
    
 

void solve(){
    int arr[3][4];

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

    int c_min=INT_MAX, m_min=INT_MAX, y_min=INT_MAX, k_min=INT_MAX;

    for(int i=0;i<3;i++){
        c_min = min(arr[i][0],c_min);
        m_min = min(arr[i][1],m_min);
        y_min = min(arr[i][2],y_min);
        k_min = min(arr[i][3],k_min);
    }
    
    int sum = c_min + m_min + y_min + k_min;
    int c=0,y=0,m=0,k=0;

    if(sum<1000000){
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }

    sum = 1000000;
    c = c_min;
    sum -= c;

/*
    vector<int>ink(4,INT_MAX);
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++) 
        ink[j] = min(arr[i][j],ink[j]);
    }

    sum = 1e6;
    for(int i=0;i<4;i++){
        ink[i] = min(ink[i],sum);
        sum -= ink[i];
    }
*/

    if(sum>m_min){
        sum-= m_min;
        m = m_min;
    }

    else{
        m = sum;
        cout<<c<<" "<<m<<" "<<y<<" "<<k<<"\n";
        return;
    }
    
    if(sum>y_min){
        sum-= y_min;
        y = y_min;
    }

    else{
        y = sum;
        cout<<c<<" "<<m<<" "<<y<<" "<<k<<"\n";
        return;
    }
    
    if(sum>k_min){
        sum-= k_min;
        k = k_min;
    }

    else{
        k = sum;
        cout<<c<<" "<<m<<" "<<y<<" "<<k<<"\n";
        return;
    }
    
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