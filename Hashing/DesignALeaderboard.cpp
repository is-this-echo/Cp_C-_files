/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <shared_mutex>
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
Design a Leaderboard class, which has 3 functions:
--------------------------------------------------
addScore(playerId, score): Update the leaderboard by adding score to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.

top(K): Return the score sum of the top K players.

reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.

Initially, the leaderboard is empty.
*/
class Leaderboard
{
public:
    void addScore(int playerId, int score) // O(log n), removing/adding score to the multiset
    {
        int oldScore = playerMap[playerId];
        playerMap[playerId] += score;

        if (auto itr = board.find(oldScore); itr != board.end())
        {
            board.erase(itr);
        }
        board.insert(playerMap[playerId]);
    }

    int top(int k) // O(k), linear search in ordered list(multiset)
    {
        int topSum = 0;
        for(const auto& score : board)
        {
            topSum += score;

            if (--k == 0)
                break;
        }
        return topSum;
    }

    void reset(int playerId) // O(log n), removing score from the multiset
    {
        int playerScore = playerMap[playerId];
        playerMap.erase(playerMap.find(playerId)); // playerMap.erase(playerId);
        board.erase(board.find(playerScore));
    }

private:
    std::unordered_map<int, int> playerMap;
    std::multiset<int, greater<>> board;
};


// Multi-threading enabled, read heavy system, concurrent reads but exclusive single writes,
// blocking for writes but not for reads.
class Leaderboard
{
public:
    void addScore(int playerId, int score)
    {
        std::unique_lock<std::shared_mutex> lck(mtx);

        int oldScore = playerMap[playerId];
        playerMap[playerId] += score;

        if (auto itr = board.find(oldScore); itr != board.end())
            board.erase(itr);

        board.insert(playerMap[playerId]);
    }

    int top(int k) const
    {
        std::shared_lock<std::shared_mutex> lck(mtx);

        int topSum = 0;
        for(const auto& score : board)
        {
            topSum += score;

            if (--k == 0)
                break;
        }
        return topSum;
    }

    void reset(int playerId)
    {
        std::unique_lock<std::shared_mutex> lck(mtx);

        int playerScore = playerMap[playerId];
        playerMap.erase(playerMap.find(playerId));
        board.erase(board.find(playerScore));
    }

private:
    std::unordered_map<int, int> playerMap;
    std::multiset<int, greater<>> board;
    mutable std::shared_mutex mtx;
};


int main()
{
    fastio();
    
    return 0;
}