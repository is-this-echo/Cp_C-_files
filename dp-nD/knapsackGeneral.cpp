#include<iostream>
#include<vector>
using namespace std;


int knapsackRecursive(vector<int> &prices, vector<int> &wts, int N, int W){
    if(N==0 || W==0)
        return 0;

    int inc=0,exc=0;
    if(W-wts[N-1]>0)
        inc = prices[N-1] + knapsackRecursive(prices,wts,N-1,W-wts[N-1]);
    exc = knapsackRecursive(prices,wts,N-1,W);

    return max(inc,exc);
}


int knapsackBU(vector<int> &prices, vector<int> &wts, int N, int W){
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));
    int inc=0,exc=0;

    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            if(w-wts[n-1]>0)
                inc = prices[n-1] + dp[n-1][w-wts[n-1]];

            exc = dp[n-1][w];

            dp[n][w] = max(inc,exc);
        }
    }
    return dp[N][W];
}



int main()
{   
    vector<int> wts{2,7,3,4};
    vector<int> prices{5,20,20,10};
    int W = 11, N = wts.size();

    cout<<knapsackRecursive(prices,wts,N,W)<<endl;
    cout<<knapsackBU(prices,wts,N,W);

    return 0;
}