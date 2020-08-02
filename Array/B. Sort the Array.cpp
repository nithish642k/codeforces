/*
Being a programmer, you like arrays a lot. For your birthday, your friends have given you an array a consisting of n distinct integers.

Unfortunately, the size of a is too small. You want a bigger array!
Your friends agree to give you a bigger array,
but only if you are able to answer the following question correctly:
is it possible to sort the array a (in increasing order) by reversing exactly one segment of a?
See definitions of segment and reversing in the notes.

Input
The first line of the input contains an integer n (1≤n≤105) — the size of array a.

The second line contains n distinct space-separated integers: a[1],a[2],...,a[n] (1≤a[i]≤109).

Output
Print "yes" or "no" (without quotes), depending on the answer.

If your answer is "yes", then also print two space-separated integers denoting start and end
(start must not be greater than end) indices of the segment to be reversed.
If there are multiple ways of selecting these indices, print any of them.

Examples

input:
3
3 2 1
output:
yes
1 3

input:
4
2 1 3 4
output:
yes
1 2

input:
4
3 1 2 4
output:
no

input:
2
1 2
output:
yes
1 1
*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n;
    cin>>n;
    vector<ll>nums(n);
    for(ll i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<ll>sorted(nums.begin(),nums.end());
    sort(sorted.begin(),sorted.end());
    ll start=-1,end=-1;
    for(ll i=0;i<nums.size();i++)
    {
        if(nums[i]!=sorted[i])
        {
            start=i;
            break;
        }
    }
    for(ll i=n-1;i>=0;i--)
    {
        if(nums[i]!=sorted[i])
        {
            end=i;
            break;
        }
    }
    if(start==-1)
    {
        cout<<"yes"<<endl;
        cout<<"1 1";
        return 0;
    }
    ll prev=INT_MIN;
    for(ll i=0;i<start-1;i++)
    {
        if(nums[i]>=prev)
        {
            prev=nums[i];
        }
        else
        {
            cout<<"no";
            return 0;
        }
    }
    for(ll i=end;i>=start;i--)
    {
        if(nums[i]>=prev)
        {
            prev=nums[i];
        }
        else
        {
            cout<<"no";
            return 0;
        }
    }
    for(ll i=end+1;i<n;i++)
    {
        if(nums[i]>=prev)
        {
            prev=nums[i];
        }
        else
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes"<<endl;
    cout<<start+1<<" "<<end+1;
    return 0;
}
