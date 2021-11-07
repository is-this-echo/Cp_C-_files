// Leetcode 264

/*An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
*/

#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 1e9+7

int nthUglyNumber(int n) {
    if(n == 1)
        return 1;

    vector<int> uglyNum(n);
    uglyNum[0] = 1;
    int l2 = 0, l3 = 0, l5 = 0; 

    for(int i=1; i<n; i++){
            uglyNum[i] = min(2 * uglyNum[l2], 
                    min(3 * uglyNum[l3], 5 * uglyNum[l5]));

        if(uglyNum[i] == 2 * uglyNum[l2])
            l2++;

        if(uglyNum[i] == 3 * uglyNum[l3])
            l3++;

        if(uglyNum[i] == 5 * uglyNum[l5])
            l5++;
    }
    return uglyNum[n-1];
    
    /*
    vector<int> ad;
    vector<int> nums = {2,3,5};
    int count=1;
        
    ad.push_back(1);
    
    if(n==1)
        return 1;
    
    for(int i=2;;i++){
        int temp=i;
        for(int x : nums){
            while(i%x==0)
                i=i/x;
        }
        if(i==1){
            ad.push_back(temp);
            cout<<temp<<" ";
            count++;
        }
        if(count==n)
            break;
    }
    
    return ad[n-1];
    */
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cout<<nthUglyNumber(10);
    
    return 0;
}