#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;

// data structure to be used in graphs
class Node{
public:
    string name;
    list<string>nbrs;

    Node(string name){
        this->name = name;
    }
};

// Creating the adjacency list representation of graph
class Graph{
    unordered_map<string,Node*> m;

public:
    Graph(vector<string> cities){
        for(auto city: cities){
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir=false){
        m[x]->nbrs.push_back(y);
        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjList(){
        for(auto cityPair : m){
            auto city = cityPair.first;
            Node * node = cityPair.second;

            cout<<city<<"--> ";
            for(auto nbrs : node->nbrs ){
                cout<<nbrs<<", ";
            }
            cout<<endl;
        }
    }

};


int main(){

    vector<string> cities = {"LasVegas", "NewYork","Kolkata","Tokyo"};

    Graph g(cities);
    g.addEdge("LasVegas","NewYork");
    g.addEdge("LasVegas","Kolkata");
    g.addEdge("NewYork","Kolkata");
    g.addEdge("NewYork","Tokyo");
    g.addEdge("Tokyo","Kolkata");
    
    g.printAdjList();

    return 0;
}