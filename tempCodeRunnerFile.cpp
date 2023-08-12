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


int partition(vector<int> &arr, int start, int end){
    int i = start-1, pivot = arr[end];
    for(int j = start; j < end; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

void quicksort(vector<int> &arr, int start, int end) {
    if(start < end){
        int p = partition(arr,start,end);
        quicksort(arr, start, p);
        quicksort(arr, p+1, end);
    }
}


int main(){
    vector<int>arr = {1,9,5,67,2,3,44,57};
    int n = arr.size();

    quicksort(arr,0,n-1);

    for(int i=0; i < n; i++){
        cout<< arr[i] <<" ";
    }

    return 0;
}