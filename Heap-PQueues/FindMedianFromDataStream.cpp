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

 
 class MedianFinder {
    priority_queue<int>maxh;
    priority_queue<int, vector<int>, greater<int>>minh;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxh.push(num);

        if(maxh.size()-minh.size()>1){
            minh.push(maxh.top());
            maxh.pop();
        }

        if(!minh.empty() && maxh.top()>minh.top()){
            minh.push(maxh.top());
            maxh.pop();

            if(minh.size()-maxh.size()>1){
                maxh.push(minh.top());
                minh.pop();
            }
        }
    }
    
    double findMedian() {
        if(maxh.size()==minh.size()){
            double val  = (maxh.top() + minh.top())/2.0;
            return  val;
        }
        else if(maxh.size()>minh.size()){
            return maxh.top();
        }
        else{
            return minh.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 class MedianFinder {
    std::priority_queue<int>leftq;
    std::priority_queue<int, vector<int>, greater<int>>rightq;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (leftq.size() > rightq.size())
        {
            if (num > leftq.top())
            {
                rightq.push(num);
            }
            else
            {
                rightq.push(leftq.top());
                leftq.pop();
                leftq.push(num);
            }
        }
        else if (leftq.size() < rightq.size())
        {
            if (num > rightq.top())
            {   
                leftq.push(rightq.top());
                rightq.pop();
                rightq.push(num);
            }
            else
            {
                leftq.push(num);
            }
        }
        else
        {
            if (num > findMedian())
                rightq.push(num);
            else
                leftq.push(num);
        }
    }
    
    double findMedian()
    {
        if (leftq.size() > rightq.size())
            return leftq.top();

        else if (leftq.size() < rightq.size())
            return rightq.top();

        else
        {
            int l = leftq.empty() ? 0 : leftq.top();
            int r = rightq.empty() ? 0 : rightq.top();

            return (l + r) / 2.0;
        }
    }
};


int main() {
    fastio();

    return 0;
}