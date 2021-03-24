//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "hihi"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, c[mn], res= 0, s, t;
vector< int> a[mn], ans;
bool type= 0;

void reSet()
{
    forr(i, 1, n) c[i]= i;
    c[s]= 0;
}

void dfs(int u)
{
    //c[u]= 1;
    for(int v: a[u])
        if(c[v]== v){
            c[v]= u;
            dfs(v);
        }
}

void bfs()
{
    queue< int> q;
    q.push(s);
    while(q.size())
    {
        int u= q.front();
        q.pop();
        for(int v: a[u]){
            if(c[v]== v){
                c[v]= u;
                q.push(v);
            }
            if(v== t) goto END;
        }
    }
    END:;
}

void print()
{
    ans.clear();
    int v= t;
    while(1){
        ans.pb(v);
        if(v== s) break;
        v= c[v];
    }

    cout<< "\n"<< ans.size();
    if(type){
        cout<< "\n";
        reverse(ans.begin(), ans.end());
        for(int u: ans) cout<< u<< " ";
    }

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    forr(i, 1, m){
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    forr(i, 1, n) sort(a[i].begin(), a[i].end());

    cin>> s>> t;

    reSet();
    forr(i, 1, n)
        if(c[i]== i)
            c[i]= 0, dfs(i), ++res;

    cout<< res;

    reSet();
    bfs(), print();

    reSet();
    type= 1;
    dfs(s), print();

    return 0;
}
