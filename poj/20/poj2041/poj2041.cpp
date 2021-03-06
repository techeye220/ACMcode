#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void J(string &s)
{
	char temp = s[s.size()-1];
	for (int i=s.size()-1;i>0;i--)
		s[i]=s[i-1];
	s[0] = temp;
}
void C(string &s)
{
	char temp = s[0];
	for (int i=0;i<s.size()-1;i++)
		s[i] = s[i+1];
	s[s.size()-1] = temp;
}
void E(string &s)
{
	char temp;
	int i,j;
	for (i=0,j=(s.size()+1)/2;i<s.size()/2,j<s.size();i++,j++)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
void A(string &s)
{
	reverse(s.begin(), s.end());
}
void P(string &s)
{
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			if (s[i] == '0')
				s[i] = '9';
			else 
				s[i]--;
		}
	}
}
void M(string &s)
{
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			if (s[i] == '9')
				s[i] = '0';
			else 
				s[i]++;
		}
	}
}
int main()
{
	int Case;
	cin >> Case;
	while (Case--)
	{
		string order,str;
		cin >> order >> str;
		for (int i=order.size()-1;i>=0;i--)
		{
			switch (order[i]){
				case 'J' :J(str);break;
				case 'C' :C(str);break;
				case 'E' :E(str);break;
				case 'A' :A(str);break;
				case 'P' :P(str);break;
				case 'M' :M(str);break;
			}
		}
		cout << str << endl;
	}
	return 0;
}
