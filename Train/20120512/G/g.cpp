#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct qujian{
    int begin;
    int end;
};
qujian q[100000];
qujian ans[100000];
int max(int a,int b){
    if (a>b)
        return a;
    return b;
}
int min(int a,int b){
    if (a<b)
        return a;
    return b;
}
void qsort(int s,int t)
{
    int i,j,mid;
    i=s;j=t;
    mid=q[(i+j)/2].begin;
    while (i<=j)
    {
        while (q[i].begin < mid) i++;
        while (q[j].begin > mid) j--;
        if (i<=j)
        {
            int temp = q[i].begin;
            q[i].begin = q[j].begin;
            q[j].begin = temp;

            temp = q[i].end;
            q[i].end = q[j].end;
            q[j].end = temp;

            i++;j--;
        }
    }
    if (i < t) qsort(i,t);
    if (s < j) qsort(s,j);
}
int main()
{
    int n;
    int ca=0;
    while (cin >> n)
    {
        int begin[15],end[15];
        memset(begin,0,sizeof(begin));
        memset(end,0,sizeof(end));
        memset(q,0,sizeof(q));

        for (int i=0;i<n;++i)
            scanf("%d",&begin[i]);
        for (int i=0;i<n;++i)
            scanf("%d",&end[i]);

		q[0].begin = 0;
		q[0].end = 0;
		int p=0;
		for (int i=0;i<n;++i)
		{
			int temp = p;
			for (int j=0;j<=temp;++j)
			{
				p++;
				q[p].begin = q[j].begin + begin[i];
				q[p].end =  q[j].end + end[i];
			}
		}

        qsort(1,p);
        int k = 0;
        int count = 0;
        int temp = 0;
        for (int i=1;i<p;++i)
        {
            if (q[i].end < q[i+1].begin)
            {
                count += q[i].end-q[i].begin+1;
            }else{
                q[i+1].begin = min(q[i+1].begin,q[i].begin);
                q[i+1].end = max(q[i+1].end,q[i].end);
            }
        }
        count += q[p].end-q[p].begin+1;
        ca++;
        printf("Case %d: %d\n",ca,count);
    }
    return 0;
}
