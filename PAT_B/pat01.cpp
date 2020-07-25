#include <bits/stdc++.h>
using namespace std;
unordered_map<string, string> mp;


bool istrue(string& s)
{
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		if (s[i++] != s[j--]) return false;
	}
	return true;
}

int main()
{
	freopen("C:/Users/zg/Desktop/data.txt", "r", stdin);
	int n;
	cin >> n;
	mp["Jan"] = "01";
	mp["Feb"] = "02";
	mp["Mar"] = "03";
	mp["Apr"] = "04";
	mp["May"] = "05";
	mp["Jun"] = "06";
	mp["Jul"] = "07";
	mp["Aug"] = "08";
	mp["Sep"] = "09";
	mp["Oct"] = "10";
	mp["Nov"] = "11";
	mp["Dec"] = "12";

	for (int i = 0; i < n; i++)
	{
		string mon, day, year;
		cin >> mon >> day >> year;
		string t;
		while (year.size() != 4) year = "0" + year;
		t += year;
		t += mp[mon];
		day.pop_back();
		t += (day.size() == 1 ? "0" : "") + day;
		if (istrue(t)) printf("Y ");
		else printf("N ");
		cout << t << endl;
	}
	fclose(stdin);
	return 0;
}