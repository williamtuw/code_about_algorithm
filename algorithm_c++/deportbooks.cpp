
#include <iostream>

using namespace std;
int n;
bool MAP[120][120];
int ans[120];
int flag[120];
//��ʣ�µ�m���˷���
bool distrubute_books(int m)
{
	//����һm�˷�����
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
		// flag ����

		for (int i=0;i<n;i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> MAP[i][j];
				
			}
			flag[i] = 0;
		}

		//����һ���˷�����
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
		//������
		for (int i = 0; i < n; i++)
		{
			cout << " "+1-bool(i) << ans[i] + 1 << "\n"+1 - !bool(i + 1 - n);
		}
	}




	return 0;
}