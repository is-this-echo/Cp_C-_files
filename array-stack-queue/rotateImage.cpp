#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 1e9+7


void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();        
    int l,r,top,bottom;
    l = 0;
    r= n-1;

    while(l<r){
        top=l, bottom = r;     

        for(int i=0;i<(r-l);i++){
            int temp = matrix[top][l+i];
            
            matrix[top][l+i] = matrix[bottom-i][l];
            matrix[bottom-i][l] = matrix[bottom][r-i];
            matrix[bottom][r-i] = matrix[top+i][r];
            matrix[top+i][r] = temp;
        }  
        l+=1;
        r-=1;
    }
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    vector<vector<int>> arr = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    cout<<"Array before rotation: "<<"\n";
    for(auto x: arr){
        for(auto c: x)
            cout<<c<<" ";
        cout<<"\n";
    }

    rotate(arr);

    cout<<"Array after rotating by 90 degrees :"<<'\n';
    for(auto x: arr){
        for(auto c: x)
            cout<<c<<" ";
        cout<<"\n";
    }

    return 0;
}