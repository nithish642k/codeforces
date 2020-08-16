/*
Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases.
Next t lines contain descriptions of test cases.

Each test case contains a single integer n (1≤n≤109) — the number of cards.

It is guaranteed that the sum of n over all test cases does not exceed 109.

Output
For each test case output a single integer — the number of pyramids you will have constructed in the end.

Example
input:
5
3
14
15
24
1
output:
1
2
1
3
0
Note
In the first test, you construct a pyramid of height 1 with 2 cards. There is 1 card remaining, which is not enough to build a pyramid.

In the second test, you build two pyramids, each of height 2, with no cards remaining.

In the third test, you build one pyramid of height 3, with no cards remaining.

In the fourth test, you build one pyramid of height 3 with 9 cards remaining.
Then you build a pyramid of height 2 with 2 cards remaining. Then you build a final pyramid of height 1 with no cards remaining.

In the fifth test, one card is not enough to build any pyramids.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<long long>dp(100001);  // dp[i]->#cards needed to build a tower of height i
    dp[1]=2;
    for(int i=2;i<100001;i++)
    {
        dp[i]=dp[i-1]+(i-1)+(2*i);  // for a tower of height i,base has 2*i cards of height 1 with i-1 cards on tops
    }
    while(t--)
    {
        long long n;
        cin>>n;
        int count=0;
        for(int i=100000;i>=1;i--)
        {
            while(n>=dp[i])
            {
                n-=dp[i];
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
