#include<iostream>
#include<climits>
using namespace std;

#define ll long long 

//O(n) time worst case
ll minProduct(int arr[],int n){
    ll prod=1;
    int small_neg=INT_MAX,neg_count=0,small_pos=INT_MIN;
    bool is_zero=false;

    for(int i=0;i<n;i++){
        if(arr[i]==0){
            is_zero=true;
            continue;
        }
        if(arr[i]<0){
            small_neg = min(arr[i],small_neg);
            neg_count++;
        }
        if(arr[i]>0){
            small_pos = max(small_pos, arr[i]);
        }
        
        prod*=arr[i];
    }

    if(!is_zero && neg_count==0)
        return small_pos;

    if(is_zero && neg_count==0)
        return 0;

     if(neg_count%2==0)
        prod = prod/small_neg;
        
     return prod;
}


int main()
{
    int arr[]={0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minProduct(arr,n);

    return 0;
}