#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


int lengthOfLongestSubstring(string s) {   
    int ls=0,s_idx=0;
    unordered_map<char,int> m;
    
    for(int i=0;i<s.length();i++){
        // if char is not in the map or it exists before the start index
        if(m.count(s[i])==0 || m[s[i]]<s_idx){
            m[s[i]]=i;
            ls = max(ls,i-s_idx+1);
        }
        else{
            // shift the start index to 1 + the index of previous char position in the string
            s_idx = m[s[i]]+1;
            m[s[i]]=i;
        }
    }
    return ls;
}



int main()
{
    string s = "abcabcbb";
    string a = "tmmzuxt";

    cout<<lengthOfLongestSubstring(s)<<endl;
    cout<<lengthOfLongestSubstring(a)<<endl;

    
    return 0;
}