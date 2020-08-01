/*
In Summer Informatics School, if a student doesn't behave well, teachers make a hole in his badge.
And today one of the teachers caught a group of n students doing yet another trick.

Let's assume that all these students are numbered from 1 to n. The teacher came to student a and put a hole in his badge.
The student, however, claimed that the main culprit is some other student pa.

After that, the teacher came to student pa and made a hole in his badge as well. The student in reply said that the main culprit was student ppa.

This process went on for a while, but, since the number of students was finite, eventually the teacher came to the student,
who already had a hole in his badge.

After that, the teacher put a second hole in the student's badge and decided that he is done with this process, and went to the sauna.

You don't know the first student who was caught by the teacher. However, you know all the numbers pi.
Your task is to find out for every student a, who would be the student with two holes in the badge if the first caught student was a.

Input
The first line of the input contains the only integer n (1≤n≤1000) — the number of the naughty students.
The second line contains n integers p1, ..., pn (1≤pi≤n), where pi indicates the student who was reported to the teacher by student i.

Output
For every student a from 1 to n print which student would receive two holes in the badge, if a was the first student caught by the teacher.

Examples
input:
3
2 3 2
output:
2 2 3

input:
3
1 2 3
output:
1 2 3
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>next(n+1);
    int s;
    for(int i=1;i<=n;i++)
    {
        cin>>next[i];
    }
    for(int i=1;i<=n;i++)
    {
        int u=i;
        vector<bool>visited(n,false);
        while(!visited[u])
        {
            visited[u]=true;
            u=next[u];
        }
        cout<<u<<" ";
    }
    return 0;
}
