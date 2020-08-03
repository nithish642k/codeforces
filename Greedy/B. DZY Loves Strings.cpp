/*
DZY loves collecting special strings which only contain lowercase letters. For each lowercase letter c DZY knows its value w c.
For each special string s=s 1 s 2... s |s| (|s| is the length of the string) he represents its value with a function f(s)
,where f(s)=summation 1 to |s|(wsi.i).

Now DZY has a string s. He wants to insert k lowercase letters into this string in order to get the largest possible value of the resulting string.
Can you help him calculate the largest possible value he could get?

Input
The first line contains a single string s (1≤|s|≤103).
The second line contains a single integer k (0≤k≤103).
The third line contains twenty-six integers from w a to w z.
 Each such number is non-negative and doesn't exceed 1000.

Output
Print a single integer — the largest possible value of the resulting string DZY could get.

Examples
inputCopy
abc
3
1 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
outputCopy
41
Note
In the test sample DZY can obtain "abcbbc", value=1·1+2·2+3·2+4·2+5·2+6·2=41.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<int>wt(26);
    int max_wt=INT_MIN;
    for(int i=0;i<26;i++)
    {
        cin>>wt[i];
        max_wt=max(max_wt,wt[i]);
    }
    int res=0;
    int pos=1;
    for(int i=0;i<s.size();i++)
    {
        res+=pos++*wt[s[i]-'a'];
    }
    int n=s.size();
    res+=((n+k)*(n+k+1)/2-n*(n+1)/2)*max_wt;
    cout<<res;
    return 0;
}
