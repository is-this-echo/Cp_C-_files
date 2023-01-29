#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-10;
    

// using Newtons square root formula, x(i+1) = x(i) - f(x(i))/f'(x(i))
// f(x) = x*x -n

void sqrtOfN(){
    double n;
    cin>>n;

    // xi,  the starting value can be anything
    double xi=150, xn;
    int itr=0;

    while(1){
        xn = (xi + n/xi)/2;

        if(abs(xi-xn)<eps)
            break;
            
        xi=xn;
        itr++;
    }

    cout<<"sqrt : "<<xn<<"\n"<<"iterations: "<<itr;

}

    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    sqrtOfN();
    
    return 0;
}