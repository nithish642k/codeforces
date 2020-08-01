/*
As you could know there are no male planes nor female planes. However, each plane on Earth likes some other plane.
There are n planes on Earth, numbered from 1 to n, and the plane with number i likes the plane with number f i, where 1≤f i≤n and f i≠i.

We call a love triangle a situation in which plane A likes plane B, plane B likes plane C and plane C likes plane A.
Find out if there is any love triangle on Earth.

Input
The first line contains a single integer n (2≤n≤5000) — the number of planes.

The second line contains n integers f 1,f 2,...,f n (1≤f i≤n, f i≠i), meaning that the i-th plane likes the f i-th.

Output
Output «YES» if there is a love triangle consisting of planes on Earth. Otherwise, output «NO».

You can output any letter in lower case or in upper case.

Examples
input:
5
2 4 5 1 3
output:
YES

input:
5
5 5 5 5 1
output:
NO

Note
In first example plane 2 likes plane 4, plane 4 likes plane 1, plane 1 likes plane 2 and that is a love triangle.
In second example there are no love triangles.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>lover(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>lover[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(lover[lover[lover[i]]]==i)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
