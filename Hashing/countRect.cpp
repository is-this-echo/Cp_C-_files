#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};


class Compare {
public:
    bool operator()(const Point p1, const Point p2){
        if(p1.x==p2.x)
            return p1.y<p2.y;
        return p1.x<p2.x;
    }
};


// time complexity : O(n^2logn)
int countRect(vector<Point> p){
    set<Point, Compare> s;
    int n = p.size();
    int ans=0;

    for(auto points : p)
        s.insert(points);

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            
            Point p1 = p[i];
            Point p2=p[j];

            if(p1.x==p2.x || p1.y==p2.y)
                continue;
            
            Point p3(p2.x,p1.y);
            Point p4(p1.x,p2.y);

            if(s.find(p3)!=s.end() && s.find(p4)!=s.end())
                ans++;

        }
    }
        return ans/2;
}


int main()
{   
    vector<Point> p;
    int x,y,n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        Point temp(x,y);
        p.push_back(temp);
    }

    cout<<"The number of rectangles formed are : "<<countRect(p)<<endl;

    return 0;
}