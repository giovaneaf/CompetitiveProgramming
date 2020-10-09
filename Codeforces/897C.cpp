#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000000000000000000
 
typedef unsigned long long int llu;
 
char f0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char fn[] = "What are you doing while sending xx? Are you busy? Will you send xx?";
 
llu size[100010];
 
char get(int n, llu k)
{
	//cout << n << " " << k << endl;
	if(n == 0)
	{
		int i = k;
		return f0[i];
	}
	else if(k < 34)
	{
		int i = k;
		if(fn[i] == 'x')
			return '"';
		return fn[i];
	}
	else if(k < 34+size[n-1])
	{
		return get(n-1, k-34);
	}
	else if(k < 34+size[n-1]+32)
	{
		int i = k - size[n-1];
		if(fn[i] == 'x')
			return '"';
		return fn[i];
	}
	else if(k < 34 + size[n-1]*2 + 32)
		return get(n-1, k-34-size[n-1]-32);
	if(k == size[n]-1)
		return '?';
	return '"'; 
}
 
int main()
{
	size[0] = strlen(f0);
	//cout << size[0] << endl;
	for(int i = 1; i < 100001; i++)
	{
		if(size[i-1]*2+64 > (llu) MAX)
			size[i] = MAX;
		else
			size[i] = size[i-1]*2 + 64 + 4;
	}
	int n, q;
	llu k;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> n >> k;
		k--;
		if(size[n] <= k)
			cout << ".";
		else
		{
			char car = get(n, k);
			cout << car;
		}
	}
	cout << endl;
	return 0;
}