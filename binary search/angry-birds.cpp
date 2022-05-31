
/* 
There is a long wire along a straight line, which contains N bird nests at positions x1,x2,..xN.
There are B(B<=N) birds, which become angry towards each other once put into a nest. To put the birds from hurting each other
you want to assign birds to nests such that minimum distance between any two birds is as large as possible.
What is the largest minimum distance possible b/w 2 birds.

Input
N=5 nests
B=3 birds , Nests = [1,2,4,8,9], assume not  sorted by default

Output = 3
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool canPlaceBirds(vector<int> &nests, int N, int B, int dist){
    // one can ask that why do we need to start from the first nest, reason being
    // that putting one bird in the first nest always increases separation from the next bird 
    int birds = 1;
    int prev_loc = nests[0];

    for(int i=1;i<N;i++){
        int curr_loc = nests[i];

        if(curr_loc-prev_loc>=dist){
            birds++;
            prev_loc = curr_loc;
            if(birds==B){
                return true;
            }
        }
    }
    return false;
}



int main()
{
    vector<int> nests{9,4,8,2,1};
    int N = nests.size();
    int birds = 3;

    // define search space, here it is the distance between nests,so we find out the max and min distance
    sort(nests.begin(),nests.end());
    int s=0;
    int e = nests[N-1]-nests[0];
    int ans=-1;

    while(s<=e){
        int mid = (s+e)/2; 
        // s + (e-s)/2
        
        bool canPlace  = canPlaceBirds(nests, N, birds,mid);
        if(canPlace){
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }
    }

    cout<<ans;

    return 0;
}