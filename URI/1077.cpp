#include <bits/stdc++.h>

using namespace std;

bool isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int prec(char ch)
{
	if(ch == '(')
		return 0;
	if(ch == '+' || ch == '-')
		return 1;
	if(ch == '*' || ch == '/')
		return 2;
	if(ch == '^')
		return 3;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string expr;
		cin >> expr;
		stack<char> s;
		string ans;
		for(int i = 0; i < expr.size(); ++i)
		{
			if(expr[i] == '(')
			{
				s.push(expr[i]);
			}
			else if(expr[i] == ')')
			{
				while(s.top() != '(')
				{
					ans.push_back(s.top());
					s.pop();
				}
				s.pop();
			}
			else if(isOperator(expr[i]))
			{
				while(s.size() and prec(s.top()) >= prec(expr[i]))
				{
					ans.push_back(s.top());
					s.pop();
				}
				s.push(expr[i]);
			}
			else
			{
				ans.push_back(expr[i]);
			}
		}
		while(s.size())
		{
			ans.push_back(s.top());
			s.pop();
		}
		cout << ans << "\n";
	}
	return 0;
}