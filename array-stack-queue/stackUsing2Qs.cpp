#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 

class MyStack {
    queue<int>q1,q2;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        
        while(!q2.empty()){
            int front = q2.front();
            q2.pop();
            q1.push(front);
        }
        swap(q1,q2);
    }
    
    
    int pop() {
        int val=q2.front();
        q2.pop();
        return val;
    }
    
    
    int top() {
        return q2.front();
    }
    
    
    bool empty() {
        return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}