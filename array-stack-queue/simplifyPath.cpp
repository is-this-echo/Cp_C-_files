/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    


string simplifyPath(string path){
    vector<string>tokens;
    string token;
    istringstream iss(path);

    while(getline(iss,token,'/')){
        if(token=="" || token==".")
            continue;
        
        tokens.push_back(token);
    }

    vector<string>stack;
    if(path[0]=='/')
        stack.push_back("");

    for(string s : tokens){
        if(s==".."){
            if(stack.size()==0 || stack.back()=="..")
                stack.push_back("..");
            
            else if(stack.back()!=""){
                stack.pop_back();
            }
        }

        else{
            stack.push_back(s);
        }
    }
        
    if(stack.size()==1 && stack[0]=="")
        return "/";

    ostringstream oss;
    int i=0;

    for(string s : stack){
        if(i!=0)
            oss << "/";
        i++;
        oss << s;
    }
    return oss.str();
}
 

int main() {
    fastio();

    string cmd = "/../x/y///././c/./d/../../m/..///z/";
    cout<<simplifyPath(cmd);
    
    return 0;
}