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


// Time complexity = O(m*n), Space complexity = O(1)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        int currNum = nums1[i];
        for (int j = 0; j < m; j++)
        {   
            if (currNum == nums2[j])
            {
                while (j < m)
                {
                    if (nums2[j] > currNum)
                    {
                        ans[i] = nums2[j];
                        break;
                    }
                    j++;
                }
            }
        }
    }
    return ans;
}


// Time complexity = O(m+n), Space complexity = O(n) -> use of hashmap and stack
vector<int> nextGreaterElement(const vector<int>& nums1, const vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    unordered_map<int,int> mp;

    for (int i = 0; i < n; i++)
        mp[nums1[i]] = i;

    vector<int> ans(n, -1);
    stack<int> stk;

    for (int i = 0; i < m; i++)
    {
        while (!stk.empty() && nums2[i] > stk.top())
        {
            int val = stk.top();
            stk.pop();
            ans[mp[val]] = nums2[i];
        }
        if (mp.count(nums2[i])) // we do this check before pushing to stack
        // as stack should only contain those elements whose greater element
        // is required to be found
            stk.push(nums2[i]);
    }
    return ans;
}


int main() {
    fastio();

    const vector<int>& nums1{4, 1, 2};
    const vector<int>& nums2{1, 3, 4, 2};

    auto ans = nextGreaterElement(nums1, nums2);

    for (auto x : ans)
        cout << x << " ";


    return 0;
}