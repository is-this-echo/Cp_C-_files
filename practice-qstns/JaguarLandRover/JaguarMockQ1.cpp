
// Jaguar 0/1s problem, image attached, idea is to find same rows(same values ), use hashmap

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;


int maxRows1(vector<vector<int>> &grid, int n){
    unordered_map<string,int>m;
    string s;
    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s.push_back(grid[i][j]);
        }
        m[s]++;
        ans = max(ans,m[s]);
        s.erase();
    }
    return ans;
}


int main()
{   int n;
    cin>>n;

    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    
    cout<<maxRows1(grid,n)<<endl;

    return 0;
}