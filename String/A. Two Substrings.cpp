/*
You are given string s. Your task is to determine if the given string s contains two non-overlapping substrings "AB" and "BA"
(the substrings can go in any order).

Input
The only line of input contains a string s of length between 1 and 105 consisting of uppercase Latin letters.

Output
Print "YES" (without the quotes), if string s contains two non-overlapping substrings "AB" and "BA", and "NO" otherwise.

Examples

input:
ABA
output:
NO

input:
BACFAB
output:
YES

input:
AXBYBXA
output:
NO

Note
In the first sample test, despite the fact that there are substrings "AB" and "BA", their occurrences overlap, so the answer is "NO".
In the second sample test there are the following occurrences of the substrings: BACFAB.
In the third sample test there is no substring "AB" nor substring "BA".
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int pos=s.find("AB");
    if(pos!=string::npos)
    {
        if(s.find("BA",pos+2)!=string::npos)
        {
            cout<<"YES";
            return 0;
        }
    }
    pos=s.find("BA");
    if(pos!=string::npos)
    {
        if(s.find("AB",pos+2)!=string::npos)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
