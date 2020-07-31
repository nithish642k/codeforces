/*
Kefa decided to celebrate his first big salary by going to the restaurant.
He lives by an unusual park. The park is a rooted tree consisting of n vertices with the root at vertex 1.
Vertex 1 also contains Kefa's house. Unfortunaely for our hero, the park also contains cats.
Kefa has already found out what are the vertices with cats in them.

The leaf vertices of the park contain restaurants. Kefa wants to choose a restaurant where he will go,
but unfortunately he is very afraid of cats,
so there is no way he will go to the restaurant if the path from the restaurant to his house contains more than m consecutive vertices with cats.

Your task is to help Kefa count the number of restaurants where he can go.

Input
The first line contains two integers, n and m (2≤n≤105, 1≤m≤n) — the number of vertices of the tree
and the maximum number of consecutive vertices with cats that is still ok for Kefa.

The second line contains n integers a 1,a 2,..., a n, where each a i either equals to 0 (then vertex i has no cat),
or equals to 1 (then vertex i has a cat).

Next n-1 lines contains the edges of the tree in the format " x i y i" (without the quotes) (1≤x i,y i≤n, x i≠y i),
where x i and y i are the vertices of the tree, connected by an edge.
It is guaranteed that the given set of edges specifies a tree.

Output
A single integer — the number of distinct leaves of a tree the path to which from Kefa's home contains at most m consecutive vertices with cats.

Examples
input:
4 1
1 1 0 0
1 2
1 3
1 4
output:
2

input:
7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
output:
2
*/
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj,vector<bool>&visited,int x,vector<int>&hasCat,int num_cats,int k,int &res)
{
    visited[x]=true;
    if(hasCat[x])
        num_cats++;
    else
        num_cats=0;
    if(num_cats<=k)
    {
        if(adj[x].size()==1&&x!=0)
            res++;
    }
    else
        return;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        {
            dfs(adj,visited,adj[x][i],hasCat,num_cats,k,res);
        }
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>hasCat(n);
    for(int i=0;i<n;i++)
    {
        cin>>hasCat[i];
    }
    vector<vector<int>>adj(n);
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int res=0;
    vector<bool>visited(n,false);
    dfs(adj,visited,0,hasCat,0,k,res);
    cout<<res;
    return 0;
}
