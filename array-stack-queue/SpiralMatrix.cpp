/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}


// 54. Spiral Matrix, print matrix in spiral form 
// T.C = O(mxn), S.C = O(1) if we do cout elsw O(mxn) if elements stored in vector
vector<int> solve(vector<vector<int>>&matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    int top = 0, left = 0, right = col-1, bottom = row-1;
    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        for(int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        top++;

        for(int i = top;i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}

    
int main() {
    fastio();

    vector<vector<int>>matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto ans = solve(matrix);

    for(auto x: ans)
        cout<<x<<" ";

    return 0;
}