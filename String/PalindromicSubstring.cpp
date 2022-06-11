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
    
 // Leetcode
 // 5. Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {

        int n = (int)s.length();
        int ans_l = 0, ans_r = 0, max_len=0;
        
        for(int i=0;i<n;i++){
            // for odd length palindrome
            int l=i, r=i;
            
            while(l>=0 && r<n && s[l]==s[r]){ 
                if(r-l+1>max_len){
                    ans_l = l; ans_r = r;
                    max_len = r-l+1;
                }
                l--; r++;
            }
            
            // for even length palindrome
            l=i, r=i+1;
            
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>max_len){
                    ans_l = l; ans_r = r;
                    max_len = r-l+1;
                }
                
                l--; r++;
            }
        }
        return s.substr(ans_l,max_len);
    }
};
    
int main() {
    fastio();

    Solution s;
    string str = "abadabkl";

    cout<<s.longestPalindrome(str);
    
    return 0;
}