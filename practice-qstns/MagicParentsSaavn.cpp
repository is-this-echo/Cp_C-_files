#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<string> arr (n);
	vector<int> value (n), id (n);
	for(int i=0; i<n; i++) {
		cin >> value[i];
		id[i] = i;
	}
	for(int i=1; i<n; i++)
		cin >> arr[i];
	sort(id.begin(), id.end(), [&](const int &x, const int &y) {
		if(arr[x].length()!=arr[y].length())
			return arr[x].length()<arr[y].length();
		return arr[x]<arr[y];
	});
	int ans = 0;
	for(int i=0, j=1; i<n-2 and j<n; i++) {
		int left = -1, right = -1;
		if(arr[id[j]]==arr[id[i]]+'L')
			left = value[id[j++]];
		if(arr[id[j]]==arr[id[i]]+'R')
			right = value[id[j++]];
		if(left!=-1 and right!=-1 and ((left&1)^(right&1)))
			ans += value[id[i]];
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// int _t; cin >> _t; while(_t--)
	solve();
}