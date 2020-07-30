/*
Polycarpus has a ribbon, its length is n. He wants to cut the ribbon in a way that fulfils the following two conditions:

After the cutting each ribbon piece should have length a, b or c.
After the cutting the number of ribbon pieces should be maximum.
Help Polycarpus and find the number of ribbon pieces after the required cutting.

Input
The first line contains four space-separated integers n, a, b and c (1≤=n,a,b,c≤=4000) — the length of the original ribbon
and the acceptable lengths of the ribbon pieces after the cutting, correspondingly. The numbers a, b and c can coincide.

Output
Print a single number — the maximum possible number of ribbon pieces. It is guaranteed that at least one correct ribbon cutting exists.

Examples
input:
5 5 3 2
output:
2

input:
7 5 5 2
output:
2
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum;
    cin>>sum;
    vector<int>coins(3);
    for(int i=0;i<3;i++)
    {
        cin>>coins[i];
    }
    vector<vector<int>>dp(4,vector<int>(sum+1,0));
    for(int j=1;j<=sum;j++)
    {
        dp[0][j]=INT_MIN;
    }
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coins[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
        }
    }
    cout<<dp[3][sum];
}
