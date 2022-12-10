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
    
 
// Time Complexity : O(n^2)
// Sapce Complexity : O(1) -> In-place sorting

void SelectionSort(vector<int> &arr){
    int n = arr.size();

    for(int i=0;i<n-1;i++){

        int minIdx  = i;

        for(int j=i+1;j<n;j++){

            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }

}

    
int main() {
    fastio();
    
    vector<int>sample = {2,9,3,6,8,1,5};

    SelectionSort(sample);

    for(int x : sample){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}