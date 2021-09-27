#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;
    s.push(asteroids[0]);

    for(int i=1;i<asteroids.size();i++){
        if(asteroids[i]<0 && abs(asteroids[i])<s.top())){

        }

    }

}



int main()
{
    vector<int> ast = {10,2,-5};
    vector<int> temp = asteroidCollision(ast);

    for(auto s : temp)
        cout<<s<<endl;

    return 0;
}