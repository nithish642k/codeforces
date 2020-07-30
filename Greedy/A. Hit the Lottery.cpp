/*
Allen has a LOT of money. He has n dollars in the bank.
 For security reasons, he wants to withdraw it in cash (we will not disclose the reasons here).
 The denominations for dollar bills are 1, 5, 10, 20, 100. What is the minimum number of bills Allen could receive
 after withdrawing his entire balance?

Input
The first and only line of input contains a single integer n (1≤n≤109).

Output
Output the minimum number of bills that Allen could receive.

Examples
input:
125
output:
3

input:
43
output:
5
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=0;
    int c1=n/100;
    n=n%100;
    int c2=n/20;
    n=n%20;
    int c3=n/10;
    n=n%10;
    int c4=n/5;
    n=n%5;
    count=c1+c2+c3+c4+n;
    cout<<count;
}
