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
    class Node 
    {
    public:
        Node* left;  // 0-bit
        Node* right; // 1-bit

        Node() : left(nullptr), right(nullptr) {};
    };

    class Trie
    {
        Node* root;
    public:
        Trie() : root(new Node()) {};

        void insert(int val)
        {
            Node *temp = root;
            for (int i = 31; i >= 0; --i)
            {
                bool bit = (val>>i) & 1;
                if (bit)
                {
                    if (temp->right == nullptr)
                        temp->right = new Node();
                    temp = temp->right;
                }
                else
                {
                    if (temp->left == nullptr)
                        temp->left = new Node();
                    temp = temp->left;
                }
            }
        }

        int maxXor(int val, int limit)
        {
            int maxXor = 0;
            Node *temp = root;
            for (int i = 31; i >= 0; --i)
            {
                bool bit = (val>>i) & 1;
                if (bit)
                {
                    if (temp->left != nullptr)
                    {
                        maxXor += (1<<i);
                        temp = temp->left;
                    }
                    else
                        temp = temp->right;
                }
                else
                {
                    if (temp->right != nullptr)
                    {  
                        maxXor += (1<<i);
                        temp = temp->right;
                    }                    
                    else
                        temp = temp->left;
                }
            }
            return maxXor;
        }
    };
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int qSize = queries.size();
        int numsSize = nums.size();

        Trie t;
        vector<int> ans(qSize);

        // TC = O(nlogn)
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> offlineQueries; // mi, xi, idx
        for (int i = 0; i < qSize; ++i)
            offlineQueries.push_back({queries[i][1], make_pair(queries[i][0], i)});

        // TC = O(qlogq)
        sort(offlineQueries.begin(), offlineQueries.end());

        int idx = 0;
        // The idea is to store numbers in the trie from nums which are smaller
        // than the mi value given in query and then do the max xor query in trie.
        // TC = O(q+n) and not O(q*n)
        for (int i = 0; i < qSize; ++i)
        {
            int xi = offlineQueries[i].s.f;
            int limit = offlineQueries[i].f;
            int qdx = offlineQueries[i].s.s;
            // cout << xi << " " << limit << " " << qdx <<endl;
            
            // TC = O(n) in total
            while (idx < numsSize && nums[idx] <= limit)
            {
                t.insert(nums[idx]);
                idx++;
            }

            // no element in nums is lesser than or equal to limit
            if (idx == 0)
                ans[qdx] = -1;
            else
                ans[qdx] =  t.maxXor(xi, limit);
        }
        return ans;
    }
};


int main()
{
    fastio();

    vector<int> nums{0,1,2,3,4};
    vector<vector<int>> queries{{3,1}, {1,3}, {5,6}};

    Solution st;
    auto out = st.maximizeXor(nums, queries);

    for (auto x : out)
        cout << x << " ";

    return 0;
}

