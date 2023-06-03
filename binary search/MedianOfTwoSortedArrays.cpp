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
    


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // taking A as the smaller array
        vector<int>A=nums2, B=nums1;
        if(nums1.size()<nums2.size()){
            A = nums1;
            B = nums2;
        }

        int totalSize = nums1.size() + nums2.size();
        // pointers for A
        int l=0, r=A.size()-1;

        while(true){
            cout<<"just entered loop \n";
            int midA = (l+r)/2;
            int midB = (totalSize/2)-midA-2;

            // left half 
            int ALeft = (midA>=0) ? A[midA] : INT_MIN;
            int BLeft = (midB>=0) ? B[midB] : INT_MIN;

            // right half
            int ARight = (midA+1 < A.size()) ? A[midA+1] : INT_MAX;
            int BRight = (midB+1 < B.size()) ? B[midB+1] : INT_MAX;

            if(ALeft<=BRight && BLeft<=ARight){
                cout<<"reached here";
                // odd no. of elements
                if((totalSize%2) != 0){
                    return min(ARight, BRight);
                }
                // even number of elements
                return (max(ALeft, BLeft) + min(ARight, BRight))/2.0;
            }
            else if(ALeft>BRight){
                cout<<"2nd condtn";
                r = midA-1;
            }
            else{
                cout<<"3rd condtn";
                l = midA+1;
            }
        }
        return 0.00;
    }
};

    
int main() {
    fastio();

    vector<int>nums1{1,2}, nums2{3,4};

    Solution st;
    cout<<st.findMedianSortedArrays(nums1, nums2);

    return 0;
}