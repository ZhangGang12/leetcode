#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];
int res[100010];
int cns;

void add(int len1, int len2)
{
	int i = 0, j = 0, fla = 0;
	while (i < len1 || j < len2 || fla)
	{
		if (i < len1) fla += a[i++];
		if (j < len2) fla += b[j++];
		res[cns++] = fla % 30;
		fla /= 30;
	}
}

int main()
{
	freopen("C:/Users/zg/Desktop/data.txt", "r", stdin);
	unordered_map<char, int> mp;
	unordered_map<int, char> mps;
	char c = '0';
	for (int i = 0; i <= 9; i++)
	{
		mps[i] = c;
		mp[c++] = i;
	}
	c = 'a';
	for (int i = 10; i <= 29; i++) { 
		mps[i] = c;
		mp[c++] = i; 
	}

	string a1, b1;
	cin >> a1 >> b1;
	int cnt = 0;
	for (int i = a1.size() - 1; i >= 0; i--) a[cnt++] = mp[a1[i]];
	cnt = 0;
	for (int i = b1.size() - 1; i >= 0; i--) b[cnt++] = mp[b1[i]];

	add(a1.size(), b1.size());

	while (res[cns] == 0 && cns > 0) cns--;
	int k = 0;
	string s;
	for (int i = cns; i >= 0; i--) {
		s += mps[res[i]];
	}
	cout << s;
	fclose(stdin);
	return 0;
}