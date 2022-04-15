//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int ARR[21],N;
//int WAYS[41][21];//v,k从左边k个物品中选出组成v体积的方法数
//
//int main_mp()
//{
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> ARR[i+1];
//		WAYS[0][i+1] = 1;
//	}
//	for (int i = 0; i <= 40; i++)
//		WAYS[i][0] = 0;
//	WAYS[0][0] = 1;
//
//	for(int i=1;i<=40;i++)
//		for (int j = 1; j <= N; j++)
//		{
//			WAYS[i][j] = WAYS[i][j - 1];
//			if (i - ARR[j] >= 0)
//				WAYS[i][j] += WAYS[i - ARR[j]][j - 1];
//		}
//
//
//	cout << WAYS[40][N] << endl;
//
//	return 0;
//}
//
