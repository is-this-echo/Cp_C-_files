
#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 1e9+7


void genSubarrays(vector<int> &nums, vector<vector<int>>&store){
    int n =nums.size();
    vector<int> temp;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            temp.push_back(nums[j]);
            store.push_back(temp);
        }
        temp.clear();
    }
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    vector<int> nums = {0,1,1,0,1};
    vector<vector<int>> store;
    vector<int> temp;

    genSubarrays(nums,store);

    for(auto x: store){
        for(auto y : x)
            cout<<y<<" ";
        cout<<"\n";
    }
    

    return 0;
}