//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1505
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "LABUDOVI"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int m, n, a[mn][mn], res= 0, r[mn* mn], d[mn][mn], c[2];
int dx[4]= {0, 1, 0, -1};
int dy[4]= {1, 0, -1, 0};
queue< ii> q;
string s;

bool chek(int u, int v)
{
    if(a[u][v]== 1) return false;
    forr(i, 0, 3)
    {
        int _u= u+ dx[i], _v= v+ dy[i];
        if(a[_u][_v]== 1) return true;
    }
    return false;
}

int fs(int u)
{
    return !r[u] ? u: r[u]= fs(r[u]);
}

void init()
{
    cin>> m>> n;
    forr(i, 1, m)
    {
        cin>> s;
        for(int j= 0; j< s.length(); j++)
        {
            if(s[j]== 'L')
            {
                c[res++]= i* n+ j+ 1;
                a[i][j+ 1]= 2;
            }
            if(s[j]== 'X') a[i][j+ 1]= 1;
            if(s[j]== '.') a[i][j+ 1]= 0;
            //else a[i][j+ 1]= 0;
        }
    }
}

void prep()
{
    forr(i, 1, m)
        forr(j, 1, n)
            forr(k, 0, 3)
    {
        int u= i+ dx[k], v= j+ dy[k];
        if(a[i][j]!= 1&& a[u][v]!= 1){
            int A= (i- 1)* n+ j, B= (u- 1)* n+ v;
            int fA= fs(A), fB= fs(B);
            if(fA!= fB) r[fA]= fB;
        }
    }
}

void bfs()
{
    forr(i, 1, m)
        forr(j, 1, n)
            if(chek(i, j))
                q.push(ii(i, j));

    res= 0;
    while(fs(c[0])!= fs(c[1])){
         ++res;
         while(1){
            int u= q.front().x, v= q.front().y;
            if(d[u][v]== res) break;
            q.pop();
            forr(i, 0, 3)
            {
                int _u= u+ dx[i], _v= v+ dy[i];
                if(!a[_u][_v]|| a[_u][_v]== 2) continue;
                a[_u][_v]= 0;
                //if(!chek(_u, _v)) continue;
                q.push(ii(_u, _v));
                d[_u][_v]= res;
            }
         }

         int ans= q.size();
         while(ans--){
            int u= q.front().x, v= q.front().y;
            q.pop();
            forr(i, 0, 3)
            {
                int _u= u+ dx[i], _v= v+ dy[i];
                int A= u* n+ v, B= _u* n+ _v;
                int fA= fs(A), fB= fs(B);
                if(fA!= fB) r[fA]= fB;
            }
            q.push(ii(u, v));
         }

    }

    cout<< res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    init();

    prep();

    bfs();

    return 0;
}
