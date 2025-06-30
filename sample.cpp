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
void meta(int t) {cout << "Case #" << t << ": ";}


struct Node
{
    int val;
    Node *left, *right;

    Node(int d) : val(d), left(NULL), right(NULL) {}
};


bool canPlace(vector<int>&nests, int dist, int birds)
{
    int birdsPlaced = 1
    int prevLocation = nests[0];

    for (int i = 1; i < nests.size(); ++i)
    {
        int currLocation = nests[i];
        if (currLocation - prevLocation >= dist)
        {
            birdsPlaced++;
            prevLocation = currLocation;

            if (birdsPlaced == birds)
                return true;
        }
    }
    return true;
}


int angryBirds(vector<int>& nests, int birds)
{
    std::ranges::sort(nests);

    int n = nests.size();
    int start = 0;
    int end = nests[n - 1] - nests[0];
    int ans = -1;

    while (start <= end)
    {
        int dist = start + (end - start) / 2;
        if (canPlace(nests, dist, birds))
        {
            ans = dist;
            start = dist + 1;
        }
        else
        {
            end = dist - 1;
        }
    }
    return ans;
}


void print(vector<int>& arr)
{
    for (int i : arr)
        std::cout << i << " ";

    std::cout << std::endl;
}


int main()  
{
    fastio();


    

    return 0;
}  

