
/*Given two strings a and b, find the number of ways to add a character in such a way that LCS(a,b) increases by 1.
Example: a=zzz, b=xzzzz         output: 5 (a can become: xzzz, zzzz, zzzz, zzzz, zzzz)
sol:
duto dp karechi
dp1[i][j] = lcs (s[0___i], t[0___j])
dp2[i][j] = lcs(s[i__n-1, t[j__m-1])
tarpor b te 0___m number of positions ache sekhane prattek ta character till a-z put karchi and current character ka match karachhi with character of a, then lcs compute karchi from dp1 and dp2
 tahole order ta n*m hachhe
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second

const int N = 100010, mod = 1e9+7;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp1 (n+1, vector<int> (m+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1]==t[j-1])
                dp1[i][j] = 1+dp1[i-1][j-1];
            else
                dp1[i][j] = max(dp1[i][j-1], dp1[i-1][j]);
        }
    }
    vector<vector<int>> dp2 (n+1, vector<int> (m+1));
    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {
            if(s[i]==t[j])
                dp2[i][j] = 1+dp2[i+1][j+1];
            else
                dp2[i][j] = max(dp2[i][j+1], dp2[i+1][j]);
        }
    }

    int lcs = dp1[n][m];
    int ans = 0;
    for(int j=0; j<=m; j++) {
        vector<int> count (26);
        for(int i=0; i<n; i++) {
            if(lcs==dp1[i][j]+dp2[i+1][j])
                count[s[i]-'a'] = 1;
        }
        cout << endl;
        for(int i=0; i<26; i++)
            ans += count[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int _t; cin >> _t; while(_t--)
    solve();
}