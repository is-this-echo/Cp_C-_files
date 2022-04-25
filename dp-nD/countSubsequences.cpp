#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define ll long long
#define mod 998244353
const double eps = 1e-12;

// Top down approach/ recursive approach
int countSub(string s1, string s2, int i , int j){
    if((i==-1 && j==-1) || j==-1)
        return 1;

    if(i==-1)
        return 0;
    
    if(s1[i]==s2[j])
        return countSub(s1,s2,i-1,j-1) + countSub(s1,s2,i-1,j);
    
    return countSub(s1,s2,i-1,j);
}

// Bottom up approach, TC = O(mxn), SC = O(mxn)
int countSubBU(string s1, string s2){
    int m = s1.size(),n = s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    // if s2 is empty string then we can always find it in s1
    for(int i=0;i<=m;i++)
        dp[i][0]=1;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[m][n];
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s1 = "ABBCDCEC";
    string s2 = "ABC";
    int m = s1.size();
    int n = s2.size();

    cout<<countSub(s1,s2,m-1,n-1)<<"\n";
    cout<<countSubBU(s1,s2)<<"\n";
    
    return 0;
}