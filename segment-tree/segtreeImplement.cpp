/* Question : 

Given an array, arr = [9,1,5,2,3,7,1,8,4,5] and Q queries of the form l,r
We need to find the max element in the array with indices ranging from l to r(both inclusive).

l , r   output
0 , 2   9
6 , 9   8/
3,  5   7
*/

#include<iostream>
#include<climits>
using namespace std;

#define ll long long
#define mod 1e9+7

int arr[100005], seg[4*100005];


void build(int idx, int low, int high){
    if(low==high){
        seg[idx] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);

    seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
}


int query(int idx, int low, int high, int l, int r){
    // if seg tree range lies complelely inside l and r
    if(low>=l && high<=r)
        return seg[idx];

    // seg tree range lies outside l and r
    if (low>r || high<l)
        return INT_MIN;

    // the 2 ranges overlaps
    int mid=(low+high)/2;
    int left = query(2*idx+1, low,mid,l,r);
    int right = query(2*idx+2,mid+1,high,l,r);
    
    return max(left,right);
    
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
         cin>>arr[i];
    }
    build(0,0,n-1);

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<" ";
    }
       
    return 0;
}