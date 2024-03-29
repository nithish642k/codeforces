/*
Lunar New Year is approaching, and Bob decides to take a wander in a nearby park.

The park can be represented as a connected graph with n nodes and m bidirectional edges.
Initially Bob is at the node 1 and he records 1 on his notebook. He can wander from one node to another through those bidirectional edges.
Whenever he visits a node not recorded on his notebook, he records it.
After he visits all nodes at least once, he stops wandering, thus finally a permutation of nodes a1,a2,…,an is recorded.

Wandering is a boring thing, but solving problems is fascinating.
Bob wants to know the lexicographically smallest sequence of nodes he can record while wandering.
Bob thinks this problem is trivial, and he wants you to solve it.

A sequence x is lexicographically smaller than a sequence y if and only if one of the following holds:

x is a prefix of y, but x≠y (this is impossible in this problem as all considered sequences have the same length);
in the first position where x and y differ, the sequence x has a smaller element than the corresponding element in y.
Input
The first line contains two positive integers n and m (1≤n,m≤105), denoting the number of nodes and edges, respectively.

The following m lines describe the bidirectional edges in the graph. The i-th of these lines contains two integers ui and vi (1≤ui,vi≤n),
representing the nodes the i-th edge connects.

Note that the graph can have multiple edges connecting the same two nodes and self-loops.
It is guaranteed that the graph is connected.

Output
Output a line containing the lexicographically smallest sequence a1,a2,…,an Bob can record.

Examples

input:
3 2
1 2
1 3
output:
1 2 3

input:
5 5
1 4
3 4
5 4
3 2
1 5
output:
1 4 3 2 5

input:
10 10
1 4
6 8
2 5
3 7
9 4
5 6
3 4
8 10
8 9
1 10
output:
1 4 3 7 9 8 6 5 2 10

Note:
In the first sample, Bob's optimal wandering path could be 1→2→1→3. Therefore,
Bob will obtain the sequence {1,2,3}, which is the lexicographically smallest one.

In the second sample, Bob's optimal wandering path could be 1→4→3→2→3→4→1→5.
Therefore, Bob will obtain the sequence {1,4,3,2,5}, which is the lexicographically smallest one.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<int,vector<int>,greater<int>>q;
    q.push(0);
    vector<bool>visited(n,false);
    visited[0]=true;
    while(!q.empty())
    {
        int x=q.top();
        q.pop();
        cout<<x+1<<" ";
        for(int i=0;i<adj[x].size();i++)
        {
            if(!visited[adj[x][i]])
            {
                visited[adj[x][i]]=true;
                q.push(adj[x][i]);
            }
        }
    }
    return 0;
}
