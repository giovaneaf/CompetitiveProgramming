#include <bits/stdc++.h>

#define INF 1e9
#define MAXN 200030
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

char str[MAXN];
int SA[MAXN];
int LCP[MAXN];
int st[4*MAXN];

int n;

void init(int cur, int l, int r)
{
	if(l == r)
	{
		st[cur] = LCP[l];
		return ;
	}
	int mid = (l + r) >> 1;
	int left = 2*cur + 1;
	int right = 2*cur + 2;
	init(left, l, mid);
	init(right, mid+1, r);
	st[cur] = min(st[left], st[right]);
}

int query(int cur, int l, int r, int ql, int qr)
{
	if(ql > r || qr < l) return INF;
	if(ql <= l && r <= qr) return st[cur];
	int mid = (l + r) >> 1;
	return min(query(2*cur+1, l, mid, ql, qr), query(2*cur+2, mid+1, r, ql, qr));
}

class SuffixArray {
	int RA[MAXN], tempRA[MAXN];
	int tempSA[MAXN], c[MAXN], n;
	int Phi[MAXN], PLCP[MAXN]; //para LCP
	void countingSort(int k, int SA[]) { // O(n)
		int i, sum, maxi = max(300, n);
		memset(c, 0, sizeof c);
		for (i = 0; i < n; i++) c[i + k < n ? RA[i + k] : 0]++;
		for (i = sum = 0; i < maxi; i++) {
			int t = c[i];
			c[i] = sum;
			sum += t;
		}
		for (i = 0; i < n; i++)
			tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
		for (i = 0; i < n; i++) SA[i] = tempSA[i];
	}
public:
	void constructSA(char str[], int SA[]) { // O(nlogn)
		int i, k, r; n = strlen(str);
		str[n++] = '$'; str[n] = 0;
		for (i = 0; i < n; i++) RA[i] = str[i];
		for (i = 0; i < n; i++) SA[i] = i;
		for (k = 1; k < n; k <<= 1) {
			countingSort(k, SA);
			countingSort(0, SA);
			tempRA[SA[0]] = r = 0;
			for (i = 1; i < n; i++) 
				tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
			for (i = 0; i < n; i++) RA[i] = tempRA[i];
			if (RA[SA[n-1]] == n-1) break;
		}
	}
	void computeLCP(char str[], int SA[], int LCP[]) { // O(n)
		int i, L; n = strlen(str);
		Phi[SA[0]] = -1;
		for (i = 1; i < n; i++)  Phi[SA[i]] = SA[i-1];
		for (i = L = 0; i < n; i++) {
			if (Phi[i] == -1) {
				PLCP[i] = 0; continue;
			}
			while (str[i + L] == str[Phi[i] + L]) L++;
			PLCP[i] = L;
			L = max(L-1, 0);
		}
		for (i = 0; i < n; i++) LCP[i] = PLCP[SA[i]];
	}
};


SuffixArray sa;


int KMP(string& current, string& pattern)
{
	vector<int> prefix(pattern.size());
	prefix[0] = 0;
	int j = 0;
	for(int i = 1; i < pattern.size(); ++i)
	{
		while(j > 0 && pattern[i] != pattern[j]) j = prefix[j-1];
		if(pattern[i] == pattern[j]) j++;
		prefix[i] = j;
	}
	int ip = 0;
	for(int i = 0; i < current.size(); ++i)
	{
		while(ip > 0 && current[i] != pattern[ip]) ip = prefix[ip-1];
		if(current[i] == pattern[ip])
		{
			ip++;
			if(ip == pattern.size())
				return i;
		}
	}
	return -1;
}

int main()
{
	while(cin >> n)
	{
		vector<string> s(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}
		string pattern;
		cin >> pattern;
		string concat;
		int idx = 0;
		vector<int> indexes;
		for(int i = 0; i < s.size(); ++i)
		{
			int ii;
			while((ii = KMP(s[i], pattern)) > -1)
			{
				s[i] = s[i].erase(ii - pattern.size() + 1, pattern.size());
			}
			concat += s[i];
			indexes.push_back(s[i].size());
			for(int j = 0; j < s[i].size(); ++j)
			{
				str[idx] = s[i][j];
				idx++;
			}
			if(i < s.size()-1)
			{
				concat += (char) i+1;
				str[idx] = (char) i+1;
			}
			idx++;
		}
		if(n == 1)
		{
		    cout << s[0] << "\n";
		    continue;
		}
		for(int i = 1; i < indexes.size(); ++i)
			indexes[i] += indexes[i-1]+1;
		str[idx-1] = '\0';
		int size = strlen(str)+1;
		sa.constructSA(str, SA);
		sa.computeLCP(str, SA, LCP);
		int color[MAXN];
		for(int i = 0; i < size; ++i)
		{
			color[i] = distance(indexes.begin(), lower_bound(indexes.begin(), indexes.end(), SA[i]));
		}
		int sz[n];
		for(int i = 0; i < n; ++i)
			sz[i] = 0;
		int lp = n;
		int bp = lp;
		sz[color[lp]]++;
		int lcp_size = 0;
		idx = 0;
		init(0, 0, size-1);
		while(bp < size)
		{
			bool possible = true;
			for(int i = 0; i < n; ++i)
			{
				if(sz[i] == 0)
				{
					possible = false;
					break;
				}
			}
			if(possible)
			{
				int tmp = query(0, 0, size-1, lp+1, bp);
				if(tmp > lcp_size)
				{
					lcp_size = tmp;
					idx = lp;
				}
				sz[color[lp++]]--;
				if(lp == size) break;
				if(bp < lp)
				{
					bp++;
					sz[color[bp]]++;
				}
			}
			else
			{
				bp++;
				if(bp == size) break;
				sz[color[bp]]++;
			}
		}
		cout << concat.substr(SA[idx], lcp_size) << "\n";
	}
	return 0;
}