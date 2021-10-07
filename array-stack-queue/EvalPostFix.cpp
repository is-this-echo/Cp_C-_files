/*
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        
        for(int i=0;i<n;i++){
            string s = tokens[i];
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans;
                
                switch(s[0]){
                    case '+': ans=a+b;
                                break;
                    case '-' : ans = a-b;
                                break;
                    case '*' : ans = a*b;
                                break;
                    case '/' : ans = a/b;
                                break;
                }
                st.push(ans);
            }
            else
                st.push(stoi(s));
        }
        return st.top();
    }


int main()
{
    vector<string> s = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout<<evalRPN(s);
    
    return 0;
}