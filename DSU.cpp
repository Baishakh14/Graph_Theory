const int mx = 1e5+10;
vector<int>siz(mx,1);
vector<int>par(mx);
int com = -1;
void make(int i)
{
    par[i] = i;
}

int find(int x)
{
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void dsu(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a != b)
    {
        if(siz[b] > siz[a]) swap(a,b);
        par[b] = a;
        com--;
        siz[a] += siz[b];
    }
}
