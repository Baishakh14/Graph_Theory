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
int n,m;
const int mx = 1e3+10;
bool isv(int xx,int yy)
{
    if(xx >= 0 && xx < n && yy >= 0 && yy < m) return true;
    else return false;
}
int main()
{
    cin>>n>>m;
    vector<vector<char>>g(n,vector<char>(m));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++) cin>>g[i][j];
    }
    vector<pair<int,int>>move = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<char>movec = {'R','L','D','U'};
    pair<int,int>start,end;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(g[i][j] == 'A') start.first = i,start.second = j;
            if(g[i][j] == 'B') end.first = i,end.second = j;
        }
    }
    queue<pair<int,int>>q;
    vector<vector<pair<int,int>>>par(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<char>>path(n,vector<char>(m));
    bool vis[mx][mx];
    memset(vis,false,sizeof(vis));
    vis[start.first][start.second] = true;
    q.push({start.first,start.second});
    while(!q.empty())
    {
        auto val = q.front();
        if(val == end) break;
        q.pop();
        for(int i = 0;i<4;i++)
        {
            int xx = val.first + move[i].first;
            int yy = val.second + move[i].second;
            if(isv(xx,yy))
            {
                if(g[xx][yy] == '#')
                {
                    vis[xx][yy] = true;
                    continue;
                 }
                 if(!vis[xx][yy])
                 {
                    q.push({xx,yy});
                    par[xx][yy] = {val.first,val.second};
                    vis[xx][yy] = true;
                    path[xx][yy] = movec[i];
                 }
            }
        }
    }
    if(!vis[end.first][end.second])
    {
        cout<<"NO"<<endl;
    }
    else
    {
        vector<char>ans;
        pair<int,int> cur = end;
        while(cur != start)
        {
            char x = path[cur.first][cur.second];
            ans.push_back(x);
            cur = par[cur.first][cur.second];
        }
        reverse(ans.begin(),ans.end());
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(auto it : ans) cout<<it;
        cout<<endl;
    }
  return 0;
}


//Tata Goodbye Khatam
