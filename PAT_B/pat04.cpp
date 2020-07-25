#include <bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
	if (x <= 1) return false;
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	freopen("C:/Users/zg/Desktop/data.txt", "r", stdin);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		string  t = s.substr(i);
		printf("%s", t.c_str());
		if (isprime(stoi(t))) printf(" Yes\n");
		else {
			printf(" No\n");
			cnt++;
		}
	}
	if (cnt == 0) printf("All Prime!");
	
		

	fclose(stdin);
	return 0;
}