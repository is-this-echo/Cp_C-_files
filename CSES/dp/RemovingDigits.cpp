#include<iostream>
#include<climits>
#include<vector>
using namespace std;
 
#define ll long long
#define mod 1e9+7
 
 
int Steps(int n, vector<int>&dp){ 
    if(n==0)
        return 0;
    
    if(dp[n]!=0)
        return dp[n];
    
    int ans=INT_MAX;
    int temp=n;
    while(temp){
        int digit = temp%10;
        if(digit!=0)
            ans = min(ans,1+Steps(n-digit,dp));
        temp/=10;
    }
    return dp[n]=ans;
}
 
 
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
    int n;
    cin>>n;
 
    vector<int> dp(n+1);
    dp[0]=0;
 
    cout<<Steps(n,dp)<<"\n";
 
    return 0;
}