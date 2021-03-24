#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define pb push_back
#define x first
#define y second
#define ii pair <int,int>

using namespace std;

ii a[5];
vector <ii> RES;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("1087C.inp", "r", stdin);

    forr(i,1,3) cin >> a[i].x >> a[i].y;


    sort(a+1,a+4);

    int LEN = max(a[1].y,a[3].y),
        XUONG = min(a[1].y,a[3].y);
    if (a[2].y > LEN)
    {
        if (a[1].y == XUONG)
        {
            while (a[1].y < LEN)
            {
                RES.pb(a[1]);
                ++a[1].y;
            }
            while (a[1].x < a[3].x)
            {
                RES.pb(a[1]);
                ++a[1].x;
            }
        }
        else
        {
            while (a[1].x < a[3].x)
            {
                RES.pb(a[1]);
                ++a[1].x;
            }
            while (a[1].y > XUONG)
            {
                RES.pb(a[1]);
                --a[1].y;
            }
        }
        while (a[2].y > LEN)
        {
            RES.pb(a[2]);
            --a[2].y;
        }
    }
    else if (a[2].y < XUONG)
    {
        if (a[1].y == XUONG)
        {
            while (a[1].x < a[3].x)
            {
                RES.pb(a[1]);
                ++a[1].x;
            }
            while (a[1].y < LEN)
            {
                RES.pb(a[1]);
                ++a[1].y;
            }
        }
        else
        {
            while (a[1].y > XUONG)
            {
                RES.pb(a[1]);
                --a[1].y;
            }
            while (a[1].x < a[3].x)
            {
                RES.pb(a[1]);
                ++a[1].x;
            }
        }
        while (a[2].y < XUONG)
        {
            RES.pb(a[2]);
            ++a[2].y;
        }
    }
    else
    {
        if (a[1].y == XUONG)
        {
            while (a[1].y < a[2].y)
            {
                RES.pb(a[1]);
                ++a[1].y;
            }
            while (a[1].x < a[2].x)
            {
                RES.pb(a[1]);
                ++a[1].x;
            }
            while (a[1].y < LEN)
            {
                RES.pb(a[1]);
                ++a[1].y;
            }
            while (a[1].x < a[3].x)
            {
                RES.pb(a[1]);
                ++a[1].x;
            }
        }
        else
        {
            while (a[1].y > a[2].y)
            {
                RES.pb(a[1]);
                --a[1].y;
            }
            while (a[1].x < a[2].x)
            {
                RES.pb(a[1]);
                ++a[1].x;
            }
            while (a[1].y > XUONG)
            {
                RES.pb(a[1]);
                --a[1].y;
            }
            while (a[1].x < a[3].x)
            {
                RES.pb(a[1]);
                ++a[1].x;
            }
        }

    }

    RES.pb(a[3]);

    cout << RES.size() << '\n';

    for (auto z : RES)
        cout << z.x << ' ' << z.y << '\n';
    return 0;
}
