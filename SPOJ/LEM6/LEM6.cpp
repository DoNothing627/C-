//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "LEM6"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, a[mn];
string c[mn][mn];

string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    forr(i, 1, m) cin>> a[i];

    /*c[1][a[1]- 1]= "0";
    forr(i, 1, m) c[i][0]= "0";*/

    forr(i, 0, m)
        forr(j, 0, n)
            c[i][j]= "0";

    forr(i, a[1], n)
        c[1][i]= add(c[1][i- 1], "1");

    forr(i, 2, m)
    {
        forr(j, 1, n)
        {
             if(j>= a[i]+ 1)
             {
                 c[i][j]= add(c[i][j- 1], c[i- 1][j- a[i]- 1]);
             }
        }
    }

    cout<< c[m][n];

    return 0;
}
