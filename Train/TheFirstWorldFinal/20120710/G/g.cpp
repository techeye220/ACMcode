#include <cstdio>
#include <iostream>
using namespace std;
long long abs(long long a,long long b)
{
	if (a>b)
	  return a-b;
	else 
	  return b-a;
}
int month[]={0,1,9,36,100,225,441,784,1296,2025,3025,4356,6084};
int year[]={1,9,36,100,225,441,784,1296,2025,3025,4356,6084};
int past[]={0,1,10,46,146,371,812,1596,2892,4917,7942,12298};
const int MAX_DAYS = 6084;
const int MAX_12 = 18382;
int main()
{
	int year1,year2,mon1,mon2,day1,day2;
	while (scanf("%d-%d-%d",&mon1,&day1,&year1) != EOF)
	{
		scanf("%d-%d-%d",&mon2,&day2,&year2);
		long long days1=year1/12*MAX_12+month[mon1-1]+day1;
		long long days2=year2/12*MAX_12+month[mon2-1]+day2;
		//cout << days1<< endl;
		//cout << days2 << endl;
		days1+=past[year1%12];
		days2+=past[year2%12];

		//cout << days1<<endl;
		//cout << days2<<endl;
		if (year1!=0)
		  days1+=(year1-1)/11+1;
		if (year2!=0)
		  days2+=(year2-1)/11+1;
		if (year1>0)
		  days1++;
		if (year2>0)
		  days2++;
		if (year1%11==0 && mon1>1)
		  days1++;
		if (year2%11==0 && mon2>1)
		  days2++;
		//cout << days1<< endl;
		//cout << days2<< endl;
		printf("%lld",abs(days1,days2)+1);
	}
	return 0;
}