#include<iostream>
#include<string>
#include<vector>
using namespace std;


string cipher(string &key, string &buf){
    string code="";

    vector<int> arr;
    for(int i=0;i<key.length();i++){
        arr.push_back(key[i]-'a');
    }

    vector<int>shift;
    for(int i=0;i<buf.length();i++){
        shift.push_back(arr[i%key.length()]);
        code.push_back((shift[i]+(buf[i]-'a'))%26+'a');
    }
    return code;
}


int main()
{   
    string key = "caterpillar";
    string buf = "night";

    cout<<cipher(key,buf);
    
    return 0;
}