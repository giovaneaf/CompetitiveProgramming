/*
You can use Segment Tree 2D, in this problem can be used one dimension for the row and the other for the column.
*/

#include <bits/stdc++.h>

using namespace std;

const int SIZE = (1 << 11) + 10;

int row, col, treer, treec;
int st[SIZE][SIZE];

int colquery(int i, int cur, int l, int h, int ql, int qh);
int rowquery(int cur, int l, int h, int qrl, int qrh, int qcl, int qch);
void colupdate(int i, int cur, int l, int h, int uc, int value);
void rowupdate(int cur, int l, int h, int ur, int uc, int value);

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int p;
	while(cin >> col >> row >> p)
	{
		if(row == 0 and col == 0 and p == 0) break;
		treer = 2*pow(2, ceil(log2(row)))-1;
		treec = 2*pow(2, ceil(log2(col)))-1;
		for(int i = 0; i < treer; ++i)
			for(int j = 0; j < treec; ++j)
				st[i][j] = 0;
		int Q;
		cin >> Q;
		while(Q--)
		{
			char ch;
			cin >> ch;
			//cout << ch << "\n";
			if(ch == 'A')
			{
				int n, xpos, ypos;
				cin >> n >> xpos >> ypos;
				rowupdate(0, 0, row-1, ypos, xpos, n);
			}
			else
			{
				int x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				cout << rowquery(0, 0, row-1, min(y1, y2), max(y1, y2), min(x1, x2), max(x1, x2))*p << "\n";
			}
		}
		putchar('\n');
	}
	return 0;
}

int colquery(int i, int cur, int l, int h, int ql, int qh)
{
	if(ql > h or qh < l) return 0;
	if(l >= ql and h <= qh) return st[i][cur];
	int mid = (h+l) >> 1;
	int left = 2*cur+1;
	int right = left+1;
	return colquery(i, left, l, mid, ql, qh) + colquery(i, right, mid+1, h, ql, qh);
}

int rowquery(int cur, int l, int h, int qrl, int qrh, int qcl, int qch)
{
	if(qrl > h or qrh < l) return 0;
	if(l >= qrl and h <= qrh) return colquery(cur, 0, 0, col-1, qcl, qch);
	int mid = (h+l) >> 1;
	int left = 2*cur+1;
	int right = left+1;
	return rowquery(left, l, mid, qrl, qrh, qcl, qch) + rowquery(right, mid+1, h, qrl, qrh, qcl, qch);
}

void colupdate(int i, int lr, int hr, int cur, int l, int h, int uc, int value)
{
	if(l == h)
	{
		if(lr == hr)
			st[i][cur] += value;
		else
			st[i][cur] = st[2*i+1][cur] + st[2*i+2][cur];
	}
	else
	{
		int mid = (l + h) >> 1;
		if(uc <= mid)
			colupdate(i, lr, hr, 2*cur+1, l, mid, uc, value);
		else
			colupdate(i, lr, hr, 2*cur+2, mid+1, h, uc, value);
		st[i][cur] = st[i][2*cur+1] + st[i][2*cur+2];
	}
}

void rowupdate(int cur, int l, int h, int ur, int uc, int value)
{
	if(l != h)
	{
		int mid = (h+l) >> 1;
		if(ur <= mid)
			rowupdate(2*cur+1, l, mid, ur, uc, value);
		else
			rowupdate(2*cur+2, mid+1, h, ur, uc, value);
	}
	colupdate(cur, l, h, 0, 0, col-1, uc, value);
}