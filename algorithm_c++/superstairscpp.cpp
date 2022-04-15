#include <iostream>

using namespace std;

int ans[41][41];
int stairs(int x,int m)
{
	int count;
	if (x == m) return 1;
	if (x == m - 1)return 1;
	if (ans[x][m]) return ans[x][m];
	count = stairs(x + 1, m) + stairs(x + 2, m);
	ans[x][m] = count;
	return count;
}

int main_()
{
	int n,m;
	cin >> n;
	for (int i=0;i<41;i++)
		for(int j=0;j<41;j++)
			ans[i][j] = 0;
	
	while (n--)
	{
		
		cin >> m;
		if (ans[1][m])
			cout << ans[1][m] << endl;
		else
			cout << stairs(1,m)<<endl;

	}


	return 0;
}