#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	map<string, double> pot;
	pot["HANDGUN"] = 2;
	pot["RED9"] = 3.5;
	pot["BLACKTAIL"] = 3.5;
	pot["MATILDA"] = 2;
	pot["HANDCANNON"] = 60;
	pot["STRIKER"] = 12;
	pot["TMP"] = 1.2;
	pot["RIFLE"] = 12;
	map<string, long long int> monster;
	monster["GANADOS"] = 50;
	monster["COBRAS"] = 40;
	monster["ZEALOT"] = 75;
	monster["COLMILLOS"] = 60;
	monster["GARRADOR"] = 125;
	monster["LASPLAGAS"] = 100;
	monster["GATLINGMAN"] = 150;
	monster["REGENERATOR"] = 250;
	monster["ELGIGANTE"] = 500;
	monster["DR.SALVADOR"] = 350;
	while(scanf("%d", &n) != EOF) {
		vector<pair<double, int>> v;
		for(int i = 0; i < n; ++i) {
			string gun;
			int qty;
			cin >> gun >> qty;
			v.push_back(make_pair(pot[gun], qty));
		}
		int m;
		scanf("%d", &m);
		long long int total = 0;
		for(int i = 0; i < m; ++i) {
			string monst;
			long long int qty;
			cin >> monst >> qty;
			total += qty*monster[monst];
		}
		int numberOfShots;
		scanf("%d", &numberOfShots);
		double memo[n+1][numberOfShots+1];
		for(int i = 0; i <= n; ++i) {
			memo[i][0] = 0.0;
		}
		for(int i = 0; i <= numberOfShots; ++i) {
			memo[0][i] = 0.0;
		}

		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= numberOfShots; ++j) {
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
				int qty = v[i-1].second;
				double w = v[i-1].first;
				if(j >= qty) {
					memo[i][j] = max(memo[i][j], qty*w + memo[i-1][j-qty]);
				}
			}
		}
		
		double highestDamage = memo[n][numberOfShots];
		if(highestDamage - total > 0.0) {
			printf("Missao completada com sucesso");
		} else {
			printf("You Are Dead");
		}
		printf("\n\n");
	}
	return 0;
}