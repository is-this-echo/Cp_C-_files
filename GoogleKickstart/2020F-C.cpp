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



int side,ra,pa,rb,pb,c;
int allowed[8][8];

inline bool isBounded(int x, int y){
    if(x>=1 && y>=1 && x<=side && y<=2*x-1 && allowed[x][y]==0)
        return 1;
    return 0;
 }


void getBest(){

}

void solve(){
    cin>>side>>ra>>pa>>rb>>pb>>c;
    memset(allowed,0,sizeof(allowed));
    // allowed =0 means not blocked, 1 means blocked for access

    allowed[ra][pa]=1;
    allowed[rb][pb]=1;

    for(int i=0;i<c;i++){
        int x,y;
        cin>>x>>y;

        allowed[x][y]=1;
    }

    cout<<getBest(ra,pa,rb,pb)<<"\n";
    


}
    

int main() {
    fastio();

    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        google(i);
        solve();
    }

    return 0;
}