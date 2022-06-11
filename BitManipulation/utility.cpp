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

    
 /*
 	xor operator, a^b compares their binary forms bit by bit, ex-> 1^1 = 0, 0^0=0, 1^0 =1, 0^1=1
	~ operator, flips the bits from 0 to 1 or vice versa.
	But, ~0 =-1 as most significant bit msb, decides the sign, if its 1 then 
    the number is negative else positive.

  Right shift operator  ->    a>>b   = a/(2^b)  , drop 'b' no. of bits from the end.
	Ex -> a= 10010, b= 2  , then a>>b = 100 , last 2 bits dropped.
	Here, a is shown in binary form.

  left shift operator   ->    a<<b   = a * (2^b),  append 'b' no. of zeros at the end. 
	Ex -> a = 100, b = 3 , then a<<b = 100000  , binary form of a gets appended by 3 zeros.
	Here, a is shown in binary form.

    To find if a number N is a power of 2, then N & (N-1) == 0
    To find if a number x is odd, then (x & 1)==1 , as odd numbers in binary form has 1 as the last bit.
 */
    
int main() {
    fastio();

    int a;
    cin>>a;

    cout<<__builtin_clz(a)<<endl;   // gives leading zeroes
    cout<<__builtin_ctz(a)<<endl;       // gives trailing zeroes
    cout<<__builtin_popcount(a)<<"\n";  // gives number of setbits, <__builtin_popcountll> for ll type

    return 0;
}