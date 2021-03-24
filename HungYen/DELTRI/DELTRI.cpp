//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "DELTRI"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, res= oo, ans;
ii a[mn];
bool c[5005][5005], chek[5005];
vector< int> v;

void BUFF()
{
    forr(i, 1, n- 1) c[i][i+ 1]= c[i+ 1][i]= 1;
    c[1][n]= c[n][1]= 1;
    m= n- 3;

    forr(x, 0, (1<< m)- 1)
    {
        v.clear();
        ans= 0;
        forr(i, 0, m- 1)
            if((x>> i)& 1){
                v.pb(i+ 1);
                c[a[i+ 1].x][a[i+ 1].y]= c[a[i+ 1].y][a[i+ 1].x]= 1;
                ++ans;
            }
        for(auto z: v){
            int U= a[z].x, V= a[z].y;
            forr(i, 1, n)
            {
                if(i== U|| i== V) continue;
                if(c[i][U]&& c[i][V]) goto over;
            }
        }

        res= min(res, n- 3- ans);

        over:;

        forr(i, 0, m- 1)
            if((x>> i)& 1)
                //v.pb(i+ 1);
                c[a[i+ 1].x][a[i+ 1].y]= c[a[i+ 1].y][a[i+ 1].x]= 0;
    }

    cout<< res;
}

int COUNT(int u)
{
    int cnt= 0;
    forr(i, 1, n)
    {
        if(i== a[u].x|| i== a[u].y) continue;
        if(c[i][a[u].x]== c[i][a[u].y]&& c[i][a[u].y]== 1) ++cnt;
    }
    return cnt;
}

void COW()
{
    forr(i, 1, n- 1) c[i][i+ 1]= c[i+ 1][i]= 1;
    c[1][n]= c[n][1]= 1;
    m= n- 3;
    sort(a+ 1, a+ m+ 1);

    forr(i, 1, m)
        c[a[i].x][a[i].y]= c[a[i].y][a[i].x]= 1;

    int cnt= n- 2;
    res= 0;

    while(cnt)
    {
        forr(i, 1, m)
        {
            if(chek[i]) continue;
            if(COUNT(i)== 2)
            {
                c[a[i].x][a[i].y]= c[a[i].y][a[i].x]= 0;
                cnt-= 2, ++res, chek[i]= 1;
                goto over;
            }
        }
            //if(ans== 0) break;
        forr(i, 1, m)
        {
            if(chek[i]) continue;
            if(COUNT(i)== 1)
            {
                c[a[i].x][a[i].y]= c[a[i].y][a[i].x]= 0;
                --cnt, ++res, chek[i]= 1;
                goto over;
            }
        }
        over:;
    }

    cout<< res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n- 3)
        cin>> a[i].x>> a[i].y;

    if(n<= 18) BUFF();
    else COW();
    //COW();

    return 0;
}
