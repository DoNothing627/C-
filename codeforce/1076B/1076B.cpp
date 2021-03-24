#include <bits/stdc++.h>
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

long long n;
//vector< int> v;
bool d[1000005];

void snt()
{
    forr(i, 2, 1e6)
    {
        if(!d[i]){
            //v.push_back(i);
            for(long long j= 1ll* i* i; j<= 1e6; j+= i)
                d[j]= 1;
        }
    }
}


int main()
{

    freopen("1076B.inp", "r", stdin);
    cin>> n;
    snt();

    if(n% 2== 0){
        cout<< n/ 2;
        return 0;
    }
    forr(i, 3, sqrt(n))
    {
        if(n% i== 0&& !d[i]){
            n-= i;
            break;
        }
    }
    if(n% 2) cout<< 1;

    else cout<< n/ 2+ 1;

    return 0;
}
