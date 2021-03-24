//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1388D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], b[mn], c[mn], d[mn], p[mn], dif[mn], ans= 0, e[mn];
bool tick[mn], chek[mn];
stack < int> s, q;
vector< int> v;

void dfs(int u)
{
    chek[u]= 1;

    int i= e[u];
    if(!chek[i]) dfs(i);

    if(!tick[u]){
        ans+= a[u];
        v.pb(u);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n) cin>> a[i];
    forr(i, 1, n){
        cin>> b[i];
        if(b[i]!= -1){
            p[i]= b[i];
            ++d[b[i]];
            e[i]= b[i];
        }
    }

    forr(i, 1, n)
        if(!d[i])
            q.push(i), s.push(i);
    while(s.size()){
        int i= s.top();
        s.pop();
        if(a[i]> 0)
        {
            ans+= a[i];
            a[p[i]]+= a[i];
            v.pb(i);
            tick[i]= 1;
        }
        --d[p[i]];
        if(!d[p[i]]&& p[i])
        s.push(p[i]);
        p[i]= 0;
    }

    tick[0]= 1;
    forr(i, 1, n){

        if(!tick[i]){
            int u= i, m= 0, sum= 0, res= 0, val= 0;

            while(!tick[u]){
                tick[u]= 1, c[++m]= u;
                sum+= a[u];
                u= p[u];
            }

            if(m== 1){
                tick[i]= 0;
                continue;
            }
            forr(j, 1, m)
            {
                res+= a[c[j]]* (m- j+ 1);
                dif[j]= dif[j- 1]+ a[c[j]]* m- res;
                if(dif[val]<= dif[j]) val= j;
            }

            ans+= res+ dif[val];
            forr(j, 0, m- 1){
                int z= c[(j+ val)% m];
                if(!z) z= c[m];
                v.pb(z);
            }
        }
    }

    while(q.size())
    {
        int i= q.top();
        q.pop();
        dfs(i);
    }

    cout<< ans<< "\n";
    for(int u: v) cout<< u<< " ";

    return 0;
}
