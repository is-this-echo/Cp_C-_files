#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 1e9+7


// nxn matrices
vector<vector<int>> matrixMultiply(vector<vector<int>>&A, vector<vector<int>> &B){
    int n = A.size();
    vector<vector<int>> C(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){       
            for(int k=0;k<n;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}


// A^x = A^x/2 * A^x/2 if x is even and A^x = A* (A^x/2 * A^x/2) if x is odd
// Time complexity -> O(n^3 logx) , if done manually it would be O(n^3 x)
vector<vector<int>> matrixExpo(vector<vector<int>>&A, int x){
    if(x==1)
        return A;
    
    vector<vector<int>> resultBy2 = matrixExpo(A,x/2);
    vector<vector<int>> result = matrixMultiply(resultBy2,resultBy2);

    if(x&1)
        return matrixMultiply(result,A); 
    else 
        return result;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    //vector<vector<int>> a={{1,0},{2,6}};
    //vector<vector<int>> b = {{1,3},{1,0}};
    vector<vector<int>> d = {{1,0},{-1,2}};

    auto x = matrixExpo(d,5);

    for(auto r : x){
        for(auto c : r)
            cout<<c<<" ";
        cout<<"\n";
    }
    
    
    return 0;
}