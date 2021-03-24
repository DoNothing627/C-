#include <stdio.h>
#include <conio.h>
#define PI 3.14159265
#define float double
//#define lf f

float ABS(float a)
{
    if(a< 0) return -a;
    return a;
}

 main()
{
    float x, y, z, val = PI / 180.0;

    //ret = cos( x*val );
    scanf("%lf%lf%lf", &x, &y, &z);

    float ans= cos(y* val);

    float f= ((x+ y+ z)/(x* x+ y* y+ 1)- ABS(x- z* ans));

    printf("%0.6lf\n", ans);

    //printf("%0.6f\n", ABS(x- z* cos(y)));

    printf("%0.6lf", f);
    return 0;
 }
