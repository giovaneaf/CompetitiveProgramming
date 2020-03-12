#include <stdio.h>
#include <math.h>

int ST[300000][9] = {{}};
int lazy[300000] = {};
int v[9] = {};

int N, Q, size;

void rotate(int idx, int num)
{
	int tmp[9];
	for(int i = 0; i < 9; i++)
	{
		tmp[i] = ST[idx][i];
	}
	for(int i = 0; i < 9; i++)
	{
		ST[idx][(i+num)%9] = tmp[i];
	}
}

void mostfreq(int index, int l, int h, int ul, int uh)
{
	if(lazy[index] != 0)
	{
		int qty = lazy[index] % 9;
		rotate(index, qty);
		if(l != h)
		{
			lazy[2*index + 1] += qty;
			lazy[2*index + 2] += qty;
		}
		lazy[index] = 0;
	}
	if(l > uh || h < ul)
		return ;
	if(l >= ul && h <= uh)
	{
		for(int i = 0; i < 9; i++)
			v[i] += ST[index][i];
		return ;
	}
	int mid = (l + h)/2;
	
	mostfreq(2*index + 1, l, mid, ul, uh);
	mostfreq(2*index + 2, mid + 1, h, ul, uh);
	
	for(int i = 0; i < 9; i++)
	{
		ST[index][i] = ST[2*index + 1][i] + ST[2*index + 2][i];
	}
}

int mostfrequent(int ul, int uh)
{
	mostfreq(0, 0, N-1, ul, uh);
	int index = 8;
	int mf = v[8];
	v[8] = 0;
	for(int i = 7; i >= 0; i--)
	{
		if(v[i] > mf)
		{
			mf = v[i];
			index = i;
		}
		v[i] = 0;
	}
	return index;
}

void update(int index, int l, int h, int ul, int uh, int val)
{
	if(lazy[index] != 0)
	{
		int qty = lazy[index] % 9;
		rotate(index, qty);
		if(l != h)
		{
			lazy[2*index + 1] += qty;
			lazy[2*index + 2] += qty;
		}
		lazy[index] = 0;
	}
	if(l > uh || h < ul)
		return ;
	if(l >= ul && h <= uh)
	{
		rotate(index, val);
		if(l != h)
		{
			lazy[2*index + 1] += val;
			lazy[2*index + 2] += val;
		}
		return ;
	}
	int mid = (l + h)/2;
	
	update(2*index + 1, l, mid, ul, uh, val);
	update(2*index + 2, mid + 1, h, ul, uh, val);
	
	for(int i = 0; i < 9; i++)
	{
		ST[index][i] = ST[2*index + 1][i] + ST[2*index + 2][i];
	}
}

void createST(int index, int l, int h)
{
	if(l == h)
	{
		ST[index][1] = 1;
		return ;
	}
	int mid = (l + h)/2;
	createST(2*index + 1, l, mid);
	createST(2*index + 2, mid + 1, h);
	ST[index][1] = ST[2*index + 1][1] + ST[2*index + 2][1];
}

void show(int index, int l, int h)
{
	if(lazy[index] != 0)
	{
		int qty = lazy[index] % 9;
		rotate(index, qty);
		if(l != h)
		{
			lazy[2*index + 1] += qty;
			lazy[2*index + 2] += qty;
		}
		lazy[index] = 0;
	}
	if(l == h)
	{
		for(int i = 0; i < 9; i++)
		{
			if(ST[index][i] == 1)
			{
				printf("%d\n", i);
				return ;
			}
		}
	}
	int mid = (l + h)/2;
	show(2*index + 1, l, mid);
	show(2*index + 2, mid + 1, h);
}

int main()
{
	scanf("%d %d", &N, &Q);
	size = ceil(log2(N));
	size = 2*pow(2.0, size) - 1;
	createST(0, 0, N-1);
	for(int i = 0; i < Q; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int mf = mostfrequent(a, b);
		update(0, 0, N-1, a, b, mf);
	}
	show(0, 0, N-1);
	return 0;
}