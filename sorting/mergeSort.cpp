#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;
    

void merge(vector<int> &arr, int s, int mid, int e){
    int i=s,j=mid+1;
    //int *temp = new int[e-s+1];
    
    vector<int>temp;

    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(arr[j]);
        j++;
    }
    
    int k=0;
    for(i=s;i<=e;i++){
        arr[i]=temp[k];
        k++;
    }
}


void mergeSort(vector<int> &arr, int s, int e){
    if(s<e){
        int mid= (s+e)/2;
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<int> arr=  {5,4,1,0,10,3,7,6};
    int n = arr.size();

    mergeSort(arr,0,n-1);

    for(auto x: arr)
        cout<<x<<" ";
    
    return 0;
}