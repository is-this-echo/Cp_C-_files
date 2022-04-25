#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> asteroidCollision(vector<int> &a) {
    stack<int> s;
    vector<int> ans;
    s.push(a[0]);

    for(int i=1;i<a.size();i++){

       while(!s.empty() && i<a.size() && s.top()>0 && a[i]<0 ){
           if(abs(s.top())>abs(a[i]))
               i++;

           else if(abs(s.top())<abs(a[i]))
            s.pop();

            else {
                s.pop();
                i++;
            }     
       }

       if(i<a.size()) 
        s.push(a[i]);
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}



int main()
{
    vector<int> ast = {1,-2,-2,-2,};
    vector<int> temp = asteroidCollision(ast);

    for(auto s : temp)
        cout<<s<<" ";

    return 0;
}