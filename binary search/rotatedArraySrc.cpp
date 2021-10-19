#include<iostream>
#include<vector>
using namespace std;


// discontinuous straight lines
int search(vector<int>& a, int target) {
    int s=0,e=a.size()-1;
    
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==target)
            return mid;
        
        if(a[s]<=a[mid]){
            if(a[s]<=target && target<=a[mid])
                e = mid-1;
            else
                s=mid+1;
        }
        else{
            if(a[mid]<=target && target<=a[e])
                s=mid+1;
            else
                e=mid-1;
        }
    }
    return -1;
}



int main()
{
    vector<int> nums={4,5,6,7,0,1,2};
    int ans = search(nums,0);

    if(ans==-1)
        cout<<"Target element not found";
    else
        cout<<"Target element found at index "<<ans;

    return 0;
}