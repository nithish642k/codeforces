/*
Sereja has an array a, consisting of n integers a 1, a 2, ..., a n.
The boy cannot sit and do nothing, he decided to study an array. Sereja took a piece of paper and wrote out m integers l 1,l 2,...,l m (1≤l i≤n).
For each number l i he wants to know how many distinct numbers are staying on the positions l i, l i+1, ..., n.

Formally, he want to find the number of distinct numbers among a l i,a l i+1,...,a n.?
Sereja wrote out the necessary array elements but the array was so large and the boy was so pressed for time.
Help him, find the answer for the described question for each l i.

Input
The first line contains two integers n and m (1≤n,m≤105).
The second line contains n integers a 1, a 2, ..., a n (1≤a i≤105) — the array elements.

Next m lines contain integers l 1,l 2,...,l m. The i-th line contains integer li (1≤l i≤n).

Output
Print m lines — on the i-th line print the answer to the number l i.

Examples
input:
10 10
1 2 3 4 1 2 3 4 100000 99999
1
2
3
4
5
6
7
8
9
10
output:
6
6
6
6
6
5
4
3
2
1

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    unordered_set<int>s;
    vector<int>dp(n);
    for(int i=n-1;i>=0;i--)
    {
        s.insert(nums[i]);
        dp[i]=s.size();
    }
    int x;
    for(int i=0;i<q;i++)
    {
        cin>>x;
        x--;
        cout<<dp[x]<<endl;
    }
    return 0;
}
