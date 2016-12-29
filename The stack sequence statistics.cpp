#include <iostream>
using namespace std;

int n;
template <typename T>
class Stack{
	T a[16];
	int top;
public:
	Stack() :top(-1){}
	void push(T d)
	{
		a[++top] = d;
	}
	void pop()
	{
		top--;
	}
	bool empty()
	{
		return top<0;
	}
	bool full()
	{
		return top >= n - 1;
	}
};
int f = 0;
int fun(Stack<int> a, int s)
{
	if (a.empty() && s == 0)
	{
		f++;
		return 0;
	}
	else if (a.empty())
	{
		a.push(s);
		fun(a, --s);
		a.pop();
	}
	else if (s == 0)
	{
		a.pop();
		fun(a, s);
	}
	else
	{
		a.push(s);
		fun(a, --s);
		a.pop();
		++s;
		a.pop();
		fun(a, s);
	}
	return 0;
}

int main()
{
	cin >> n;
	Stack<int> a;
	fun(a, n);
	cout << f << endl;
	return 0;
}