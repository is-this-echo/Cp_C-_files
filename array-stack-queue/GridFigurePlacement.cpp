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
    

/*
You are given a grid of size n × m and a list figures consisting of characters representing different shapes. Your task is to place these shapes on the grid following specific rules.
A:
[1]

B:
[1, 1, 1]

C:
[1, 1]
[1, 1]

D:
[1, 0]
[1, 1]
[1, 0]

E:
[0, 1, 0]
[1, 1, 1]

📌 Rules
Start with an n × m grid filled with 0s.
Place figures in the order they appear in the array figures.
Each figure is represented in the grid using its 1-based index:
First figure → 1
Second figure → 2
and so on
A figure:
cannot overlap with already placed figures
cannot be rotated
must fully fit within the grid
For each figure, choose a position such that:
The topmost (smallest row index) placement is chosen
If multiple positions exist, choose the leftmost (smallest column index)
It is guaranteed that every figure can be placed somewhere on the grid.
📤 Output

Return the final grid after placing all figures.


🧪 Example
Input:
n = 3
m = 5
figures = ['A', 'D', 'E']

Output:
[
 [1, 2, 0, 0, 0],
 [0, 2, 2, 3, 0],
 [0, 2, 3, 3, 3]
]
*/


#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> solution(int n, int m, vector<char> figures)
{
    vector<vector<int>> grid(n, vector<int>(m, 0));
    unordered_map<char, vector<vector<int>>> shapes = {
        {'A', {{1}}},
        {'B', {{1,1,1}}},
        {'C', {{1,1},{1,1}}},
        {'D', {{1,0},{1,1},{1,0}}},
        {'E', {{0,1,0},{1,1,1}}}
    };

    for (int idx = 0; idx < figures.size(); ++idx)
    {
        auto &shape = shapes[figures[idx]];
        int h = shape.size();
        int w = shape[0].size();

        bool placed = false;

        // Try all positions (top-left priority)
        for (int i = 0; i <= n - h && !placed; ++i)
        {
            for (int j = 0; j <= m - w && !placed; ++j)
            {
                bool canPlace = true;

                // Check if shape fits
                for (int x = 0; x < h && canPlace; ++x)
                {
                    for (int y = 0; y < w; ++y)
                    {
                        if (shape[x][y] == 1 && grid[i + x][j + y] != 0)
                        {
                            canPlace = false;
                            break;
                        }
                    }
                }

                // Place shape
                if (canPlace)
                {
                    for (int x = 0; x < h; ++x)
                    {
                        for (int y = 0; y < w; ++y)
                        {
                            if (shape[x][y] == 1)
                            {
                                grid[i + x][j + y] = idx + 1;
                            }
                        }
                    }
                    placed = true;
                }
            }
        }
    }

    return grid;
}

  
int main()
{
    fastio();
    
    return 0;
}