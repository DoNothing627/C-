//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "MMASS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n;
string s;
stack< int> p;

int crt(char c)
{
    if(c== '(') return 0;
    if(c== 'C') return 12;
    if(c== 'O') return 16;
    if(c== 'H') return 1;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> s;
    n= s.size();
    s= " "+ s;

    forr(i, 1, n)
    {
        //if(s[i]== '(') p.push(0);
        if(s[i]== ')'){
            int ans= 0;
            while(p.top()){
                ans+= p.top();
                p.pop();
            }
            p.pop();
            p.push(ans);
            continue;
        }
        if('2'<= s[i]&& s[i]<= '9'){
            int ans= p.top()* (s[i]- '0');
            p.pop();
            p.push(ans);
            continue;
        }
        p.push(crt(s[i]));
    }

    int ans= 0;

    while(p.size()){
        ans+= p.top();
        p.pop();
    }

    cout<< ans;

    return 0;
}
