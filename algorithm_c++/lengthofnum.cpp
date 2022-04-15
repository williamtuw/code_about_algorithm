#include <iostream>

using namespace std;

int main_()
{
	int n;
	double sum;
	while (cin>>n)
	{
		sum = 1.0;
		for (int i=2;i<=n;i++)
		{
			sum += log10(i);
		}
		cout << int(sum) << endl;
	}
	return 0;
}