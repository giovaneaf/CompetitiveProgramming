#include <bits/stdc++.h>

using namespace std;

int row[26];
char col[26];

void init()
{
	for(int i = 0; i < 26; ++i)
	{
		row[i] = i;
		col[i] = i + 'A';
	}
}

void process(int num)
{
	for(int c = row[num]; c < 25; ++c)
		swap(col[c], col[c+1]);
	for(int r = num; r < 25; ++r)
		swap(row[r], row[r+1]);
}

int main()
{
	int n;
	int t = 0;
	while(cin >> n)
	{
		t++;
		if(t > 1)
			putchar('\n');
		printf("LISTA #%d:\n", t);
		init();
		vector<string> v;
		string line;
		getline(cin, line);
		for(int i = 0; i < n; ++i)
		{
			getline(cin, line);
			stringstream sstream(line);
			int num;
			string curS;
			while(sstream >> num)
			{
				if(num == 27)
				{
					curS += ' ';
					continue;
				}
				num--;
				curS += col[row[num]];
				process(num);
			}
			v.push_back(curS);
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < n; ++i)
			cout << v[i] << "\n";

	}
	return 0;
}