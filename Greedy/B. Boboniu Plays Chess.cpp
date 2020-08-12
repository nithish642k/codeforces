/*
Boboniu likes playing chess with his employees. As we know, no employee can beat the boss in the chess game,
so Boboniu has never lost in any round.

You are a new applicant for his company. Boboniu will test you with the following chess question:

Consider a n×m grid (rows are numbered from 1 to n, and columns are numbered from 1 to m). You have a chess piece,
 and it stands at some cell (Sx,Sy) which is not on the border (i.e. 2≤Sx≤n−1 and 2≤Sy≤m−1).

From the cell (x,y), you can move your chess piece to (x,y′) (1≤y′≤m,y′≠y) or (x′,y) (1≤x′≤n,x′≠x).
 In other words, the chess piece moves as a rook. From the cell, you can move to any cell on the same row or column.

Your goal is to visit each cell exactly once. Can you find a solution?

Note that cells on the path between two adjacent cells in your route are not counted as visited,
and it is not required to return to the starting point.

Input
The only line of the input contains four integers n, m, Sx and Sy (3≤n,m≤100, 2≤Sx≤n−1, 2≤Sy≤m−1) —
the number of rows, the number of columns, and the initial position of your chess piece, respectively.

Output
You should print nm lines.

The i-th line should contain two integers xi and yi (1≤xi≤n, 1≤yi≤m), denoting the i-th cell that you visited.
You should print exactly nm pairs (xi,yi), they should cover all possible pairs (xi,yi), such that 1≤xi≤n, 1≤yi≤m.

We can show that under these constraints there always exists a solution. If there are multiple answers, print any.

Examples

input:
3 3 2 2

output:
2 2
1 2
1 3
2 3
3 3
3 2
3 1
2 1
1 1

input:
3 4 2 2

output:
2 2
2 1
2 3
2 4
1 4
3 4
3 3
3 2
3 1
1 1
1 2
1 3
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x--;
    y--;
    cout<<x+1<<" "<<y+1<<endl;
    for(int j=0;j<y;j++)
    {
        cout<<x+1<<" "<<j+1<<endl;
    }
    for(int j=y+1;j<m;j++)
    {
        cout<<x+1<<" "<<j+1<<endl;
    }
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        if(i==x)
            continue;
        if(flag)
        {
           for(int j=0;j<m;j++)
               cout<<i+1<<" "<<j+1<<endl;
        }
        else
        {
            for(int j=m-1;j>=0;j--)
               cout<<i+1<<" "<<j+1<<endl;
        }
        flag=!flag;
    }
    return 0;
}
/*
Backtracking way:(TLE)
#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<bool>>&visited,int r,int c,int n,int m)
{
    if(r>=0&&r<n&&c>=0&&c<m&&!visited[r][c])
        return true;
    return false;
}
void generatePath(vector<vector<int>>&res,vector<vector<int>>curr,vector<vector<bool>>&visited,int x,int y,int n,int m,int vcount)
{
    if(vcount==n*m-1)
    {
        curr.push_back({x,y});
        res=curr;
        return;
    }
    if(isSafe(visited,x+1,y,n,m))
    {
         visited[x][y]=true;
         curr.push_back({x,y});
         generatePath(res,curr,visited,x+1,y,n,m,vcount+1);
        visited[x][y]=false;
        curr.pop_back();
    }
    if(isSafe(visited,x-1,y,n,m))
    {
         visited[x][y]=true;
         curr.push_back({x,y});
         generatePath(res,curr,visited,x-1,y,n,m,vcount+1);
        visited[x][y]=false;
        curr.pop_back();
    }
    if(isSafe(visited,x,y+1,n,m))
    {
        visited[x][y]=true;
        curr.push_back({x,y});
        generatePath(res,curr,visited,x,y+1,n,m,vcount+1);
        visited[x][y]=false;
        curr.pop_back();
    }
    if(isSafe(visited,x,y-1,n,m))
    {
        visited[x][y]=true;
        curr.push_back({x,y});
        generatePath(res,curr,visited,x,y-1,n,m,vcount+1);
        visited[x][y]=false;
        curr.pop_back();
    }
}
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x--;
    y--;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    vector<vector<int>>res;
    vector<vector<int>>curr;
    int vcount=0;
    generatePath(res,curr,visited,x,y,n,m,vcount);
    for(auto x:res)
    {
        for(auto y:x)
        {
            cout<<y+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/
