
// 1423. Maximum Points You Can Obtain from Cards

#include<iostream>
#include<vector>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
// O(k) time complexity
    int n = cardPoints.size();
    int max_score,curr_sum=0;

// start window, required sum will be the sum of elements outside the window
    int i=0, j = n-k-1;
    for(int x=j+1;x<n;x++)
        curr_sum+=cardPoints[x];
 
    max_score = curr_sum;
    
    while(j<n-1){ 
        j++,i++;
        curr_sum = curr_sum-cardPoints[j]+cardPoints[i-1];
        max_score = max(max_score,curr_sum);
    }  

    return max_score;
}


int main()
{
    vector<int> cards  = {100,40,17,9,73,75};
    int k =3;

    cout<<maxScore(cards,k)<<endl;

    return 0;
}