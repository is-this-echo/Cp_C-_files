/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    


/*
ride(desert, fuel) -> bool 

'.' -> sand 
'c' -> car 
'o' -> oasis 
'1-9' -> refuel 
'r' -> rocks 


 o -> (0,4)
 c -> (3, 2)
const desert = [
    ['.','.','.','o'],
    ['.','.','.','.'],
    ['.','.','.','.'],
    ['.','c','.','.']
];

ride(desert, 3) => false
ride(desert, 5) => true


const desertWithStation = [
    ['.','.','.','o'],
    ['.','.', 2 ,'.'],
    ['.','.','.','.'],
    ['.','c','.','.']
];

ride(desertWithStation, 3) => true
ride(desertWithStation, 5) => true

const desertWithStationAndRocks = [
    ['.','.','.','o'],
    ['.','r','r','.'],
    ['.','.','r','r'],
    ['c','.','.', 20]
];

ride(desertWithStationAndRocks, 2) => false
ride(desertWithStationAndRocks, 3) => true // the car visits some fields twice

*/

struct Point
{
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    int getDistance(const Point& p) const
    {
        return abs(p.x - x) + abs(p.y - y);
    }
};


// Use Manhattan distance to find the distance b/w the car and the oasis,
// if the fuel required is greater than the distance return false.
// Given a single fuel station, calculate the distance b/w the car/fuel station and
// b/w fuel station/oasis, if the sum of these distances is greater than fuel of the car, return false.
bool desert(vector<vector<char>>& grid, int fuel)
{
    Point car, oasis, fuelStn;
    int extraFuel = 0;

    for (int i = 0; i < desert.size(); ++i)
    {
        for (int j = 0; j < desert[0].size(); ++j)
        {
            if (desert[i][j] == "c")
                car{i,j};
            
            if (desert[i][j] == "o")
                oasis{i,j};

            if (std::isdigit(desert[i][j]))
            {
                fuelStn{i,j};
                extraFuel = desert[i][j] - '0';
            }
        }
    }

    int totalDistance = car.getDistance(fuelStation) + oasis.getDistance(fuelStation);
    return totalDistance <= fuel + fuelCollected || car.getDistance(oasis) <= fuel;

}


pair<int, int> findStart(vector<vector<string>>& desert)
{
    for (int i = 0; i < desert.size(); ++i)
        for (int j = 0; j < desert[0].size(); ++j)
            if (desert[i][j] == "c")
                return {i, j};

    return {-1, -1};
}


// TC = O(m*n*F), F -> number of different fuel levels reachable
// SC = O(m * n), for visited array and queue
bool ride(vector<vector<string>>& desert, int gas)
{
    int m = desert.size();
    int n = desert[0].size();
    // visited[i][j] -> the last time we visited this cell what was the fuel remaining
    vector<vector<int>> visited(m, vector<int>(n, -1));

    auto [sr, sc] = findStart(desert);

    if (sr == -1)
        return false;

    queue<vector<int>> q; // x, y, gas left after visiting (x,y)
    q.push({sr, sc, gas});

    vector<int> dx{0, 0, 1, -1};
    vector<int> dy{1, -1, 0, 0};

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int x = curr[0];
        int y = curr[1];
        int currGas = curr[2];

        if (currGas < 0)
            continue;

        if (desert[x][y] == "o")
            return true;

        if (desert[x][y].length() > 0 && std::isdigit(desert[x][y][0]))
            currGas += stoi(desert[x][y]);

        if (visited[x][y] != -1 && visited[x][y] >= currGas)
            continue;
    
        visited[x][y] = currGas;

        if (currGas == 0)
            continue;

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || desert[nx][ny] == "r")
                continue;
            
            q.push({nx, ny, currGas - 1});
        }
    }
    return false;
}

    
int main() {
    fastio();

    vector<vector<string>> desert = {
        {"c", "", "r", "o"},
        {"", "2", "", ""},
        {"", "r", "1", ""}
    };

    cout << "Initial fuel = 2, " << (ride(desert, 2) ? "Can reach oasis" : "Cannot reach oasis") << endl;
    cout << "Initial fuel = 3, " << (ride(desert, 3) ? "Can reach oasis" : "Cannot reach oasis") << endl;

    return 0;
}