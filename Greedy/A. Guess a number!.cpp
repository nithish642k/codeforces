/*
A TV show called "Guess a number!" is gathering popularity. The whole Berland, the old and the young, are watching the show.

The rules are simple. The host thinks of an integer y and the participants guess it by asking questions to the host.
 There are four types of acceptable questions:

Is it true that y is strictly larger than number x?
Is it true that y is strictly smaller than number x?
Is it true that y is larger than or equal to number x?
Is it true that y is smaller than or equal to number x?
On each question the host answers truthfully, "yes" or "no".

Given the sequence of questions and answers, find any integer value of y that meets the criteria of all answers.
 If there isn't such value, print "Impossible".

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 10000) —
 the number of questions (and answers). Next n lines each contain one question and one answer to it.
 The format of each line is like that: "sign x answer", where the sign is:

">" (for the first type queries),
"<" (for the second type queries),
">=" (for the third type queries),
"<=" (for the fourth type queries).
All values of x are integer and meet the inequation  - 109 ≤ x ≤ 109.
 The answer is an English letter "Y" (for "yes") or "N" (for "no").

Consequtive elements in lines are separated by a single space.

Output
Print any of such integers y, that the answers to all the queries are correct.
The printed number y must meet the inequation  - 2·109 ≤ y ≤ 2·109.
 If there are many answers, print any of them. If such value doesn't exist, print word "Impossible" (without the quotes).

Examples
input:
4
>= 1 Y
< 3 N
<= -3 N
> 55 N
output:
17

input:
2
> 100 Y
< -100 Y
output:
Impossible
*/
#include<bits/stdc++.h>
using namespace std;
void reduceRange(int &Min,int &Max,string &cond,int &val)
{
    if(cond=="<")
    {
        if(Max>val-1)
        Max=val-1;
    }
    else if(cond=="<=")
    {
        if(Max>val)
        Max=val;
    }
    else if(cond==">")
    {
        if(Min<val+1)
        Min=val+1;
    }
    else if(cond==">=")
    {
        if(Min<val)
        Min=val;
    }
}
int main()
{
    int n;
    cin>>n;
    string cond;
    int val;
    char truth;
    int Min=-2000000000;
    int Max= 2000000000;
    for(int i=0;i<n;i++)
    {
        cin>>cond>>val>>truth;
        if(truth=='N')
        {
            if(cond=="<") cond=">=";
            else if(cond=="<=") cond=">";
            else if(cond==">") cond="<=";
            else if(cond==">=") cond="<";
        }
        reduceRange(Min,Max,cond,val);
    }
    if(Min>Max)
        cout<<"Impossible";
    else
        cout<<Min;
}
