/* 
Amongst n number of people in a park. One of them has a virus. 
Let's assume all the folks are standing in an x-axis line. The positions of people are given as input.
 A contaminated person can spread the virus up to d distance. Find the minimum and maximum spread 
 of the virus that could occur.
Input: n = 5, d = 5, [1,3,5,9,14]
Output: [1, 3]
minimum spread = 1 by 14, maximum spread = 3 by 5
I have solved that problem using the Binary Search Method with O(NlogN) 
Time Complexity & O(1) Space Complexity.
*/

/*
my logic : sort the array first, then iterate over the array & for each element x,
find lower bounds of x-d & x+d, if element at lower bound of x+d  > x+d, then 
spread = l2-l1-2 else if lower_bound(x+d)==arr[idx] then spread = l2-l21-1,
keep track of the max and min spreads in a 2 variables
*/

#include<iostream>
using namespace std;

int main()
{
    
    return 0;
}