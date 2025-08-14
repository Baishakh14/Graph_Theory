/*
Allaih is Almighty
Bismillahhi Rahmanir Rahim
Baishakh
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define ll long long
const int mod = 1e9+7;
// s.order_of_key(x) -> values total are small than x
// *s.find_by_order(x)  -> kth small elemnt (index) in pbds
vector<ll>dis(1e5+10,1e17);
void disj(int n,vector<pair<ll,ll>>g[])
{
    set<pair<ll,ll>>s;
    dis[1] = 0;
    s.insert({0,1});
    while(!s.empty())
    {
        auto it = *s.begin();
        s.erase(it);
        ll node = it.second;
        ll cost = it.first;
        if(dis[node] != cost) continue;
        for(auto it : g[node])
        {
            ll nnode = it.first;
            ll ccost = it.second;
            if(cost + ccost < dis[nnode])
            {
                dis[nnode] = cost + ccost;
                s.insert({cost + ccost,nnode});
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>g[n+1];
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    disj(n,g);
    for(int i = 1;i<=n;i++) cout<<dis[i]<<" ";
    cout<<endl;
  return 0;
}


//Tata Goodbye Khatam
