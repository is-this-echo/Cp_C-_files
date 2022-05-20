#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define ll long long
#define mod 1e9+7


void permute(string s, int l, int r, vector<string> &v){
    if(l==r){
        v.push_back(s);
        cout<<v.size()<<" "<<s<<"\n";
        return ;  
    }
    
    for(int i=l;i<=r;i++){
        // swap to get different patterns
        swap(s[l],s[i]);
        permute(s,l+1,r,v);
        // put back swapped elements in their place and branch out for next swap
        swap(s[l],s[i]);
    }
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<string> v;
    string s;
    
    cin>>s;

    int l=0,r = s.length()-1;
    permute(s,l,r,v);
    
    return 0;
}