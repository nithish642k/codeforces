/*
"QAQ" is a word to denote an expression of crying. Imagine "Q" as eyes with tears and "A" as a mouth.

Now Diamond has given Bort a string consisting of only uppercase English letters of length n.
There is a great number of "QAQ" in the string (Diamond is so cute!).
Bort wants to know how many subsequences "QAQ" are in the string Diamond has given.
 Note that the letters "QAQ" don't have to be consecutive, but the order of letters should be exact.

Input
The only line contains a string of length n (1?=?n?=?100).
It's guaranteed that the string only contains uppercase English letters.

Output
Print a single integer — the number of subsequences "QAQ" in the string.

Examples
input:
QAQAQYSYIOIWIN
output:
4

input:
QAQQQZZYNOIWIN
output:
3
Note
In the first example there are 4 subsequences "QAQ":
 " QAQAQYSYIOIWIN", " QAQAQYSYIOIWIN", " QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN".

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int q=0,qa=0,qaq=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='Q')
        {
            q++;
            qaq+=qa;
        }
        else if(s[i]=='A')
        {
            qa+=q;
        }
    }
    cout<<qaq;
    return 0;
}
