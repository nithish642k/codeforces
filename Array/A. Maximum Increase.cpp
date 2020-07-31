/*
You are given array consisting of n integers. Your task is to find the maximum length of an increasing subarray of the given array.

A subarray is the sequence of consecutive elements of the array.
Subarray is called increasing if each element of this subarray strictly greater than previous.

Input
The first line contains single positive integer n (1≤n≤105) — the number of integers.

The second line contains n positive integers a 1,a 2,...,a n (1≤a i≤109).

Output
Print the maximum length of an increasing subarray of the given array.

Examples
input:
5
1 7 2 11 15
output:
3

input:
6
100 100 100 100 100 100
output:
1

input:
3
1 2 3
output:
3
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int max_length=0;
    int length=1;
    for(int i=1;i<n;i++)
    {
        if(nums[i]>nums[i-1])
        {
            length++;
        }
        else
        {
            max_length=max(max_length,length);
            length=1;
        }
    }
    max_length=max(max_length,length);
    cout<<max_length;
    return 0;
}
