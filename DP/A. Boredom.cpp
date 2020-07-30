/*
Alex doesn't like boredom. That's why whenever he gets bored, he comes up with games.
One long winter evening he came up with a game and decided to play it.

Given a sequence a consisting of n integers. The player can make several steps.
In a single step he can choose an element of the sequence (let's denote it a k) and delete it,
at that all elements equal to a k + 1 and a k - 1 also must be deleted from the sequence. That step brings a k points to the player.

Alex is a perfectionist, so he decided to get as many points as possible. Help him.

Input
The first line contains integer n (1≤n≤105) that shows how many numbers are in Alex's sequence.
The second line contains n integers a 1, a 2, ..., a n (1 ≤ a i ≤ 105).

Output
Print a single integer — the maximum number of points that Alex can earn.

Examples
input:
2
1 2
output:
2

input:
3
1 2 3
output:
4

input:
9
1 2 1 3 2 2 2 2 3
output:
10
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    unordered_map<long long,long long>count;
    int num;
    for(long long i=0;i<n;i++)
    {
        cin>>num;
        count[num]++;
    }
    vector<long long>dp(100001);
    dp[0]=0;
    dp[1]=count[1];
    for(long long i=2;i<100001;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+i*count[i]);
    }
    cout<<dp[100000];
}
