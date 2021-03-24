//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "KCOLLECT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, d[100005], num[105][105], low[105][105], dad[105][105], F[100005], C[100005], cnt= 0, COUNT= 0;
vector< int> k[100005], c[105][105];

int dx[4]= {0, 1, 0, -1};
int dy[4]= {1, 0, -1, 0};

bool chek[100005];
char a[105][105];
stack< ii> S;

void dfs(int u, int v)
{

    num[u][v]= low[u][v]= ++cnt;
    S.push(ii(u, v));

    for(auto z: c[u][v])
    {
        int _u= u+ dx[z], _v= v+ dy[z];
        if(0>= _u|| _u> m|| 0>= _v|| _v> n|| a[_u][_v]== '#') continue;
        if(num[_u][_v])
            low[u][v]= min(low[u][v], num[_u][_v]);
        else{
            dfs(_u, _v);
            low[u][v]= min(low[u][v], low[_u][_v]);
        }
    }

    if(num[u][v]== low[u][v])
    {
        int _u, _v;
        ++COUNT;
        while(_u!= u|| _v!= v)
        {
            _u= S.top().x, _v= S.top().y;
            S.pop();
            if('0'<= a[_u][_v]&& a[_u][_v]<= '9') F[COUNT]+= (a[_u][_v]- '0');
            dad[_u][_v]= COUNT;
            num[_u][_v]= low[_u][_v]= oo;
        }
    }

}


void visit(int u)
{
    chek[u]= 1;
    for(auto v: k[u])
        if(!chek[v]) visit(v);
    d[cnt--]= u;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> m>> n;
    forr(i, 1, m)
        forr(j, 1, n)
        {
            cin>> a[i][j];
            if('0'<= a[i][j]&& a[i][j]<= '9') c[i][j].pb(0), c[i][j].pb(1);
            if(a[i][j]== 'W') c[i][j].pb(2);
            if(a[i][j]== 'N') c[i][j].pb(3);
        }

    if(a[1][1]== '#'){
        cout<< 0;
        return 0;
    }

    forr(i, 1, m)
    forr(j, 1, n)
    if(!num[i][j]&& a[i][j]!= '#') dfs(i, j);

    forr(i, 1, m)
    forr(j, 1, n)
    {
        if(a[i][j]== '#') continue;
        for(auto z: c[i][j])
        {
            int u= i+ dx[z], v= j+ dy[z];
            if(u<= 0|| u> m|| v<= 0|| v> n|| a[u][v]== '#') continue;
            if(dad[i][j]!= dad[u][v]) k[dad[i][j]].pb(dad[u][v]);
        }
    }

    cnt= COUNT;
    forr(i, 1, COUNT)
    if(!chek[i]) visit(i);

    //forr(i, 1, COUNT) C[i]= F[i];

    memset(C, -60);
    C[dad[1][1]]= F[dad[1][1]];

    forr(u, 1, COUNT)
        for(auto v: k[d[u]])
            C[v]= max(C[v], C[d[u]]+ F[v]);


    cout<< *max_element(C+ 1, C+ COUNT+ 1);


    return 0;
}
