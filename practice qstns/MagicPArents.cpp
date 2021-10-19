#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<string> arr (n);
	vector<int> value (n);
	for(int i=0; i<n; i++) {
		cin >> value[i];
	}
	for(int i=1; i<n; i++)
		cin >> arr[i];
	unordered_map<string, int> mp;
	for(int i=1; i<n; i++) {
		mp[arr[i]] = i;
	}
	int ans = 0;
	for(int i=0; i<n; i++) {
		if(mp.find(arr[i]+'L')==mp.end() or mp.find(arr[i]+'R')==mp.end())
			continue;
		int left = value[mp[arr[i]+'L']], right = value[mp[arr[i]+'R']];
		if((left&1)^(right&1))
			ans += value[i];
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//  int n = 6;
    // int rootVal=11;
    // string s[] = {"L","R","LL","LR","RR"};
    // int values[]={14,23,7,8,14};
    
    // cout<<magicParents(n,rootVal,s,values);
    // // 25

	// int _t; cin >> _t; while(_t--)
	solve();
}