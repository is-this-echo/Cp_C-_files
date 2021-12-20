
// Leetcode 653. Two Sum IV - Input is a BST


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

bool findTarget(TreeNode* root, int k) {
    vector<int>arr;
    inOrderTraversal(root,arr);
    
    int n = arr.size();
    
    for(int i=0;i<n-1;i++){
        int x = k-arr[i];
        
        int s=i+1;
        int e = n-1;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(arr[mid]==x)
                return true;
            
            else if(arr[mid]>x)
                e=mid-1;
            else
                s=mid+1;
        }
    }
    return false;
}



void inOrderTraversal(TreeNode* root, vector<int>&arr){
    if(!root)
        return ;
    
    inOrderTraversal(root->left,arr);
    arr.push_back(root->val);
    inOrderTraversal(root->right,arr);
}

    

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}