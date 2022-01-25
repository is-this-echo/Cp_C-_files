#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
// O(k + (n-k)logk) time complexity
class Car{
public:
    string id;
    int x,y;

    Car(int x, int y, string s){
        this->x=x;
        this->y = y;
        id=s;
    }
    
    int dist() const{
        return x*x + y*y;
    }
};


class Compare {
public:
    bool operator()(const Car &a , const Car &b){
        return a.dist()<b.dist();
    }
};

void printKNearestCars(vector<Car>&cars, int k){
    priority_queue<Car, vector<Car>, Compare>pq(cars.begin(),cars.begin()+k);

    for(int i=k;i<cars.size();i++){
        if(cars[i].dist()<pq.top().dist()){
            pq.pop();
            pq.push(cars[i]);
        }
    }

    vector<string>ans;
    while(!pq.empty()){
        ans.push_back(pq.top().id);
        pq.pop();
    }

    reverse(ans.begin(),ans.end());

    for(auto s : ans)
        cout<<s<<"\n";

}

    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,k;
    cin>>n>>k;

    vector<Car>cars;
    int x,y;
    string s;

    for(int i=0;i<n;i++){
        cin>>s>>x>>y;
        
        Car temp(x,y,s);
        cars.push_back(temp);
    }

    printKNearestCars(cars,k);
    
    return 0;
}