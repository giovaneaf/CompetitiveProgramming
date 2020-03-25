#include <bits/stdc++.h>

#define INF 1e9
#define MAXN 200030
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void compute(int op1, int op2, int oper, vector<vector<bool>>& values)
{
	vector<bool> ans;
	if(oper == '&')
	{
		for(int i = 0; i < values[op1].size(); ++i)
		{
			bool v1, v2;
			v1 = values[op1][i];
			v2 = values[op2][i];
			ans.push_back(v1 && v2);
		}
	}
	else if(oper == '|')
	{
		for(int i = 0; i < values[op1].size(); ++i)
		{
			bool v1, v2;
			v1 = values[op1][i];
			v2 = values[op2][i];
			ans.push_back(v1 || v2);
		}
	}
	else if(oper == '-')
	{
		for(int i = 0; i < values[op1].size(); ++i)
		{
			bool v1, v2;
			v1 = values[op1][i];
			v2 = values[op2][i];
			ans.push_back(!(v1 && !v2));
		}
	}
	else
	{
		for(int i = 0; i < values[op1].size(); ++i)
		{
			bool v1, v2;
			v1 = values[op1][i];
			v2 = values[op2][i];
			ans.push_back(v1 == v2);
		}
	}
	values.push_back(ans);
}


int main()
{
	string expr;
	while(getline(cin, expr))
	{
	    cout << expr << "\n";
		vector<bool> symbol;
		symbol.assign(26, false);
		int size = 0;
		for(int i = 0; i < expr.size(); ++i)
		{
			if(expr[i] >= 'a' && expr[i] <= 'z')
			{
				int val = expr[i] - 'a';
				if(!symbol[val])
				{
					symbol[val] = true;
					size++;
				}
			}
		}
		map<char, int> m;
		int cnt = 0;
		for(int i = 0; i < 26; ++i)
		{
			if(symbol[i])
				m[i+'a'] = cnt++;
		}
		vector<vector<bool>> values(size);
		for(int i = 0; i < (1 << size); ++i)
		{
		    for(int j = 0; j < size; ++j)
		    {
		        values[size-1-j].push_back((((i&(1 << j)) > 0) ? 1 : 0));
		    }
		}
		stack<pair<char, int>> s;
		int ignore = 0;
		map<pair<char, int>, int> op;
		for(int i = 0; i < expr.size(); ++i)
		{
			if(expr[i] == ' ') continue;
			if(ignore > 0)
			{
				ignore--;
				continue;
			}
			if(expr[i] == ')')
			{
				char oo = s.top().first;
				int pos1 = s.top().second;
				s.pop();
				int op2;
				if(oo >= 'a' && oo <= 'z')
					op2 = m[oo];
				else
					op2 = op[{oo, pos1}];
				char oper = s.top().first;
				int pos = s.top().second;
				s.pop();
				if(oper == '!')
				{
					s.pop();
					vector<bool> ans;
					for(int i = 0; i < values[op2].size(); ++i)
					{
						ans.push_back(!values[op2][i]);
					}
					values.push_back(ans);
					s.push({oper, pos});
					op[{oper, pos}] = cnt++;
				}
				else
				{
					char oo = s.top().first;
					int pos1 = s.top().second;
					s.pop();
					s.pop();
					int op1;
					if(oo >= 'a' && oo <= 'z')
						op1 = m[oo];
					else
						op1 = op[{oo, pos1}];
					compute(op1, op2, oper, values);
					s.push({oper, pos});
					op[{oper, pos}] = cnt++;
				}
			}
			else if(expr[i] == '-' || expr[i] == '<')
			{
				s.push({expr[i], i});
				ignore = 2;
			}
			else if(expr[i] >= 'a' && expr[i] <= 'z')
			{
				s.push({expr[i], i});
			}
			else
			{
				s.push({expr[i], i});
			}
		}
		bool forward = false;
		int cur;
		for(int i = 0; i < values[0].size(); ++i)
		{
			for(int j = 0; j < expr.size(); ++j)
			{
			    if(expr[j] == ' ')
			    {
			        putchar(' ');
			        continue;
			    }
			    if(forward)
			    {
                    
			        cout << values[cur][i];
					forward = false;
			    }
				else if(expr[j] >= 'a' && expr[j] <= 'z')
				{
					cout << values[m[expr[j]]][i];
				}
				else if(expr[j] == '&' || expr[j] == '|' || expr[j] == '!')
				{
					cur = op[{expr[j], j}];
					cout << values[cur][i];
				}
				else
				{
					cout << " ";
					if(expr[j] == '-' || expr[j] == '<')
					{
					    cur = op[{expr[j], j}];
						forward = true;
					}
				}
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}