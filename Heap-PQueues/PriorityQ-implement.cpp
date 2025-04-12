#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;


// min-heap implementation
class Heap {
    vector<int>v;

    void heapify(int i){
        int left = 2*i, right = 2*i+1;
        int minIdx =i;

        if(left<v.size() && v[left]<v[minIdx])
            minIdx = left;

        if(right<v.size() && v[right]<v[minIdx])
            minIdx = right;
        
        if(minIdx!=i){
            swap(v[i],v[minIdx]);
            heapify(minIdx);
        }
    }

public: 
    Heap(int default_size=10){
        v.reserve(default_size+1);
        v.push_back(-1);
    };

     void push(int data){
         v.push_back(data);

         int index = v.size()-1;
         int parent = index/2;
        
        while(index>1 && v[index]<v[parent]){
            swap(v[index],v[parent]);
            index = parent;
            parent = parent/2;
        }
     }

     int top(){
         return v[1];
     }
 
     void pop(){
         int idx = v.size()-1;

         swap(v[1],v[idx]);
         v.pop_back();
         heapify(1);
     }

     bool empty(){
         return v.size()==1;
     }
};
 
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    return 0;
}