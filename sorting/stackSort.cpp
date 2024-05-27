#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;


 // sorting one stack using a temporary stack in decreasing order, TC = O(n^2)
void printStack(stack<int> stk){
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<"\n\n";
}


// sort in descending order
void solve(){
    stack<int> s1, temp;

    s1.push(3);s1.push(5);s1.push(1);s1.push(4);s1.push(2);
    printStack(s1);

    while(!s1.empty()){
        int val = s1.top();
        s1.pop();

        while(!temp.empty() && val<temp.top()){
            //s1.pop();
            int val2 = temp.top();
            temp.pop();
            s1.push(val2);
        }
        temp.push(val);
    }
    printStack(temp);
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    
    return 0;
}
