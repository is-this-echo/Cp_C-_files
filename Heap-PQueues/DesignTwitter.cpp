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


class Twitter
{
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId)
    {
        userTweets[userId].emplace_back(timestamp, tweetId);
        ++timestamp;
    }
    
    vector<int> getNewsFeed(int userId)
    {
        vector<int> feed;

        followList[userId].insert(userId);

        // max-heap : {timestamp, tweetId, userId, idx}
        priority_queue<std::tuple<int,int,int,int>> pq;
        for (int followee : followList[userId])
        {
            // insert most recent tweet from all followees
            if (userTweets.contains(followee) && userTweets[followee].size() > 0)
            {
                const auto& tweet = userTweets[followee];
                const auto idx = tweet.size() - 1;
                pq.push({tweet[idx].first, tweet[idx].second, followee, idx});
            }
        }

        while (!pq.empty() && feed.size() < 10)
        {
            auto [_, tweetId, followee, idx] = pq.top();
            pq.pop();

            feed.emplace_back(tweetId);
            if (idx-- > 0)
            {
                const auto& tweet = userTweets[followee];
                pq.push({tweet[idx].first, tweet[idx].second, followee, idx});
            }

        }

        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        followList[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followList[followerId].erase(followeeId);
    }

private:
    int timestamp{0};

    // userId -> list of following
    std::unordered_map<int, std::unordered_set<int>> followList;

    // userId -> their tweets {timestamp, tweetId}
    std::unordered_map<int, std::vector<std::pair<int,int>>> userTweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
   

int main()
{
    fastio();
    
    return 0;
}