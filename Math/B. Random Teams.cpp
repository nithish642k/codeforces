/*
n participants of the competition were split into m teams in some manner so that each team has at least one participant.
After the competition each pair of participants from the same team became friends.
Your task is to write a program that will find the minimum and the maximum number of pairs of friends
that could have formed by the end of the competition.

Input
The only line of input contains two integers n and m,
separated by a single space (1≤m≤n≤109) — the number of participants and the number of teams respectively.

Output
The only line of the output should contain two integers k min and k max — the minimum possible number of pairs of friends and the maximum possible number of pairs of friends respectively.

Examples
input:
5 1
output:
10 10

input:
3 2
output:
1 1

input:
6 3
output:
3 6
Note
In the first sample all the participants get into one team, so there will be exactly ten pairs of friends.

In the second sample at any possible arrangement one team will always have two participants and the other team will always have one participant.
Thus, the number of pairs of friends will always be equal to one.

In the third sample minimum number of newly formed friendships can be achieved if participants were split on teams consisting of 2 people,
maximum number can be achieved if participants were split on teams of 1, 1 and 4 people.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m; // n->#participants m->#teams
    cin>>n>>m;
    /*
      for mimimum #pairs,
      initially each team is equally distruibuted with n/m participants,
      and the rest of the n%m participants join the first n%m teams.

      So,the first n%m teams have n/m+1 participants,the rest of the (m-n%m)teams have n/m participants.
    */
    cout<<(m-n%m)*(n/m)*(n/m-1)/2 + (n%m)*(n/m+1)*(n/m+1-1)/2<<" ";

    /*
    for maximum pairs,
    the first m-1 teams, will have one participant(no pair),
    the last team will have the rest of the n-(m-1) participants
    */

    long long t=n-(m-1);
    cout<<t*(t-1)/2;
    return 0;
}
