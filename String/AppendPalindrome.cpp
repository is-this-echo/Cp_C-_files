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
    
 
 // Find the number of letters to append to the given string to make it a palindrome
 // use kmp or z-algo to solve.

void solve(string str, int len){
    int n = str.length();

    vector<int>lps(n+1);
    int i=0,j=-1;
    lps[0]=-1;

    while(i<n){
        while(j!=-1 && str[j]!=str[i]) 
            j = lps[j];
        
        i++; j++;
        lps[i]=j;

    }

    cout<<"Number of characters to be added = "<<len-lps[n];
    cout<<endl;

}

    
int main() {
    fastio();

    string s = "abacdca",temp;
    temp = s;
    reverse(temp.begin(),temp.end());

    string sp = temp + "#"+ s ;

    // s is of the form  y + palindrome + rev(y), we need to find longest suffix which is a palindrome
    // here s = a + cebec + a, so if we can find the palindrome length(lps[n]) then,
    // ans = str.length()- lps[n]

    solve(sp,s.length());
    

    return 0;
}