/*
We know that prime numbers are positive integers that have exactly two distinct positive divisors.
Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.

Input
The first line contains a single positive integer, n (1≤n≤105), showing how many numbers are in the array.
The next line contains n space-separated integers x i (1≤x i≤1012).

Please, do not use the %lld specifier to read or write 64-bit integers in С++.
It is advised to use the cin, cout streams or the %I64d specifier.

Output
Print n lines: the i-th line should contain "YES" (without the quotes), if number x i is Т-prime, and "NO" (without the quotes), if it isn't.

Examples
input:
3
4 5 6
output:
YES
NO
NO

Note
The given test has three numbers. The first number 4 has exactly three divisors — 1, 2 and 4,
thus the answer for this number is "YES". The second number 5 has two divisors (1 and 5),
and the third number 6 has four divisors (1, 2, 3, 6), hence the answer for them is "NO".


intuition:
A prime number has 2 prime factors.
Squares of prime numbers have 3 prime factors.
A number is T-prime if it is a square of a prime number.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        long long x=sqrt(num);
        bool isPrime=true;
        for(int j=2;j*j<=x;j++)
        {
            if(num%j==0)
            {
                isPrime=false;
                break;
            }
        }
        if(isPrime&&x*x==num&&num!=1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
