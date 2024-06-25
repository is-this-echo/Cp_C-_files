
#include<iostream>
using namespace std;


void generateBrackets(string s, int n, int nob, int ncb, int i){
    // base case
    if(i==2*n){
        cout<<s<<endl;
        return;
    }

    if(nob<n)
        generateBrackets(s+'(',n,nob+1,ncb,i+1);

    if(nob>ncb)
        generateBrackets(s+')',n,nob,ncb+1,i+1);
        
}


int main()
{
    int n;
    string s;
    cin>>n;

    generateBrackets(s,n,0,0,0);
    return 0;
}