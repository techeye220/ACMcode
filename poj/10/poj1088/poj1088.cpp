#include <cstdio>
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
const int MAX_LEN = 100;
int map[MAX_LEN+5][MAX_LEN+5];
int vis[MAX_LEN+5][MAX_LEN+5];
int r,c;
int dp(int x,int y)
{
	if (vis[x][y] > 0)
	{
		return vis[x][y];
	}
	int max = 0;
	int cnt = 0;
	for (int i=0;i<4;i++)
	{
		if (x+dx[i] >= 0 && x+dx[i] <= r-1 && y+dy[i] >= 0 && y+dy[i] <= c-1)
		{
			if (map[x][y] < map[x+dx[i]][y+dy[i]])
			{
				cnt = dp(x+dx[i],y+dy[i]);
				if (max < cnt)
					max = cnt;
			}
		}
	}
	vis[x][y] = max + 1;
	return vis[x][y];
}
int main()
{
	scanf("%d%d",&r,&c);
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++)
		{
			scanf("%d",&map[i][j]);
			vis[i][j] = 0;
		}
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			dp(i,j);
		}
	}
	int max = 0;
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			if (max < vis[i][j])
			{
				max = vis[i][j];
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
