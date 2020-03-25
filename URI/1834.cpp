#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Tvector
{
	ll x, y;
	Tvector(ll x = 0LL, ll y = 0LL) : x(x), y(y) {}
	Tvector operator- (Tvector& v)
	{
		return Tvector(x - v.x, y - v.y);
	}
	ll crossp(Tvector& v)
	{
		return x*v.y - y*v.x;
	}
};

double dist(Tvector& a, Tvector& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main()
{
	Tvector p1, p2;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	if(p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y))
	{
		Tvector tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	ll q;
	cin >> q;
	ll west[2] = {0LL, 0LL};
	ll east[2] = {0LL, 0LL};
	for(int i = 0; i < q; ++i)
	{
		Tvector qp;
		ll hab;
		cin >> qp.x >> qp.y >> hab;
		Tvector vec = p2 - p1;
		Tvector vec2 = qp - p1;
		ll cp = vec.crossp(vec2);
		if(cp > 0)
		{
			west[0] += 1LL;
			west[1] += hab;
		}
		else if(cp < 0)
		{
			east[0] += 1LL;
			east[1] += hab;
		}
	}
	printf("Relatorio Vogon #35987-2\n");
	printf("Distancia entre referencias: %.2f anos-luz\n", dist(p1, p2));
	printf("Setor Oeste:\n");
	printf("- %lld planeta(s)\n", west[0]);
	printf("- %lld bilhao(oes) de habitante(s)\n", west[1]);
	printf("Setor Leste:\n");
	printf("- %lld planeta(s)\n", east[0]);
	printf("- %lld bilhao(oes) de habitante(s)\n", east[1]);
	printf("Casualidades: %lld planeta(s)\n", q - east[0] - west[0]);
	return 0;
}