/*
Q2 : Sum of (max element - min element) of every contiguous subarray O(N)
Ex: ( 2,5,2) => [ [2], [2,5], [2,5,2], [5], [5,2], [2] ] 
      => Ans =  ( 0 + 3 + 3 + 0 + 3 + 0)  = 9
*/
//907. Sum of Subarray Minimums -> The above problem is a variation of the above

#include<iostream>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;

#define ll long long
// #define mod 998244353
const long mod = (long) pow(10,9)+7;
// brute force O(n^2)
 ll sumSubarray(vector<ll>& arr) {
    ll n = arr.size();
    ll sum = 0;
    
    for(ll i=0;i<n;i++){
        ll m = arr[i];
        for(ll j=i;j<n;j++){
            if(m>arr[j])
                m=arr[j];
            sum = sum +  m % mod;
        }
    }
    return sum % mod;
}

/* Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17. */

class Pair{
public:
    int num;
    int subarr;
    
    Pair(int x, int y){
        num=x;
        subarr = y;
    }
};

// Using stacks and subarray maths
 int sumSubarrayMins(vector<ll>& arr) {
    int n = arr.size();
    stack<Pair> lstack,rstack;
    const long mod = (long) pow(10,9)+7;
    
    int left[n],right[n];
    
    for(int i=0;i<n;i++){
        int count=1;
        int elem = arr[i];
        
        while(!lstack.empty() && lstack.top().num>=elem){
            count+=lstack.top().subarr;
            lstack.pop();
        }
        lstack.push(Pair(elem,count));
        left[i] = count;
    }
    
    for(int i=n-1;i>=0;i--){
        int count=1;
        int elem = arr[i];

        while(!rstack.empty() && rstack.top().num>elem){
            count+=rstack.top().subarr;
            rstack.pop();
        }
        rstack.push(Pair(elem,count));
        right[i] = count;
    }
    
    long ans=0;
    for(int i=0;i<n;i++){
        ans = (ans + (long)left[i]*right[i]*arr[i]) % mod;
    }
    return ans;    
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<ll> arr = {3,1,2,4};
    cout<<sumSubarrayMins(arr);

    return 0;
}
