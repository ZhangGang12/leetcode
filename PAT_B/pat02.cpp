#include <bits/stdc++.h>
using namespace std;
int q[10010];

int main()
{
	freopen("C:/Users/zg/Desktop/data.txt", "r", stdin);
	int n, t;
	cin >> n >> t;
	int begin = -1, end = -1;
	int res = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &q[i]);
		res = max(res, q[i]);
		if (q[i] > t)
		{
			if (begin == -1)
			{
				begin = i;
				end = i;
			}
			else {
				end = i;
			}
		}
		else {
			if (begin != -1)
			{
				printf("[%d, %d]\n", begin, end);
				begin = end = -1;
			}
		}
	}
	if(begin != -1) printf("[%d, %d]\n", begin, end);
	if (res <= t) printf("%d", res);
	fclose(stdin);
	return 0;
}