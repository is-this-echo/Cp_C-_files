#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;


class Node{
public:
    int x, y, s_dist;

    Node(int x, int y, int s_dist){
        this->x=x;
        this->y=y;
        this->s_dist=s_dist;
    }
};

class Compare{
    public:
    bool operator()(const Node &a,  const Node &b){
    return a.s_dist<=b.s_dist;
    }
};


int shortest_path(vector<vector<int>> grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    set<Node,Compare> s;

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    dist[0][0]=grid[0][0];
    s.insert((Node(0,0,dist[0][0])));

    while(!s.empty()){
        auto curr = s.begin();

        int cx = curr->x;
        int cy = curr->y;
        int cdist = curr->s_dist;
        s.erase(curr);

        for(int k=0;k<4;k++){
            int nx = cx+dx[k];
            int ny = cy+dy[k];

            if(nx>=0 && nx<m && ny>=0 && ny<n && cdist+grid[nx][ny]<dist[nx][ny]){
                Node temp(nx,ny,dist[nx][ny]);
                auto p = s.find(temp);
                if(p!=s.end())
                    s.erase(p);

                dist[nx][ny] = cdist+grid[nx][ny];
                s.insert(Node(nx,ny,dist[nx][ny]));

            }
        }

    }
        return dist[m-1][n-1];
}



int main()
{
    vector<vector<int>> matrix = {  {31,100,65,12,18},
                                    {10,13,47,157,6},
                                    {100,113,174,11,33},
                                    {88,124,41,20,140},
                                    {99,32,111,41,20}};

    cout<<"Shortest path distance is-> "<<shortest_path(matrix); 

    return 0;
}