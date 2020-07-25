#include <bits/stdc++.h>
using namespace std;
vector<int> mp;
vector<vector<int>> pers;
bool st[200010];

bool pst[11]; //参赛选手

bool iswrong(int x)
{
	//判断是否出错
	for (auto& num : mp)
	{
		if (st[num + x]) return false;
	}
	return true;
}

int main()
{
	freopen("C:/Users/zg/Desktop/data.txt", "r", stdin);
	int x, y;
	cin >> x >> y;
	st[x] = true, st[y] = true;
	mp.push_back(x), mp.push_back(y);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		vector<int> t;
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			t.push_back(x);
		}
		pers.push_back(t);
	}
	int cnt = 0;
	for (int j = 0; j < m; j++)
	{
		vector<int> out;
		for (int i = 0; i < n; i++)
		{
			if (pst[i]) continue;
			int t = pers[i][j];  //第i+1名玩家的第j+1轮出牌
			//判断t是否合法 1、判断t是否已经重复 2、判断t是否出错
			if (st[t] || iswrong(t))
			{
				//输出out
				out.push_back(i + 1);
				//printf("Round #%d: %d is out.\n", j + 1, i + 1);
				pst[i] = true;
				//如果出错是否还算？
				//st[t] = true;
				cnt++;
			}
			else
			{
				mp.push_back(t);
				st[t] = true;
			}
			
		}
		
		if (out.size())
		{
			for(int k = 0; k < out.size(); k++)
			printf("Round #%d: %d is out.\n", j + 1, out[k]);
		}
	}
	if (cnt < n)
	{
		printf("Winner(s):");
		for (int i = 0; i < n; i++)
		{
			if (!pst[i]) printf(" %d", i + 1);
		}
	}
	else {
		printf("No winner.");
	}
	fclose(stdin);
	return 0;
}