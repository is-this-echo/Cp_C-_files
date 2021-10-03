#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// recursive soln
int lcs(string s1, string s2, int i, int j){
    if(i==s1.length() || j==s2.length())
        return 0;
    
    if(s1[i]==s2[j])
        return 1 + lcs(s1,s2,i+1,j+1);
    
    int case1 = lcs(s1,s2,i,j+1);
    int case2 = lcs(s1,s2,i+1,j);

    return max(case1, case2);
}

// Top-down dp approach
// dp(i,j) -> s1(i,n1-1) and s2(j,n2-1)
int lcsTD(string s1, string s2, int i, int j, vector<vector<int>> &dp){
    if(i==s1.length() || j==s2.length())
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s1[i]==s2[j])
        return dp[i][j] = 1 + lcs(s1,s2,i+1,j+1);
    
    int case1 = lcs(s1,s2,i,j+1);
    int case2 = lcs(s1,s2,i+1,j);

    return dp[i][j] = max(case1, case2);
}

// Bottom-up dp approach
// dp(i,j) is the state that stores the length of LCS if we take first i characters from string s1,
// and first j characters from string s2
// dp(i,j) -> s1(0 to i-1) and s2(0 to j-1)
int lcsBU(string s1, string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j] = 1+ dp[i-1][j-1];
            
            else{
                int opt1 = dp[i-1][j];
                int opt2 = dp[i][j-1];
                dp[i][j] = max(opt1, opt2);
            }
        }
    }
    // printing the dp array
    for(auto rows:dp){
        for(auto x: rows)
            cout<<x<<" ";
        cout<<endl;
    }

    int i=n1,j=n2;
    string lcs;
    
    while(i!=0 && j!=0){
        if(s1[i-1]==s2[j-1]){
            lcs.push_back(s1[i-1]);
            i--,j--;
        }
        else {
            if(dp[i][j-1]>dp[i-1][j])
                j--;
            else 
                i--;
        }
    }

    reverse(lcs.begin(),lcs.end());
    cout<<lcs<<endl;

    return dp[n1][n2];
}



int main()
{   
    string a = "ABCD";
    string b = "ABEDG";
    int m = a.size();
    int n = b.size();

    cout<<lcs(a,b,0,0)<<endl;
    cout<<lcsBU(a,b)<<endl;

    return 0;
}