/*
One day, Twilight Sparkle is interested in how to sort a sequence of integers a 1,a 2,...,a n in non-decreasing order.
Being a young unicorn, the only operation she can perform is a unit shift. That is, she can move the last element of the sequence to its beginning:

a 1, a 2, ..., a n → a n, a 1, a 2, ..., a n - 1.
Help Twilight Sparkle to calculate: what is the minimum number of operations that she needs to sort the sequence?

Input
The first line contains an integer n (2 ≤ n ≤ 105). The second line contains n integer numbers a 1,a 2,...,a n (1≤a i≤105).

Output
If it's impossible to sort the sequence output -1. Otherwise output the minimum number of operations Twilight Sparkle needs to sort it.

Examples

input:
2
2 1
output:
1

input:
3
1 3 2
output:
-1

input:
2
1 2
output:
0
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    int count=0;
    int start=-1;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        if(i!=0&&nums[i]<nums[i-1])
        {
            count++;
            start=i;
        }
    }
    if(count==0)
    {
        cout<<"0";
    }
    else if(count==1&&nums[nums.size()-1]<=nums[0])
    {
        cout<<n-start;
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}
