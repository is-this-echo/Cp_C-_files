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


class Node{
public:
    Node *left; // 0 bit
    Node *right; //  1 bit

    Node() : left(NULL), right(NULL){};
};


class Trie{
    Node * root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int val)
    {
        Node *temp = root;
        for(int i=31; i>=0; i--){
            bool bit = (val>>i) & 1;

            if(bit == 0){
                if(temp->left == NULL){
                    temp->left = new Node();
                }
                temp = temp->left;
            }
            else{
                if(temp->right == NULL){
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }

    int XOR_helper(int val)
    {   
        int curr_XOR = 0;
        Node * temp = root;
        for(int i=31; i>=0; i--){
            bool bit = (val>>i) & 1;

            if(bit == 0){
                if(temp->right != NULL){
                    temp = temp->right;
                    curr_XOR += (1<<i);
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->left != NULL){
                    temp = temp->left;
                    curr_XOR += (1<<i);
                }
                else{
                    temp = temp->right;
                }
            }
        }
        return curr_XOR;
    }

    int max_XOR(int *arr, int n)
    {   
        int curr_XOR = 0, max_XOR = 0;
        for(int i=0; i<n; i++){
            insert(arr[i]);
            curr_XOR = XOR_helper(arr[i]);
            max_XOR = max(curr_XOR, max_XOR);
        }
        return max_XOR;
    }

};


int main() {
    fastio();

    int arr[] = {3,9,5,25,10,2};
    Trie t;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<t.max_XOR(arr,n);

    return 0;
}