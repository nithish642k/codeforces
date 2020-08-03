/*
Jzzhu has invented a kind of sequences, they meet the following property:
f1=x; f2=y; for all i (i>=2),fi= fi-1 + fi+1
You are given x and y, please calculate f n modulo 1000000007 (109+7).

Input
The first line contains two integers x and y (|x|,|y|≤109).
 The second line contains a single integer n (1≤n≤2·109).

Output
Output a single integer representing f n modulo 1000000007 (109+7).

Examples
input:
2 3
3
output:
1

input:
0 -1
2
output:
1000000006

Note
In the first sample, f 2=f 1+f 3, 3=2+f 3, f 3=1.

In the second sample, f 2=-1; -1 modulo (109+7) equals (109+6).

intuition:
the sequence repeats the same first six numbers
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long m=1000000007;
    long long x,y,n;
    cin>>x>>y>>n;
    n--;
    vector<long long>dp(7);
    dp[0]=(x+m)%m;
    dp[1]=(y+m)%m;
    for(int i=2;i<=6;i++)
    {
        long long a=dp[i-1]-dp[i-2];
        dp[i]=(a+m)%m;
    }
    cout<<dp[n%6];
    return 0;
}
