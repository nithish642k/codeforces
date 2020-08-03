/*
Petya and Vasya are playing a game. Petya's got n non-transparent glasses, standing in a row.
The glasses' positions are indexed with integers from 1 to n from left to right. Note that the positions are indexed but the glasses are not.

First Petya puts a marble under the glass in position s. Then he performs some (possibly zero) shuffling operations.
One shuffling operation means moving the glass from the first position to position p 1,
the glass from the second position to position p 2 and so on.
That is, a glass goes from position i to position p i.

Consider all glasses are moving simultaneously during one shuffling operation.
When the glasses are shuffled, the marble doesn't travel from one glass to another:
it moves together with the glass it was initially been put in.

After all shuffling operations Petya shows Vasya that the ball has moved to position t.
Vasya's task is to say what minimum number of shuffling operations Petya has performed or
determine that Petya has made a mistake and the marble could not have got from position s to position t.

Input
The first line contains three integers: n,s,t (1≤n≤105; 1≤s,t≤n) — the number of glasses,
the ball's initial and final position. The second line contains n space-separated integers: p 1,p 2,...,p n (1≤p i≤n)
— the shuffling operation parameters. It is guaranteed that all p i's are distinct.

Note that s can equal t.

Output
If the marble can move from position s to position t,
 then print on a single line a non-negative integer — the minimum number of shuffling operations,
  needed to get the marble to position t. If it is impossible, print number -1.

Examples

input:
4 2 1
2 3 4 1
output:
3

input:
4 3 3
4 1 3 2
output:
0

input:
4 3 4
1 2 3 4
output:
-1

input:
3 1 3
2 1 3
output:
-1

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s,t;
    cin>>n>>s>>t;
    vector<int>nums(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
    }
    vector<bool>visited(n+1,false);
    int count=0;
    while(s!=t&&!visited[s])
    {
        visited[s]=true;
        s=nums[s];
        count++;
    }
    if(s==t)
    {
        cout<<count;
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}
