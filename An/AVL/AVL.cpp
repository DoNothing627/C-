//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "AVL"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n;
ii a[mn];

struct node
{
    int val, height;
    node *left, *right;
    void turnLeft(node *c)
    {

    }
    void turnRight(node *c)
    {

    }
    void insert()
    {

    }
};

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    {
        cin>> x;
        r.insert(x);
    }

    return 0;
}
