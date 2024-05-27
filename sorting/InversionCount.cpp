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
    
 
int merge(vector<int>&arr, int st, int m, int e){
    int i=st,  j=m+1;
    vector<int>temp;
    int cnt=0;
    
    while(i<=m && j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            cnt += (m-i+1);
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=m){
        temp.push_back(arr[i]);
        i++;
    }
    
    while(j<=e){
        temp.push_back(arr[j]);
        j++;
    }

    int k=0;
    for(int idx=st;idx<=e;idx++){
        arr[idx]=temp[k];
        k++;
    }
    return cnt;
}
 

int InversionCount(vector<int> &arr, int start, int end){
    if(start>=end)
        return 0;
    
    int mid = start + (end-start)/2;

    int c1 = InversionCount(arr,start,mid);
    int c2 = InversionCount(arr,mid+1,end);
    int ci = merge(arr,start,mid,end);

    return c1+c2+ci;
}

    
int main() {
    fastio();
    
    vector<int>arr = {2,5,1,0,3,9,7};
    int n = arr.size();

    cout<<"Number of inversion pairs are: "<<InversionCount(arr,0,n-1);

    return 0;
}  