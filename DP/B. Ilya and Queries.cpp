/*
Ilya the Lion wants to help all his friends with passing exams.They need to solve the following problem to pass the IT exam.

You've got string s=s 1 s 2... s n ( n is the length of the string), consisting only of characters "." and "#" and m queries.
Each query is described by a pair of integers l i,r i (1≤l i<r i≤n). The answer to the query l i,r i is the number of such integers i
(l i≤i<r i), that s i=s i+1.

Ilya the Lion wants to help his friends but is there anyone to help him? Help Ilya, solve the problem.

Input
The first line contains string s of length n (2≤n≤105). It is guaranteed that the given string only consists of characters "." and "#".
The next line contains integer m (1≤m≤105) — the number of queries.
Each of the next m lines contains the description of the corresponding query. The i-th line contains integers l i,r i (1≤l i<r i≤n).

Output
Print m integers — the answers to the queries in the order in which they are given in the input.

Examples
input:
......
4
3 4
2 3
1 6
2 6
output:
1
1
5
4

input:
#..###
5
1 3
5 6
1 5
3 6
3 4
output:
1
1
2
2
0
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int>dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
            dp[i]=1;
        dp[i]+=dp[i-1];
    }
    int q;
    cin>>q;
    int start,end;
    for(int i=0;i<q;i++)
    {
        cin>>start>>end;
        cout<<dp[end-1]-dp[start-1]<<endl;
    }
}
