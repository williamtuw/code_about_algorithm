#include <iostream>
#include <math.h>
using namespace std;

int main_()
{
	int n,N;
	cin >> n;
	double x;
	while (n--)
	{
		cin >> N;
		x = N * log10(N);
		x -= long long(N*log10(N));

		cout << int(pow(10, x ))<<endl;
	}
	return 0;
}