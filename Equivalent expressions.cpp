#include <iostream>
#include <stack>
#include <map>
#include <string.h>

using namespace std;
char s1[100];
map<char, int>m;
bool IsChar(char ch)
{
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ||
		ch >= '1' && ch <= '9')
		return true;
	else
		return false;
}
void Change(char ch[])
{
	stack<char> s;
	int len = strlen(ch);
	int i, j = 0;
	for (i = 0; i < len; i++)
	{
		if (IsChar(ch[i]))
		{
			s1[j++] = ch[i];
		}
		else
		{
			switch (ch[i])
			{
			case '(':
				s.push(ch[i]);
				break;
			case ')':
				while (s.top() != '(')
				{
					s1[j++] = s.top();
					s.pop();
				}
				s.pop();
				break;
			case '+':
			case '-':
			case '*':
				while (!s.empty() && m[s.top()] >= m[ch[i]])
				{
					s1[j++] = s.top();
					s.pop();
				}
				s.push(ch[i]);
				break;
			}
		}
	}
	while (!s.empty())
	{
		s1[j++] = s.top();
		s.pop();
	}
	s1[j] = 0;
}
int Result()
{
	stack<int> s;
	int len = strlen(s1), i;
	for (i = 0; i < len; i++)
	{
		if (IsChar(s1[i]))
		{
			if (s1[i] >= '1' && s1[i] <= '9')
				s.push(s1[i] - '0');
			else
			{
				s.push((int)s1[i]);
			}
		}
		else
		{
			int a, b;
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			switch (s1[i])
			{
			case '+':
				s.push(a + b);
				break;
			case '-':
				s.push(b - a);
				break;
			case '*':
				s.push(a*b);
				break;
			}
		}
	}
	return s.top();
}
int main()
{
	int N;
	char ch1[100], ch2[100];
	cin >> N;
	m['+'] = 1;
	m['-'] = 1;
	m['*'] = 2;
	m['('] = 0;
	cin.getline(ch1, 100, '\n');
	while (N--)
	{
		cin.getline(ch1, 100, '\n');
		cin.getline(ch2, 100, '\n');
		int n1, n2;
		Change(ch1);
		n1 = Result();
		Change(ch2);
		n2 = Result();
		if (n1 == n2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}