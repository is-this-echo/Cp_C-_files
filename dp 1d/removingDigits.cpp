
/* 
    Given a number n, we can subtract from it any one digit that appears in it
    We need to find the number of steps required to make the number equal to 0.

    if n=27 , output =5 steps
    27 ->(-7), 20->(-2), 18-> (-8), 10->(-1), 9-> (-9), 0
*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

#define ll long long
#define mod 1e9+7


// top down dp approach, dp[i] -> min steps required to reach zero from i
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


// bottom up dp approach
int StepsBU(int n){
    vector<int> dp(n+1);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        int temp=i;
        int ans = INT_MAX;
        while(temp){
            int digit = temp%10;
            if(digit!=0)
                ans = min(ans,dp[i-digit]+1);
            temp=temp/10;
        }
        dp[i]=ans;
    }
    return dp[n];    
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;

    vector<int> dp(n+1);
    dp[0]=0;

    cout<<Steps(n,dp)<<"\n";
    cout<<StepsBU(n)<<'\n';

    return 0;
}