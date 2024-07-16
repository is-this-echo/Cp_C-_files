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



// 950. Reveal Cards In Increasing Order
// TC = O(nlogn), SC = O(n)
vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end()); // O(nlogn) time

    int n = deck.size();
    vector<int>ans(n);
    deque<int>dq;

    // storing the vector indices in deque
    for (int i = 0; i < n; ++i)
        dq.push_back(i);

    // O(n) time
    for (const auto& card : deck)
    {
        // step1 of logic to reveal card and remove from deck
        int idx = dq.front();
        dq.pop_front();
        ans[idx] = card;

        // O(1) constant time
        // step2 - once the previous card is revealed and popped from deque
        // pop the next index and append at back of deque which is
        // equivalent to keeping the space blank while maintaining index filling order.
        if ( !dq.empty())
        {
            int bottomCardIdx = dq.front();
            dq.pop_front();
            dq.push_back(bottomCardIdx);  
        }
    }
    return ans;
}


int main() {
    fastio();

    return 0;
}