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
    
 
// Time Complexity : O(nloglogn)

int EratosthenesSieve(int n){
    bool isPrime[1000001];
    int cnt=0;
    
    memset(isPrime,1,sizeof(isPrime));

    isPrime[0]=false;
    isPrime[1]=false;
    
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]==true){
            for(ll j = 1LL*i*i; j<=n; j+=i)
                isPrime[j]=false;     
        }
    }
    
    for(int i=2;i<=n;i++)
        if(isPrime[i])
            cnt++;
            
    return cnt;
}

    
int main() {
    fastio();

    cout<<EratosthenesSieve(10);
    
    return 0;
}