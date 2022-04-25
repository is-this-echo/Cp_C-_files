/*
Given a paper of size A x B.
Task is to cut the paper into squares of any size. 
Find the minimum number of squares that can be cut from the paper.

Input  : 13 x 29,   Output : 9
Explanation : 
2 (squares of size 13x13) + 
4 (squares of size 3x3) + 
3 (squares of size 1x1)=9

Input  : 4 x 5,     Output : 5
Explanation : 
1 (squares of size 4x4) + 
4 (squares of size 1x1)
*/

#include<iostream>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;

  
// Returns min number of squares needed 
int minimumSquare(int a, int b){
    long long result = 0, rem = 0;  

    // swap if a is small size side . 
    if (a < b) 
        swap(a, b); 

    while (b > 0){
        result += a/b; 
        rem = a % b; 
        a = b; 
        b = rem; 
    }
    return result; 
} 
  


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n = 13, m = 29; 
    cout << minimumSquare(n, m); 
    
    return 0;
}