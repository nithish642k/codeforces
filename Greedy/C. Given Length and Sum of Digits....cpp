/*
You have a positive integer m and a non-negative integer s.
Your task is to find the smallest and the largest of the numbers that have length m and sum of digits s.
The required numbers should be non-negative integers written in the decimal base without leading zeroes.

Input
The single line of the input contains a pair of integers m, s (1≤m≤100,0≤s≤900) — the length and the sum of the digits of the required numbers.

Output
In the output print the pair of the required non-negative integer numbers — first the minimum possible number,
then — the maximum possible number. If no numbers satisfying conditions required exist, print the pair of numbers "-1 -1" (without the quotes).

Examples
input:
2 15
output:
69 96

input:
3 0
output:
-1 -1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,s;
    cin>>m>>s;
    if(s==0)
    {
        if(m==1)
        {
            cout<<"0 0";
            return 0;
        }
        else
        {
            cout<<"-1 -1";
            return 0;
        }
    }
    string maxi;
    for(int i=0;i<m;i++)
    {
        int d=min(9,s);
        maxi+=d+'0';
        s-=d;
    }
    if(s>0)
    {
        cout<<"-1 -1";
        return 0;
    }
    string mini=maxi;
    reverse(mini.begin(),mini.end());
    int j=0;
    while(mini[j]=='0')  // for cases like s=15,m=3   maxi=960,mini=069,but leading 0s is not allowed,so mini=159(take 1 from leftmost nonzero digit)
        j++;
    mini[0]++;
    mini[j]--;
    cout<<mini<<" "<<maxi;
}
