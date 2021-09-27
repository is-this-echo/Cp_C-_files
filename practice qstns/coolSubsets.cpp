#include<iostream>
using namespace std;

long long int coolSubset(int arr[], int k, int n){
int j=k-1,nodd=0;
long long divide = 1e9+7;
long long multiply =1, sum=0;


for(int i=0;i<=j;i++){
    if(arr[i]%2!=0)
        nodd++;
    multiply*=arr[i];
}

for(int i=0;i<n-k-1;i++){
    if(nodd%2==0 && j-i+1==k){
        sum+=multiply;
    }

    multiply/=arr[i];
    if(arr[i]%2!=0)
        nodd--;
    j++;
    multiply*=arr[j];

    if(arr[j]%2!=0){
        nodd++;
    }
}
return sum;
}



int main()
{
    int arr[]={1,4,5,7};
    int k=2;

    cout<<coolSubset(arr,sizeof(arr)/sizeof(arr[0]),k);

    return 0;
}