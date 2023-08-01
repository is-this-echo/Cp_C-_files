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



void InsertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int val = arr[i];
        int j = i;

        while(j>0 && arr[j-1]>val){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = val;
    }
}
    

int main() {
    fastio();
    
    int sample[] = {2,9,3,6,8,1,5};
    int n = sizeof(sample)/sizeof(int);

    InsertionSort(sample,n);

    for(int x : sample){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}