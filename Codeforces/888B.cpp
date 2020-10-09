#include <bits/stdc++.h>

using namespace std;

int dp[100][202][202];

int B(int N, string& s, int row, int col, int index)
{
    /*cout << "index = " << index << endl;
    cout << row << " " << col << endl;*/
	if(index == N && row == 0 && col == 0)
		return 0;
	else if(index == N)
		return -999;
	if(dp[index][row+101][col+101] != -1)
		return dp[index][row+101][col+101];
	int newrow = row;
	int newcol = col;
	if(s[index] == 'U')
		newcol++;
	else if(s[index] == 'D')
		newcol--;
	else if(s[index] == 'L')
		newrow--;
	else if(s[index] == 'R')
		newrow++;
	if(row == 0 && col == 0)
		return dp[index][row+101][col+101] = max(0, max(1 + B(N, s, newrow, newcol, index + 1), B(N, s, row, col, index + 1)));
	return dp[index][row+101][col+101] = max(1 + B(N, s, newrow, newcol, index + 1), B(N, s, row, col, index + 1));
}

int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;
	memset(dp, -1, sizeof(dp));
	cout << B(N, s, 0, 0, 0) << endl;
	return 0;
}