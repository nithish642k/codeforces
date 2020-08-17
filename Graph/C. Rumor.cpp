/*
Vova promised himself that he would never play computer games...
But recently Firestorm — a well-known game developing company — published their newest game,
World of Farcraft, and it became really popular. Of course, Vova started playing it.

Now he tries to solve a quest. The task is to come to a settlement named Overcity and spread a rumor in it.

Vova knows that there are n characters in Overcity. Some characters are friends to each other, and they share information they got.
Also Vova knows that he can bribe each character so he or she starts spreading the rumor;
i-th character wants c i gold in exchange for spreading the rumor.
When a character hears the rumor, he tells it to all his friends, and they start spreading the rumor to their friends (for free), and so on.

The quest is finished when all n characters know the rumor. What is the minimum amount of gold Vova needs to spend in order to finish the quest?
Take a look at the notes if you think you haven't understood the problem completely.

Input
The first line contains two integer numbers n and m (1≤n≤105,0≤m≤105) — the number of characters in Overcity and the number of pairs of friends.

The second line contains n integer numbers c i (0≤c i≤109) — the amount of gold i-th character asks to start spreading the rumor.

Then m lines follow, each containing a pair of numbers ( x i,y i) which represent that characters x i and y i are friends (1≤x i,y i≤n, x i≠y i).
It is guaranteed that each pair is listed at most once.

Output
Print one number — the minimum amount of gold Vova has to spend in order to finish the quest.

Examples

input:
5 2
2 5 3 4 8
1 4
4 5
output:
10

input:
10 0
1 2 3 4 5 6 7 8 9 10
output:
55

input:
10 5
1 6 2 7 3 8 4 9 5 10
1 2
3 4
5 6
7 8
9 10
output:
15

Note
In the first example the best decision is to bribe the first character (he will spread the rumor to fourth character,
and the fourth one will spread it to fifth). Also Vova has to bribe the second and the third characters, so they know the rumor.

In the second example Vova has to bribe everyone.

In the third example the optimal decision is to bribe the first, the third, the fifth, the seventh and the ninth characters.

*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void dfs(vector<vector<ll>>&adj,vector<bool>&visited,ll x,vector<ll>&coins,ll &mini)
{
    visited[x]=true;
    mini=min(mini,coins[x]);
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        {
            dfs(adj,visited,adj[x][i],coins,mini);
        }
    }
}
int main()
{
    ll n,p;
    cin>>n>>p;
    vector<ll>coins(n);
    for(ll i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    vector<vector<ll>>adj(n);
    ll a,b;
    for(ll i=0;i<p;i++)
    {
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool>visited(n,false);
    ll res=0;
    for(ll i=0;i<n;i++)
    {
        ll mini=INT_MAX;
        if(!visited[i])
        {
            dfs(adj,visited,i,coins,mini);
            res+=mini;
        }
    }
    cout<<res;
    return 0;
}
