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

// solution -1
class Solution {
    unordered_map<char,string>mp;
    vector<string>ans;

    void dfs(string digits, string word){
        if(digits.length()==0){
            ans.push_back(word);
            cout<< word << "  ";
            return;
        }

        string str = mp[digits[0]];
        for(char ch : str){
            dfs(digits.substr(1), word+ch);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() ==0 )
            return {};

        mp['2'] = "abc"; mp['3'] = "def";
        mp['4'] = "ghi"; mp['5'] = "jkl";
        mp['6'] = "mno"; mp['7'] = "pqrs";
        mp['8'] = "tuv"; mp['9'] = "wxyz";

        dfs(digits, "");

        return ans;
    }
};



// solution-2
string mapping[] = {"","","ABC","DEF", "GHI", "JKL","MNO","PQRS","TUV","WXYZ"};

void dfs(string input, string output, int i=0){
    if(input[i]=='\0'){
        cout<<output<<"\n";
        return;
    }
    int curr_digit = input[i]-'0';

    if(curr_digit == 0  || curr_digit == 1)
        dfs(input, output, i+1);

    for(char ch : mapping[curr_digit]){
        dfs(input, output + ch, i+1);
    }

}

void solve(){
    string input;
    cin>>input;

    dfs(input, "");

}


int main() {
    fastio();

    // solution-1
    // Solution st;
    // st.letterCombinations("234");
    
    // solution-2
    solve();

    return 0;
}