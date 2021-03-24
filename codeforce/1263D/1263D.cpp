//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1263D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, res= 0;
string a;

bool u[26][26], o[26], chek[26], d[26];

void dfs(int c)
{
    forr(i, 0, 25)
        if(u[c][i]&& !chek[i]){
            chek[i]= 1;
            dfs(i);
        }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;

    forr(j, 1, n)
    {
        cin>> a;

        memset(d, 0);
        for(int i= 0; i< a.size(); i++)
        {
            d[a[i]- 'a']= 1;
            o[a[i]- 'a']= 1;
        }
        forr(i, 0, 25)
            forr(k, 0, 25)
                if(d[i]&& d[k])
                     u[i][k]= u[k][i]= 1;

    }

    // EM YEU TRUONG EM

    forr(i, 0, 25)
    {
        if(o[i]&& !chek[i]){
            chek[i]= 1;
            dfs(i);
            ++ res;
        }
    }

    /*forr(j, 1, n)
    {
        for(int i= 0; i< a[j].size(); i++)
            if(ans[a[j][i]- 'a']== 1) ++ res;
    }*/

    cout<< res;

    return 0;
}
