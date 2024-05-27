#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


bool dfs(int crs,vector<bool>& visited, unordered_map<int,vector<int>> &m){
    // if no prerequisite, course can be completed
    if(m.count(crs)==0)
        return true;
    
    // visited array for current dfs path
    visited[crs]=true;
        
    for(auto nbr : m[crs]){
        if(visited[nbr])
            return false;
        
        bool canComp = dfs(nbr,visited,m);
        if(canComp==false)
            return false;
    } 
    // if course can be completed, take out crs from dfs stack, 
    // set prerequisite to 0 for saving time as we know it can be completed
    visited[crs]=false;
   // m[crs] = {};
    m.erase(crs);
    return true;
}



bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,vector<int>> m;
    vector<bool> visited(numCourses,false);
    
    // creating hashmap for courses:prerequisite
    for(auto rows : prerequisites)
        m[rows[0]].push_back(rows[1]); 
        
    // run dfs for every component as there can be disconnected components
    for(int i=0;i<numCourses;i++){
        if( dfs(i,visited,m) == false)
            return false;          
    }
    return true;
}



int main()
{
    int numCourses = 4;
    vector<vector<int>> v = {{0,1},{0,2},{1,2},{2,3}};

    cout<<canFinish(numCourses,v);

    
    return 0;
}