#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		double x = 0,y = 0;
		double tempx,tempy;
		for (int i=0;i<n;++i)
		{
			scanf("%lf%lf",&tempx,&tempy);
			x += tempx;
			y += tempy;
		}
		printf("%.2lf %.2lf\n",x/n,y/n);
	}
	return 0;
}
