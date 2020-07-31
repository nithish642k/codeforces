/*
A company has n employees numbered from 1 to n. Each employee either has no immediate manager or exactly one immediate manager,
who is another employee with a different number.
An employee A is said to be the superior of another employee B if at least one of the following is true:

Employee A is the immediate manager of employee B
Employee B has an immediate manager employee C such that employee A is the superior of employee C.
The company will not have a managerial cycle. That is, there will not exist an employee who is the superior of his/her own immediate manager.

Today the company is going to arrange a party.
This involves dividing all n employees into several groups: every employee must belong to exactly one group.
Furthermore, within any single group, there must not be two employees A and B such that A is the superior of B.

What is the minimum number of groups that must be formed?

Input
The first line contains integer n (1≤n≤2000) — the number of employees.

The next n lines contain the integers p i (1≤p i≤n or p i=-1). Every p i denotes the immediate manager for the i-th employee.
If p i is -1, that means that the i-th employee does not have an immediate manager.

It is guaranteed, that no employee will be the immediate manager of him/herself ( p i≠i). Also, there will be no managerial cycles.

Output
Print a single integer denoting the minimum number of groups that will be formed in the party.

Examples
input:
5
-1
1
2
1
-1
output:
3

Note
For the first example, three groups are sufficient, for example:

Employee 1
Employees 2 and 4
Employees 3 and 5

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    int b;
    queue<int>q;
    for(int a=0;a<n;a++)
    {
        cin>>b;
        if(b==-1)
            q.push(a);
        else
            adj[b-1].push_back(a);
    }
    int level=0;
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            int x=q.front();
            q.pop();
            for(int k=0;k<adj[x].size();k++)
            {
                q.push(adj[x][k]);
            }
        }
        level++;
    }
    cout<<level;
    return 0;
}
