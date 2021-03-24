//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 300005
#define pb push_back
#define oo 1337377
//#define int long long
#define DoNothing "NKSEV"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, f[mn];
string s, a;

struct trie
{
    //public:
    bool leaf= 0;
    trie *t[26];
}T;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> s>> n;
    forr(i, 1, n){
        cin>> a;
        trie *c= &T;
        for(int j= 0; j< a.size(); j++)
        {
            int x= a[j]- 'a';
            if(c-> t[x]== NULL) c-> t[x]= new trie();
            c= c-> t[x];
        }
        c->leaf= 1;
    }

    n= s.size();
    f[0]= 1;
    for(int i= 0; i< n; i++)
    {
        trie *c= &T;
        for(int j= i; j< n; j++)
        {
            int x= s[j]- 'a';
            if(c-> t[x]== NULL) break;
            c= c-> t[x];
            if(c-> leaf) f[j+ 1]= (f[j+ 1]+ f[i])% oo;
        }
    }

    cout<< f[n];

    return 0;
}
