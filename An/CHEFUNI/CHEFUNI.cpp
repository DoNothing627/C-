/* 7 ways to go from [0,0,0] to [x,y,z] with using these types of energy loses
-> a
-> b
-> c
-> a, b
-> a, c
-> b, c
-> a, b, c
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int a,b,c,x,y,z;
		int arr[3];

		cin>>arr[0]>>arr[1]>>arr[2]>>a>>b>>c;
		sort(arr,arr+3);
		x=arr[0];
		y=arr[1];
		z=arr[2];
		int ans=INT_MAX;


		// with a
		ans=min(ans,(x+y+z)*a);




		// with b
		if((x+y+z)%2==0)
		{
			if(x+y>=z)
			ans=min(ans,((x+y+z)/2)*b);
		}




		// with c
		if((x==y)&&(y==z))
			ans=min(ans,x*c);





		// with a and b

		// if a > b/2
		if(x+y<z)
			ans=min(ans,(x+y)*b+(z-x-y)*a);
		else if((x+y+z)&1)
			ans=min(ans,a+((x+y+z)/2)*b);

		// if a < b/2
		// these cases are already covered





		// with a and c
		// if a > c/3
		ans=min(ans,x*c+(y+z-2*x)*a);

		// if a < c/3
		// these cases are already covered





		// with b and c
		// if b/2 < c/3
		if((x+y+z)%2!=0&&x+y>z)
			ans=min(ans,c+((x+y+z-3)/2)*b);

		// if b/2 > c/3
		// this case will be covered in condition 			if c/3 < b/2 < a	below





		// with a, b and c

		// if a < b/2 < c/3
		// if a < c/3 < b/2
		// if b/2 < a < c/3
		// if c/3 < a < b/2
		// these cases are already covered

		// if b/2 < c/3 < a
		// not necessary

		// if c/3 < b/2 < a
		int COMMON=min(x,z-y);
		if(a+c<=2*b)
		    ans=min(ans,COMMON*(a+c)+(x-COMMON)*c+(z-y-COMMON)*a+(y-x)*b);
		else
			ans=min(ans,COMMON*(2*b)+(x-COMMON)*c+(z-y-COMMON)*a+(y-x)*b);

		cout<<ans<<endl;
	}

	return 0;
}
