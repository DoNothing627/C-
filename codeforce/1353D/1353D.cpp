//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1353D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, a[mn];
queue< ii> q;
vector< int> v[mn];

bool cmt(int y, int z)
{
    return y> z;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n;
        int ans= 0;
        q.push(ii(1, n));
        while(q.size()){
            int l= q.front().first, r= q.front().second;
            q.pop();
            if(l> r) continue;
            int c= r- l+ 1;
            if(c% 2){
                //a[(l+ r)/ 2]= ++ans;
                v[r- l+ 1].pb((l+ r)/ 2);
                q.push(ii(l, (l+ r)/ 2- 1));
                q.push(ii((l+ r)/ 2+ 1, r));
            }
            else{
                //a[(l+ r- 1)/ 2]= ++ans;
                v[r- l+ 1].pb((l+ r- 1)/ 2);
                q.push(ii((l+ r- 1)/ 2+ 1, r));
                q.push(ii(l, (l+ r- 1)/ 2- 1));
            }
        }
        //forr(i, 1, n) cout<< a[i]<< " ";
        for(int i= n; i> 0; i--)
        {
            sort(v[i].begin(), v[i].end());
            for(int u: v[i]) a[u]= ++ans;
        }
        for(int i= n; i> 0; i--) v[i].clear();
        forr(i, 1, n) cout<< a[i]<< " ";
        cout<< "\n";
    }

    return 0;
}
