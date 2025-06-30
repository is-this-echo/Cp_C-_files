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
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // define search space
        int start = 0;
        int end = rows *  cols - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int row = mid / cols, col = mid % cols;

            if (matrix[row][col] == target)
                return true;
            
            if (matrix[row][col] < target)
                start = mid + 1;
            
            else
                end = mid - 1;

        }

        return false;
    }
};

    
int main() {
    fastio();
    
    return 0;
}