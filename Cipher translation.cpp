#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int main()
{
	unsigned int i, n;
	string str;
	cin >> n;
	getchar();
	while (n-- > 0)
	{
		getline(cin, str);
		for (i = 0; str[i]!='\0'; i++)
			if ((str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
			{
				str[i]++;
				if (str[i] == ('z' + 1) || str[i] == ('Z'+1))
				str[i] -= 26;
			}
		cout << str << endl;
	}
	return 0;
}