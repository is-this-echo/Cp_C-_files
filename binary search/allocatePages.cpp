
/* Allocate books such that max number of pages(can be from one or more books)
allocated to a student is minimum.
arr = [12,34,67,90], n=4, students = 2

conditions -> 1) Each student should get atleast 1 book
              2) Every book should be allocated to only one student, no sharing
              3) Books allocation can be done only in contiguous order like st1 -> 12,34
                not 12,67 as they are not contiguous elements. 
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

#define ll long long
#define mod 998244353

double eps = 1e-12;

// Checkout Capacity To Ship Packages Within D Days from leetcode for better understanding
bool allocationPossible(vector<int> &arr,int s, int max_pages){
    int sn=1, n = arr.size(); // we can start with sn = 0
    int allocated = 0;

    for(int i=0;i<n;i++){
        // since the pages required must contain one whole book, partial allocation not possible
        if(max_pages<arr[i]) // this line will not be required if the search space start with the
            return false;    // max pages book as it definitely has to be assigned to one student

        // count how many students are required to distribute curr_min pages
        if(allocated+arr[i]>max_pages){
                sn++;
                allocated=arr[i];

            if(sn>s) // can also check for sn == s, this means we have already allocated pages
                return false; // to req students and we have extra pages left so return false
        } 
        else 
            allocated+=arr[i];
    }
    return true;
}


bool allocationPossible(vector<int>& arr, int s, int max_pages)
{
    int sn = 0;
    int allocatedPages = 0;
    for (int i = 0; i < n; i++)
    {
        if (allocatedPages + arr[i] > max_pages)
        {
            sn++;
            allocated = arr[i];

            if (sn == s)
                return false
        } 
        else
        {
            allocated += arr[i];
        }
    }
    return true;
}


int allocateBooks(vector<int> &arr, int s){
    int n =arr.size();

    sort(arr.begin(), arr.end());

    // defining search space, ideally low = * max(arr.begin(), arr.end())
    int low =arr[0], high=0;
    int ans=-1;
    high = accumulate(arr.begin(), arr.end(), 0);

    while(low<=high){
        int mid=(low+high)/2;

        if(allocationPossible(arr,s,mid)){
            ans = mid;
            high=mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    vector<int> arr = {12,34,67,90};
    int students = 2;

    cout<<allocateBooks(arr,students);

    return 0;
}