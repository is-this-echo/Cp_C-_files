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



class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, 
                                    vector<vector<int>>& secondList)
    {
        int fSize = firstList.size();
        int sSize = secondList.size();
        vector<vector<int>> ans;

        if (fSize == 0 || sSize == 0)
            return ans;

        // i -> ptr to first list, j -> ptr to the second list
        int i = 0, j = 0;
        while (i < fSize && j < sSize)
        {
            if (firstList[i][1] < secondList[j][0] ||
                    firstList[i][0] > secondList[j][1])
            {

            }
            else
            {   
                int a = max(firstList[i][0], secondList[j][0]);
                int b = min(firstList[i][1], secondList[j][1]);
                ans.push_back({a, b});
            }

            if (firstList[i][1] < secondList[j][1])
                i++;

            else if (firstList[i][1] == secondList[j][1])
                i++, j++;

            else
                j++;
        }
        return ans;
    }
};

    
int main() {
    fastio();
    
    return 0;
}