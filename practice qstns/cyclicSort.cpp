#include<iostream>
#include<vector>
using namespace std;


void cyclicSort(vector<int> &arr){
    int i=0;

    while(i<arr.size()){
        if(arr[i]!=i+1)
            swap(arr[i],arr[arr[i]-1]);
        else 
            i++;
    }
}

int main()
{
    vector<int> arr = {9,7,1,2,4,6,5,8,3};

    cyclicSort(arr);
    cout<<" After sorting : "<<endl;
    for(auto i : arr)
        cout<<i<<" ";

    return 0;
}