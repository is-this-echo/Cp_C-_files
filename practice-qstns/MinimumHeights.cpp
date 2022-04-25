
// gfg Minimum Heights II

/*Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify
the height of each tower either by increasing or decreasing them by K only once. After modifying,
height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers
after you have modified each tower.

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
The array can be modified as {3, 3, 6, 8}.
 The difference between the largest and the smallest is 8-3 = 5.
*/

#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long
#define mod 1e9+7


int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);

    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;

    int ans = arr[n-1] - arr[0];

    int mi,ma;

    for (int i = 0; i < n-1; i++){
        int mi = min(smallest, arr[i + 1] - k);
        int ma = max(largest, arr[i] + k);
        if (mi < 0)
            continue;
        ans = min(ans, ma - mi);
    }
    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int arr[] = {1,5,8,10}; 
    int n = sizeof(arr)/sizeof(arr[0]); int k=4;
    cout<<getMinDiff(arr,n,k);
    
    return 0;
}