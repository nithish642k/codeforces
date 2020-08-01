/*
You are given a weighted undirected graph. The vertices are enumerated from 1 to n.
Your task is to find the shortest path between the vertex 1 and the vertex n.

Input
The first line contains two integers n and m (2≤n≤105,0≤m≤105),
where n is the number of vertices and m is the number of edges.
Following m lines contain one edge each in form a i, b i and w i (1≤a i,b i≤n,1≤w i≤106),
where a i,b i are edge endpoints and w i is the length of the edge.

It is possible that the graph has loops and multiple edges between pair of vertices.

Output
Write the only integer -1 in case of no path. Write the shortest path in opposite case. If there are many solutions, print any of them.

Examples
input:
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
output:
1 4 3 5

input:
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
output:
1 4 3 5

*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void printPath(vector<ll>&parent,int index)
{
    if(index<0)
        return;
    printPath(parent,parent[index]);
    cout<<index+1<<" ";
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n);
    ll a,b,cost;
    ll src=0;
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b>>cost; a--; b--;
        adj[a].push_back({b,cost});
        adj[b].push_back({a,cost});
    }
    vector<ll>parent(n,-1);
    vector<ll>dist(n,1e18);
    dist[src]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        ll u=pq.top().second;
        pq.pop();
        for(ll i=0;i<adj[u].size();i++)
        {
            ll v=adj[u][i].first;
            ll uv_cost=adj[u][i].second;
            if(dist[u]+uv_cost<dist[v])
            {
                parent[v]=u;
                dist[v]=dist[u]+uv_cost;
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[n-1]==1e18)
    {
        cout<<"-1";
    }
    else
    {
        printPath(parent,n-1);
    }
    return 0;
}
