/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    
 
 // 1041. Robot Bounded In Circle


class Solution {
public:
    bool isRobotBounded(string ins) {
        
        // vector representing direction of robot(i,j)
        // 0.i + 1.j initially
        int i=0, j=1; 
        
        // initial coordinate
        int x = 0, y = 0;
        
        for(auto ch : ins){
            if(ch=='G'){
                x += i;
                y += j;
            }
            
            else if(ch=='R'){
            // if robot is facing right(1.i + 0.j)
            // after right turn, it will face (0.i + -1.j) direction
                int temp = i;
                i = j;
                j = -1 * temp;
            }
            
            else{
            // try every direction to get the formula while turing right
                int temp = j;
                j = i;
                i = -1*temp;
            }
        }
        // if net dispalcement = 0 or  after 1 iteration direction of robot
        // has changed from initial direction, it will be constrained inside a circle
        
        return (x==0 && y==0) || !(i==0 && j==1); 
            
    }
};
    
int main() {
    fastio();

    string s = "GGLLGG";
    Solution st;

    cout<<st.isRobotBounded(s);
    
    return 0;
}