#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;
    
    // O(m+n) space complexity
void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n = matrix[0].size();

    unordered_set<int>rows;
    unordered_set<int>cols;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    
    for(auto x : rows){
        for(int j=0;j<n;j++)
            matrix[x][j]=0;
    }
    
    for(auto x : cols){
        for(int i=0;i<m;i++)
            matrix[i][x]=0; 
    }
}


void printMatrix(vector<vector<int>>&grid){
    for(auto x : grid){
        for(auto y : x)
            cout<<y<<" ";
        cout<<"\n";
    }
    cout<<"\n\n";
}


 // O(1) space complexity
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size(); 
    int firstrow = 5;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                matrix[0][j]= 0;
                if(i>0)
                    matrix[i][0]=0;
                else
                    firstrow=0;
            }
        }
    }
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0 || matrix[i][0]==0)
                matrix[i][j]=0;
            }
    }
    
    if(matrix[0][0]==0)
        for(int i=0;i<m;i++)
            matrix[i][0]=0;
    
    
    if(firstrow==0)
        for(int i=0;i<n;i++)
            matrix[0][i]=0;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<vector<int>> grid = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    printMatrix(grid);
    setZeroes(grid);
    printMatrix(grid);
    
    return 0;
}