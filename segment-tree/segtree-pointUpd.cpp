
// 2 types of queries, 1) arr[idx]+=X , 2) [l,R] Range Sum query
// point updates needed in segment tree


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

// node is the index of element to be increased in the array by value
// call from main as pointUpdate(0,0,n-1,node,val); TimeComplexity = O(logn)
void pointUpdate(int idx, int low, int high, int node, int val){

    if(low==high){
        seg[low]+=val;
    }
    else{
        int mid = (low+high)>>1;
        if(node>=low && node<=mid)
            pointUpdate(2*idx+1,low,mid,node,val);
        else 
            pointUpdate(2*idx+2,mid+1,high,node,val);
        
        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
    }

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