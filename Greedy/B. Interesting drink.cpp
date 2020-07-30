/*
Vasiliy likes to rest after a hard work, so you may often meet him in some bar nearby.
As all programmers do, he loves the famous drink "Beecola", which can be bought in n different shops in the city.
It's known that the price of one bottle in the shop i is equal to x i coins.

Vasiliy plans to buy his favorite drink for q consecutive days. He knows, that on the i-th day he will be able to spent m i coins.
Now, for each of the days he want to know in how many different shops he can buy a bottle of "Beecola".

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 100 000) — the number of shops in the city that sell Vasiliy's favourite drink.
The second line contains n integers x i (1 ≤ x i ≤ 100 000) — prices of the bottles of the drink in the i-th shop.
The third line contains a single integer q (1 ≤ q ≤ 100 000) — the number of days Vasiliy plans to buy the drink.
Then follow q lines each containing one integer m i (1 ≤ m i ≤ 109) — the number of coins Vasiliy can spent on the i-th day.

Output
Print q integers. The i-th of them should be equal to the number of shops where Vasiliy will be able to buy a bottle of the drink on the i-th day.

Example
input:
5
3 10 8 6 11
4
1
10
3
11
output:
0
4
1
5

Note:
On the first day, Vasiliy won't be able to buy a drink in any of the shops.
On the second day, Vasiliy can buy a drink in the shops 1, 2, 3 and 4.
On the third day, Vasiliy can buy a drink only in the shop number 1.
Finally, on the last day Vasiliy can buy a drink in any shop.
*/
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&prices,int &target)
{
    int low=0;
    int high=prices.size();
    while(low<high)
    {
        int mid=low+(high-low)/2;
        if(prices[mid]<=target)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    return low;
}
int main()
{
    int num_shops;
    cin>>num_shops;
    vector<int>prices(num_shops);
    for(int i=0;i<num_shops;i++)
    {
        cin>>prices[i];
    }
    sort(prices.begin(),prices.end());
    long long days;
    cin>>days;
    int target;
    for(long long i=0;i<days;i++)
    {
        cin>>target;
        cout<<binarySearch(prices,target)<<endl;
    }
}
/*
dp approach without sorting:
(not feasible for large #input queries)

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long num_shops;
    cin>>num_shops;
    vector<long long>prices(num_shops);
    unordered_map<long long,long long>count;
    for(long long i=0;i<num_shops;i++)
    {
        cin>>prices[i];
        count[prices[i]]++;
    }
    vector<unsigned long long>dp(100001);
    dp[0]=count[0];
    for(long long i=1;i<100001;i++)
    {
        dp[i]=dp[i-1]+count[i];
    }
    long long days;
    cin>>days;
    vector<long long>money(days);
    for(long long i=0;i<days;i++)
    {
        cin>>money[i];
        cout<<dp[money[i]]<<endl;
    }
}
*/
