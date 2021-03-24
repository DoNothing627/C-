#include <bits/stdc++.h>

using namespace std;

int t;
double d, n, a, b;

int main()
{
    freopen("1076C.inp", "r", stdin);
    cin>> t;
    while(t--){
        cin>> d;
        n= d;
        d= d* d/ 4- d;
        if(d< 0){
            cout<< "N\n";
            continue;
        }
        d= sqrt(d);
        a= d+ n/ 2;
        b= n- a;
        cout<< "Y ";
        cout<< fixed<< setprecision(9)<<  a<< " ";
        cout<< fixed<< setprecision(9)<< b<< "\n";
    }
    return 0;
}
