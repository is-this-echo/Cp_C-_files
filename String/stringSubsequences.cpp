#include<iostream>
#include<string>
using namespace std;
 
#define ll long long
#define mod 1e9+7


void printSubseq(string input, string output){
    if(input.length()==0){
        cout<<output<<"\n";
        return ;
    }
    printSubseq(input.substr(1),output);
    printSubseq(input.substr(1),output+input[0]);
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string input, output="";
    cin>>input;

    printSubseq(input,output);

    return 0;
}