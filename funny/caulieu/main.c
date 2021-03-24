#include <stdio.h>
#include <stdlib.h>

int n;
typedef struct data
{
    int a;
    struct data *next;
}data;

data *T;

int size(data *T)
{
    //data *c= &T;
    if(T-> next== NULL) return 0;
    return 1+ size(T-> next);
}

int main()
{
    freopen("main.inp", "r", stdin);
    data *c= T;
    while(1){
        scanf("%d", &n);
        c-> a= n;
        if(n== 2) break;
        c-> next= (data*) malloc(sizeof(data));
        c= c-> next;
        c-> next= NULL;
    }

    printf("%d", size(T));
    return 0;
}
