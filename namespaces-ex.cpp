/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

#define fastio() ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 
#define LOG(x) std::cout << x << std::endl;

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {std::cout << "Case #" << t << ": ";}
    
 

namespace apple {

    void print(const std::string& text){

        std::cout<<text<<std::endl;
    }

} // namespace

namespace orange {

    void print(const char* text){

        std::string temp = text;
        std::reverse(temp.begin(),temp.end());
        std::cout<<temp<<std::endl;
    }
} //namespace


using namespace orange;
using namespace apple;

int main() {
    std::fastio();

    // if namespace not specified, it uses the one where argument provided  matches function protoype
    // better to use namespace for code readability
    apple::print("using some namesapce");

    // if-endif is a c++ pre-processor combo doesnt compile the code in the block 

    #if 0

    // sorting  + sliding window 
    sort(nums.begin(),nums.end());
    
    int n= nums.size();
    ll l=0,r=0,maxlen=1,total=nums[0];
    
    while(r<n && l<=r){
        ll window_len = r-l+1;


    #endif
    
    return 0;
}