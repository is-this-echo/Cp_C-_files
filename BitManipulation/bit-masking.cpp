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
Bitmasking is representing the numbers in a set using a single number.
Example: 17 = (1 0 0 0 1)2  -> binary representation of 17
         If the bit at ith index is ON, then it means (i+1)th number is present in the set.
         0th bit means number 1, 1st bit means number 2 and so on....
         subset S = {1, 5} as 0th and 4th bits are ON or set.
*/

/*
Adds the number x to the subset by turning ON the (x-1)th bit
*/
void add(int &subset, int x)
{
    subset = subset ^ (1 << (x-1));
}

/*
Removes the number x from the subset by turning OFF the (x-1)th bit
*/
void remove(int &subset, int x)
{
    // x-1 as ith bit represents (i+1)th number
    subset = subset ^ (1 << (x-1));
}

/*
Prints the subset elements represented by the mask to standard output
*/
void display(int subset)
{   
    cout << "Decimal : " << subset << endl;
 
    // considering 10-bit representation.
    // Take an integer whose only required bit is ON, then do an AND operation
    for (int bit = 0; bit < 10; ++bit)
    {
        if (subset & (1 << bit))
            cout << bit + 1 << " ";
    }
    cout << endl;
}

int main() {
    fastio();

    int Set = 17;
    display(Set);

    remove(Set, 1);
    display(Set);

    add(Set, 1);
    display(Set);

    add(Set, 4);
    display(Set);

    return 0;
}
