
#include <iostream>

using namespace std;
int n;
bool MAP[120][120];
int ans[120];
int flag[120];
//给剩下的m个人分数
bool distrubute_books(int m)
{
	//给第一m人分配书
	for (int i = 0; i < n; i++)
	{
		if (MAP[m][i]&&!flag[i])
		{
			ans[m] = i;
			flag[i] = 1;
			if (distrubute_books(m - 1))
				return true;
			flag[i] = 0;
		}

	}
	return false;
}

int main_()
{

	while (cin >> n)
	{
		// flag 重置

		for (int i=0;i<n;i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> MAP[i][j];
				
			}
			flag[i] = 0;
		}

		//给第一个人分配书
		for (int i = 0; i < n; i++)
		{
			if (MAP[0][i]&&!flag[i])
			{
				ans[0] = i;
				flag[i] = 1;
				if (distrubute_books(n-1))
					break;
				flag[i] = 0;
			}

		}

		int t;
		//输出结果
		for (int i = 0; i < n; i++)
		{
			cout << " "+1-bool(i) << ans[i] + 1 << "\n"+1 - !bool(i + 1 - n);
		}
	}




	return 0;
}