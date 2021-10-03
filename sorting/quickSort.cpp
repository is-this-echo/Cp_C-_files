#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int> &a, int s, int e){
    int i=s-1;
    int pivot = a[e];

    for(int j=s;j<e;j++){
        if(a[j]<pivot){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[e],a[i+1]);
    return i+1;
    // returns the correct index of the pivot element
}


// taking last element as the pivot element
void QuickSort(vector<int> &a, int s, int e){
    if(s>=e)
        return;

    int p = Partition(a,s,e);
    QuickSort(a,s,p-1);
    QuickSort(a,p+1,e);
}


int main()
{
    vector<int> arr {10,6,4,2,1,9,3,7};
    int n=arr.size();

    for(int x: arr)
        cout<<x<<" ";
    cout<<endl;

    QuickSort(arr,0,n-1);

    for(int x: arr)
        cout<<x<<" ";
    
    return 0;
}