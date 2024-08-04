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
    
 
void permute(vector<int>& temp, vector<vector<int>>& ans,
             unordered_map<int, int>& mp, int maxSize)
{
    if (temp.size() == maxSize)
    {
        ans.push_back(temp);
        return;
    }

    for (auto& [num, freq] : mp)
    {   
        if (freq > 0)
        {
            temp.emplace_back(num);
            mp[num]--;

            permute(temp, ans, mp, maxSize);

            temp.pop_back();
            mp[num]++;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    unordered_map<int, int> mp;

    for (auto x : nums)
        mp[x]++;

    permute(temp, ans, mp, nums.size());

    return ans;
}


int main() {
    fastio();

    vector<int>nums {1,1,2};
    auto ans = permuteUnique(nums);
    for (auto x : ans)
    {
        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }


    return 0;
}