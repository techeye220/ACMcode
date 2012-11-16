#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

int str2num(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		string s2(s);
		bool conti = true;
		while (conti)
		{
			s = s2;
			s2 = "";
			int i = 0;
			int k = 0;
			while (i < s.size())
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					string sNum;
					while (i < s.size() && s[i]>='0' && s[i]<='9')
					{
						sNum += s[i];
						++i;
					}
					int n = str2num(sNum);
					
					if (s[i] != '(')
					{
						for (int m=0;m<n;++m)
							s2 += s[i];
						k = i;
					}else{
						int count1 = 1;
						int count2 = 0;
						k = i;
						while (count1 != count2)
						{
							++k;
							if (s[k] == '(' )
							++count1;
							if (s[k] == ')')
							++count2;
						}
						string stemp(s,i+1,k-i-1);
						for (int m=0;m<n;++m)
							s2 += stemp;
						i=k;
					}
				}else s2 += s[i];
				i++;
			}
			//cout << s2 << endl;
			conti = false;
			for (int j=0;j<s2.size();++j)
			{
				if (s2[j]>='0' && s2[j]<='9')
				{
					conti = true;
					break;
				}
			}
		}
		for (int j=0;j<s2.size();++j)
		{
			if (s2[j]>='a' && s2[j]<='z')
				printf("%c",s2[j]);
		}
		printf("\n");
	}
	return 0;
}
