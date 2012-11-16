#include <cstdio>
#include <string.h>

using namespace std;

char str[300];
int dir[4][2] = {{10,0},{0,-10},{-10,0},{0,10}};

int main()
{
    while(scanf("%s",str) != EOF)
    {
		int i,j,tmp,k;
		int n = strlen(str);
	    int cur = 0;
	    int x = 300;
	    int y = 420;
		printf("%d %d moveto\n",x,y);
		x += 10;
		printf("%d %d lineto\n",x,y);

		for(i = 0; i < n; ++i)
		{
			if(str[i] == 'A')
				cur = ((++cur)&3);
			else if(str[i] == 'V')
					cur = ((--cur+4)&3);
			x += dir[cur][0];
			y += dir[cur][1];
			printf("%d %d lineto\n",x,y);
		}
		printf("stroke\nshowpage\n");
    }
    return 0;
}

