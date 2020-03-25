#include <bits/stdc++.h>

using namespace std;

int priority(char ch)
{
	if(isalnum(ch))
		return 0;
	if(ch == '(' or ch == ')')
		return 7;
	if(ch == '^')
		return 6;
	if(ch == '*' or ch == '/')
		return 5;
	if(ch == '+' or ch == '-')
		return 4;
	if(ch == '<' or ch == '>' or ch == '=' or ch == '#')
		return 3;
	if(ch == '.')
		return 2;
	if(ch == '|')
		return 1;
	return -1;
}

bool validChar(char ch)
{
	return priority(ch) != -1;
}

int main()
{
	string expr;
	while(getline(cin, expr))
	{
		string ans;
		stack<char> op;
		bool lexicalError = false;
		for(int i = 0; i < expr.size(); ++i)
		{
			if(!validChar(expr[i]))
			{
				lexicalError = true;
				break;
			}
		}
		if(lexicalError)
		{
			printf("Lexical Error!\n");
			continue;
		}
		bool syntaxError = false;
		int state = 0;
		int openParen = 0;
		for(int i = 0; i < expr.size(); ++i)
		{
			char ch = expr[i];
			//printf("%c %d\n", ch, state);
			if(isalnum(ch))
			{
				if(state == 1)
				{
					syntaxError = true;
					break;
				}
				state = 1;
			}
			else if(ch == '(')
			{
				if(state != 2 and i > 0)
				{
					syntaxError = true;
					break;
				}
				openParen++;
				state = 0;
			}
			else if(ch == ')')
			{
				if(openParen <= 0)
				{
					syntaxError = true;
					break;
				}
				openParen--;
				state = 1;
			}
			else
			{
				if(state != 1)
				{
					syntaxError = true;
					break;
				}
				state++;
			}
		}
		if(syntaxError || openParen > 0)
		{
			printf("Syntax Error!\n");
			continue;
		}
		for(int i = 0; i < expr.size(); ++i)
		{
			if(isalnum(expr[i]))
			{
				ans += expr[i];
			}
			else if(expr[i] == '(')
			{
				op.push('(');
			}
			else if(expr[i] == ')')
			{
				while(op.size() and op.top() != '(')
				{
					ans += op.top();
					op.pop();
				}
				op.pop();
			}
			else
			{
				int p = priority(expr[i]);
				while(op.size() and op.top() != '(' and p <= priority(op.top()))
				{
					ans += op.top();
					op.pop();
				}
				op.push(expr[i]);
			}
		}
		while(op.size())
		{
			ans += op.top();
			op.pop();
		}
		cout << ans << "\n";
	}
	return 0;
}