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
 
 
 
bool valid(int nx, int ny, int n, int m){ return nx>=0 && nx<n && ny>=0 && ny<m; }
 
void solve(){
    int n,m;
    cin>>n>>m;
 
    vector<vector<char>>grid(n,vector<char>(m,'.'));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<char>>path(n,vector<char>(m,'.'));
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
 
    int ax,ay,bx,by;
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                ax=i, ay=j;
                break;
            }
        }
    }
 
    bool ans = false;
    queue<pair<int,int>>q;
 
    q.push({ax,ay});
    vis[ax][ay] = true;
 
    while(!q.empty()){
        auto curr = q.front();
        int cx = curr.f;
        int cy = curr.s;
        q.pop();
 
        if(grid[cx][cy]=='B'){
            bx=cx, by=cy;
            ans = true;
            break;
        }
 
        // go left
        if(valid(cx,cy-1,n,m) && !vis[cx][cy-1] && grid[cx][cy-1]!='#'){
            path[cx][cy-1] = 'L';
            vis[cx][cy-1] = true;
            q.push({cx,cy-1});
        }
 
        // go right
        if(valid(cx,cy+1,n,m) && !vis[cx][cy+1] && grid[cx][cy+1]!='#'){
            path[cx][cy+1] = 'R';
            vis[cx][cy+1] = true;
            q.push({cx,cy+1});
        }
 
        // go up
        if(valid(cx-1,cy,n,m) && !vis[cx-1][cy] && grid[cx-1][cy]!='#'){
            path[cx-1][cy] = 'U';
            vis[cx-1][cy] = true;
            q.push({cx-1,cy});
        }
 
        // go down
        if(valid(cx+1,cy,n,m) && !vis[cx+1][cy] && grid[cx+1][cy]!='#'){
            path[cx+1][cy] = 'D';
            vis[cx+1][cy] = true;
            q.push({cx+1,cy});
        }
    }
 
    if(ans){
        int length=0;
        string str = "";
 
        while(1){
            if(bx==ax && by==ay){
                break;
            }
            if(path[bx][by]=='R'){ by=by-1; length++; str+='R'; } 
            if(path[bx][by]=='L'){ by=by+1; length++; str+='L'; }
            if(path[bx][by]=='U'){ bx=bx+1; length++; str+='U'; }
            if(path[bx][by]=='D'){ bx=bx-1; length++; str+='D'; }
        }
 
        reverse(str.begin(), str.end());
 
        cout<<"YES"<<"\n";
        cout<<length<<"\n";
        cout<<str;
    }
    else{
        cout<<"NO";
    }
}
 
 
int main() {
    fastio();
 
    solve();
 
    return 0;
}