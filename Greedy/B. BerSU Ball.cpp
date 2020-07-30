/*
The Berland State University is hosting a ballroom dance in celebration of its 100500-th anniversary!
 n boys and m girls are already busy rehearsing waltz, minuet, polonaise and quadrille moves.

We know that several boy&girl pairs are going to be invited to the ball. However, the partners' dancing skill in each pair must differ by at most one.

For each boy, we know his dancing skills.
Similarly, for each girl we know her dancing skills.
Write a code that can determine the largest possible number of pairs that can be formed from n boys and m girls.

Input
The first line contains an integer n (1≤n≤100) — the number of boys.
The second line contains sequence a1,a2,...,an (1≤a i≤100), where a i is the i-th boy's dancing skill.

Similarly, the third line contains an integer m (1≤m≤100) — the number of girls.
The fourth line contains sequence b1,b2,...,bm (1≤b j≤100),
where b j is the j-th girl's dancing skill.

Output
Print a single number — the required maximum possible number of pairs.

Examples
input:
4
1 4 6 2
5
5 1 5 7 9
output:
3

input:
4
1 2 3 4
4
10 11 12 13
output:
0

input:
5
1 1 1 1 1
3
1 2 3
output:
2
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nb;
    cin>>nb;
    vector<int>boys(nb);
    for(int i=0;i<nb;i++)
    {
        cin>>boys[i];
    }
    int ng;
    cin>>ng;
    vector<int>girls(ng);
    for(int i=0;i<ng;i++)
    {
        cin>>girls[i];
    }
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    int k=0;
    int pairs=0;
    for(int i=0;i<nb;i++)
    {
        for(int j=k;j<ng;j++)
        {
            if(abs(boys[i]-girls[j])<=1)
            {
                pairs++;
                k=j+1;
                break;
            }
        }
    }
    cout<<pairs;
}
