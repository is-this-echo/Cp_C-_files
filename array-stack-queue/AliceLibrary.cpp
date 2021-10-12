
#include <iostream>
#include<string>
#include<stack>
using namespace std;


int main() {
	string s,p;
	getline(cin,s);

	int n = s.length();
	stack<char> stk;

	for(int i=0;i<n;i++){
		if(s[i]!='\\'){
			stk.push(s[i]);
		}
		else{
			while(stk.top()!='/'){
				p.push_back(stk.top());
				stk.pop();
			}
			stk.pop();
			if(stk.empty()){
				cout<<p;
				return 0;
			}

			// putting the reversed string back in the stack character wise 
			for(int j=0;j<p.length();j++)
				stk.push(p[j]);
			p.erase();
			
		}
	}
	return 0;
	
}

