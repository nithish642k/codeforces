/*
Iahub got bored, so he invented a game to be played on paper.

He writes n integers a1,a2,...,an. Each of those integers can be either 0 or 1.
He's allowed to do exactly one move: he chooses two indices i and j (1≤i≤j≤n) and
flips all values a k for which their positions are in range [i,j] (that is i≤k≤j).
Flip the value of x means to apply operation x=1 - x.

The goal of the game is that after exactly one move to obtain the maximum number of ones. Write a program to solve the little game of Iahub.

Input
The first line of the input contains an integer n (1≤n≤100). In the second line of the input there are n integers: a1,a2...,an.
It is guaranteed that each of those n values is either 0 or 1.

Output
Print an integer — the maximal number of 1s that can be obtained after exactly one move.

Examples
input:
5
1 0 0 1 0
output:
4

input:
4
1 0 0 1
output:
4

input:
8
1 0 0 0 1 0 0 0
output:
7

Note
In the first case, flip the segment from 2 to 5 (i=2,j=5).
That flip changes the sequence, it becomes: [1 1 1 0 1]. So, it contains four ones. There is no way to make the whole sequence equal to [1 1 1 1 1].

In the second case, flipping only the second and the third element (i=2,j=3) will turn all numbers into 1.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    int ones=0,zeros=0;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        if(nums[i]==1)
            ones++;
    }
    if(ones==n)
    {
        cout<<ones-1; // because,we must flip atleast one
        return 0;
    }
    int max_cont_zeros=0;
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        {
            count++;
        }
        else
        {
            max_cont_zeros=max(max_cont_zeros,count);
            if(count>0)
                count--;
        }
    }
     max_cont_zeros=max(max_cont_zeros,count);
    cout<<max_cont_zeros+ones;
}
