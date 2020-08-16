#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 110
#define LOGMAXN 21
#define MAXM 10010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

#define MINIMIZE -1
#define MAXIMIZE +1
#define LESSEQ -1
#define EQUAL 0
#define GREATEQ 1
#define INFEASIBLE -1
#define UNBOUNDED 999

/***
Problem example: https://www.hackerrank.com/contests/zenhacks/challenges/circles-1
Expected complexity O(N*N*M)
Worst case exponential complexity
1.  Simplex Algorithm for Linear Programming
2.  Maximize or minimize f0*x0 + f1*x1 + f2*x2 + ... + fn-1*xn-1 subject to some constraints
3.  Constraints are of the form, c0x0 + c1x1 + c2x2 + ... + cn-1xn-1 (<= or >= or =) lim
4.  m is the number of constraints indexed from 1 to m, and n is the number of variables indexed from 0 to n-1
5.  ar[0] contains the objective function f, and ar[1] to ar[m] contains the constraints, ar[i][n] = lim_i
6.  It is assumed that all variables satisfies non-negativity constraint, i.e, xi >= 0
7.  If non-negativity constraint is not desired for a variable x, replace each occurrence
	by difference of two new variables r1 and r2 (where r1 >= 0 and r2 >= 0, handled automatically by simplex).
	That is, replace every x by r1 - r2 (Number of variables increases by one, -x, +r1, +r2)
8.  solution_flag = INFEASIBLE if no solution is possible and UNBOUNDED if no finite solution is possible
9.  Returns the maximum/minimum value of the linear equation satisfying all constraints otherwise
10. After successful completion, val[] contains the values of x0, x1 .... xn for the optimal value returned
*** If ABS(X) <= M in constraints, Replace with X <= M and -X <= M
*** Fractional LP:
	max/min
		3x1 + 2x2 + 4x3 + 6
		-------------------
		3x1 + 3x2 + 2x3 + 5
		s.t. 2x1 + 3x2 + 5x3 >= 23
		3x2 + 5x2 + 4x3 <= 30
		x1, x2, x3 ≥ 0
	Replace with:
	max/min
		3y1 + 2y2 + 4y3 + 6t
		s.t. 3y1 + 3y2 + 2y3 + 5t = 1
		2y1 + 3y2 + 53 - 23t >= 0
		3y1 + 5y2 + 4y3- 30t <= 0
		y1, y2, y3, t >= 0
***/

namespace lp {
double val[MAXN], ar[MAXM][MAXN];
int m, n, solution_flag, minmax_flag, basis[MAXM], index[MAXN];

void init(int nvars, double* f, int flag) {
	solution_flag = 0;
	ar[0][nvars] = 0.0;
	m = 0, n = nvars, minmax_flag = flag;
	for (int i = 0; i < n; i++)
		ar[0][i] = f[i] * minmax_flag;
}

void add_constraint(double* C, double lim, int cmp) {
	m++, cmp *= -1;
	if (cmp == EQUAL) {
		for (int i = 0; i < n; i++) ar[m][i] = C[i];
		ar[m++][n] = lim;
		for (int i = 0; i < n; i++) ar[m][i] = -C[i];
		ar[m][n] = -lim;
	}
	else {
		for (int i = 0; i < n; i++) ar[m][i] = C[i] * cmp;
		ar[m][n] = lim * cmp;
	}
}

void init() {
	for (int i = 0; i <= m; i++) basis[i] = -i;
	for (int j = 0; j <= n; j++)
		ar[0][j] = -ar[0][j], index[j] = j, val[j] = 0;
}

inline void pivot(int m, int n, int a, int b) {
	for (int i = 0; i <= m; i++)
		for (int j = 0; i != a && j <= n; j++)
			if (j != b) ar[i][j] -= (ar[i][b] * ar[a][j]) / ar[a][b];
	for (int j = 0; j <= n; j++)
		if (j != b) ar[a][j] /= ar[a][b];
	for (int i = 0; i <= m; i++)
		if (i != a) ar[i][b] = -ar[i][b] / ar[a][b];
	ar[a][b] = 1.0 / ar[a][b];
	swap(basis[a], index[b]);
}

inline double solve() {
	init();
	int i, j, k, l;
	while (true) {
		for (i = 1, k = 1; i <= m; i++)
			if ((ar[i][n] < ar[k][n]) || (ar[i][n] == ar[k][n] && basis[i] < basis[k] && (rand() & 1))) k = i;
		if (ar[k][n] >= -EPS) break;
		for (j = 0, l = 0; j < n; j++)
			if ((ar[k][j] < (ar[k][l] - EPS)) || (ar[k][j] < (ar[k][l] - EPS) && index[i] < index[j] && (rand() & 1))) l = j;
		if (ar[k][l] >= -EPS) {
			solution_flag = INFEASIBLE;
			return -1.0;
		}
		pivot(m, n, k, l);
	}
	while (true) {
		for (j = 0, l = 0; j < n; j++)
			if ((ar[0][j] < ar[0][l]) || (ar[0][j] == ar[0][l] && index[j] < index[l] && (rand() & 1))) l = j;
		if (ar[0][l] > -EPS) break;
		for (i = 1, k = 0; i <= m; i++)
			if (ar[i][l] > EPS && (!k || ar[i][n] / ar[i][l] < ar[k][n] / ar[k][l] - EPS || (ar[i][n] / ar[i][l] < ar[k][n] / ar[k][l] + EPS && basis[i] < basis[k]))) k = i;
		if (ar[k][l] <= EPS) {
			solution_flag = UNBOUNDED;
			return -999.0;
		}
		pivot(m, n, k, l);
	}
	for (i = 1; i <= m; i++)
		if (basis[i] >= 0) val[basis[i]] = ar[i][n];
	solution_flag = 1;
	return (ar[0][n] * minmax_flag);
}
}

double obj[110],cons[110];

int n;
int x, y;
int xx[110], yy[110];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> x >> y)
	{
		FOR(i, 0, n)
		{
			cin >> xx[i] >> yy[i];
		}
		FOR(i, 0, n)
		{
			cons[i] = 1;
			obj[i] = 1;
		}
		obj[n] = 0;
		cons[n] = 0;
		lp::init(n, obj, MAXIMIZE);
		lp::add_constraint(cons, 1, EQUAL);
		FOR(i, 0, n)
		{
			cons[i] = xx[i];
		}
		lp::add_constraint(cons, x, EQUAL);
		FOR(i, 0, n)
		{
			cons[i] = yy[i];
		}
		lp::add_constraint(cons, y, EQUAL);
		double ret = lp::solve();
		FOR(i, 0, n)
			printf("%.10f\n", lp::val[i]);
	}
	return 0;
}