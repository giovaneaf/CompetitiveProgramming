#include <bits/stdc++.h>
 
using namespace std;
 
int P, M, G;
 
bool Area(int w, int h)
{
	if(w == 0 || h == 0)
		return true;
	if(w >= 30 and h >= 30 and G > 0)
	{
		int bpl = w/30;
		int lines = G/bpl;
		lines = min(lines, h/30);
		int hc = lines*30;
		G -= (lines*bpl);
		if(hc == h)
			return Area(w-30*bpl, hc);
		bool possible = Area(w-30*bpl, hc);
		if(!possible)
			return false;
		if(G > 0 && h-hc >= 30)
		{
			int nw = w - 30*G;
			G = 0;
			return Area(nw, 30) && Area(w, h-hc-30);
		}
		else
		{
			return Area(w, h - hc);
		}
	}
	else if(w >= 15 and h >= 15 and M > 0)
	{
		int bpl = w/15;
		int lines = M/bpl;
		lines = min(lines, h/15);
		int hc = lines*15;
		M -= (lines*bpl);
		if(hc == h)
			return Area(w-15*bpl, hc);
		bool possible = Area(w-15*bpl, hc);
		if(!possible)
			return false;
		if(M > 0 && h-hc >= 15)
		{
			int nw = w - 15*M;
			M = 0;
			return Area(nw, 15) && Area(w, h-hc-15);
		}
		else
		{
			return Area(w, h - hc);
		}
	}
	else if(w >= 5 and h >= 5 and P > 0)
	{
		int bpl = w/5;
		int lines = P/bpl;
		lines = min(lines, h/5);
		int hc = lines*5;
		P -= (lines*bpl);
		if(hc == h)
			return Area(w-5*bpl, hc);
		bool possible = Area(w-5*bpl, hc);
		if(!possible)
			return false;
		if(P > 0 && h-hc >= 5)
		{
			int nw = w - 5*P;
			P = 0;
			return Area(nw, 5) && Area(w, h-hc-5);
		}
		else
		{
			return Area(w, h - hc);
		}
	}
	return false;
}
 
int main()
{
	double nX, nY, nZ;
	while(cin >> nX >> nY >> nZ)
	{
		int X, Y, Z;
		X = nX*100 + 0.5;
		Y = nY*100 + 0.5;
		Z = nZ*100 + 0.5;
		if(X == 0 and Y == 0 and Z == 0) break;
		cin >> P >> M >> G;
		int cP, cM, cG;
		cP = P; cM = M; cG = G;
		bool possible = Area(X, Y);
		if(!possible) goto label;
		possible = possible && Area(X,Z);
		if(!possible) goto label;
		possible = possible && Area(X,Z);
		if(!possible) goto label;
		possible = possible && Area(Y,Z);
		if(!possible) goto label;
		possible = possible && Area(Y,Z);
	label:
		if(possible)
			printf("%d %d %d\n", cP-P, cM-M, cG-G);
		else
			printf("impossivel\n");
	}
	return 0;
} 