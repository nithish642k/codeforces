/*
Gildong owns a bulgogi restaurant. The restaurant has a lot of customers, so many of them like to make a reservation before visiting it.
Gildong tries so hard to satisfy the customers that he even memorized all customers' preferred temperature ranges!
 Looking through the reservation list, he wants to satisfy all customers by controlling the temperature of the restaurant.

The restaurant has an air conditioner that has 3 states: off, heating, and cooling. When it's off, the restaurant's temperature remains the same.
When it's heating, the temperature increases by 1 in one minute. Lastly, when it's cooling, the temperature decreases by 1 in one minute.
Gildong can change the state as many times as he wants, at any integer minutes. The air conditioner is off initially.

Each customer is characterized by three values: ti — the time (in minutes) when the i-th customer visits the restaurant,
 li — the lower bound of their preferred temperature range, and hi — the upper bound of their preferred temperature range.

A customer is satisfied if the temperature is within the preferred range at the instant they visit the restaurant.
Formally, the i-th customer is satisfied if and only if the temperature is between li and hi (inclusive) in the ti-th minute.

Given the initial temperature, the list of reserved customers' visit times and their preferred temperature ranges,
 you're going to help him find if it's possible to satisfy all customers.

Input
Each test contains one or more test cases. The first line contains the number of test cases q (1≤q≤500). Description of the test cases follows.
The first line of each test case contains two integers n and m (1≤n≤100, −109≤m≤109),
where n is the number of reserved customers and m is the initial temperature of the restaurant.
Next, n lines follow. The i-th line of them contains three integers ti, li, and hi (1≤ti≤109, −109≤li≤hi≤109),
where ti is the time when the i-th customer visits, li is the lower bound of their preferred temperature range,
and hi is the upper bound of their preferred temperature range. The preferred temperature ranges are inclusive.

The customers are given in non-decreasing order of their visit time, and the current time is 0.

Output
For each test case, print "YES" if it is possible to satisfy all customers. Otherwise, print "NO".

You can print each letter in any case (upper or lower).

Example

input:
4
3 0
5 1 2
7 3 5
10 -1 0
2 12
5 7 10
10 16 20
3 -100
100 0 0
100 -50 50
200 100 100
1 100
99 -100 0

output:
YES
NO
YES
NO

Note
In the first case, Gildong can control the air conditioner to satisfy all customers in the following way:

At 0-th minute, change the state to heating (the temperature is 0).
At 2-nd minute, change the state to off (the temperature is 2).
At 5-th minute, change the state to heating (the temperature is 2, the 1-st customer is satisfied).
At 6-th minute, change the state to off (the temperature is 3).
At 7-th minute, change the state to cooling (the temperature is 3, the 2-nd customer is satisfied).
At 10-th minute, the temperature will be 0, which satisfies the last customer.
In the third case, Gildong can change the state to heating at 0-th minute and leave it be.
Then all customers will be satisfied. Note that the 1-st customer's visit time equals the 2-nd customer's visit time.

In the second and the fourth case, Gildong has to make at least one customer unsatisfied.

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll prev_t=0;
        ll t,l,h,ub,lb;
        lb=ub=m;
        bool ok=true;
        for(ll i=0;i<n;i++)
        {
            cin>>t>>l>>h;
            ll d=t-prev_t;
            lb=max(lb-d,l);
            ub=min(ub+d,h);
            if(lb>ub)
                ok=false;
            prev_t=t;
        }
        cout<<(ok?"YES":"NO");
        cout<<endl;
    }
    return 0;
}
