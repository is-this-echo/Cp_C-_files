#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 1e9+7


void rotate(vector<vector<int>>& matrix) {
    
    int n = matrix.size();        
    int left,right,top,bottom;
    left = 0;
    right= n-1;

    while(left<right){
        top=left, bottom = right;     

        for(int i=0;i<(right-left);i++){
            int temp = matrix[top][left+i];
            
            matrix[top][left+i] = matrix[bottom-i][left];
            matrix[bottom-i][left] = matrix[bottom][right-i];
            matrix[bottom][right-i] = matrix[top+i][right];
            matrix[top+i][right] = temp;
        }  
        left+=1;
        right-=1;
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