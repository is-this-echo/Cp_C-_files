#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
// leetcode 204. Count Primes
// To find prime numbers in range 1 to n, use the sieve of Eratosthenes technique
// TC = O(nloglogn)


int sieve(int n){
    bool isPrime[n];
    int cnt=0;
    
    memset(isPrime,1,sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;
    
    for(int i=2;i*i<n;i++){
        if(isPrime[i]==true){
            for(int j=i*i;j<n;j+=i)
                isPrime[j]=false;     
        }
    }
    
    for(int i=0;i<n;i++)
        if(isPrime[i])
            cnt++;
            
    return cnt;
}

    
    
int countPrimes(int n) {
    if(n==0 || n==1)
        return 0;
    
    return sieve(n);
}




int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}