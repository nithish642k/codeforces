/*
There are n people who want to participate in a boat competition.
The weight of the i-th participant is wi. Only teams consisting of two people can participate in this competition.
As an organizer, you think that it's fair to allow only teams with the same total weight.

So, if there are k teams (a1,b1), (a2,b2), …, (ak,bk),
where ai is the weight of the first participant of the i-th team and bi is the weight of the second participant of the i-th team,
then the condition a1+b1=a2+b2=...=ak+bk=s, where s is the total weight of each team, should be satisfied.

Your task is to choose such s that the number of teams people can create is the maximum possible.
 Note that each participant can be in no more than one team.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1≤n≤50) — the number of participants.
 The second line of the test case contains n integers w1,w2,…,wn (1≤wi≤n), where wi is the weight of the i-th participant.

Output
For each test case, print one integer k:
the maximum number of teams people can compose with the total weight s, if you choose s optimally.

Example
inputCopy
5
5
1 2 3 4 5
8
6 6 6 6 6 6 8 8
8
1 2 2 1 2 1 1 2
3
1 3 3
6
1 1 3 4 2 2
outputCopy
2
3
4
1
2
Note
In the first test case of the example, we can reach the optimal answer for s=6.
Then the first boat is used by participants 1 and 5 and the second boat is used by participants 2 and 4 (indices are the same as weights).

In the second test case of the example, we can reach the optimal answer for s=12.
Then first 6 participants can form 3 pairs.

In the third test case of the example, we can reach the optimal answer for s=3.
The answer is 4 because we have 4 participants with weight 1 and 4 participants with weight 2.

In the fourth test case of the example, we can reach the optimal answer for s=4 or s=6.

In the fifth test case of the example, we can reach the optimal answer for s=3.
Note that participant with weight 3 can't use the boat because there is no suitable pair for him in the list.
*/
#include<bits/stdc++.h>
using namespace std;
int find(vector<int>&nums,int &target)
{
    int count=0;
    int low=0;
    int high=nums.size()-1;
    while(low<high)
    {
        int curr_sum=nums[low]+nums[high];
        if(curr_sum==target)
        {
            count++;
            low++;
            high--;
        }
        else if(curr_sum>target)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=2;i<=100;i++)
        {
            res=max(res,find(nums,i));
        }
        cout<<res<<endl;
    }
    return 0;
}
/*
Without sorting:(slower)
#include<bits/stdc++.h>
using namespace std;
int find(vector<int>&nums,int &target)
{
    int count=0;
    vector<bool>used(nums.size(),false);
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(used[i]||used[j])
                continue;
            if(nums[i]+nums[j]==target)
            {
                count++;
                used[i]=used[j]=true;
            }
        }
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=2;i<=100;i++)
        {
            res=max(res,find(nums,i));
        }
        cout<<res<<endl;
    }
    return 0;
}
*/
