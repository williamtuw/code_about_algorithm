//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int W[1000];
//int P[1000];
//int N, C, count_=0;
////int MAXP[1000];
//int num_obj[1000];
//int MAXP[1000][1000];//n,c
////int max_profit(int n, int c)
////{
////	if (MAXP[n][c] != -1)
////	{
////		return MAXP[n][c];
////	}
////	if (n == 0 || c <= 0)
////	{
////		MAXP[n][c] = 0;
////		return 0;
////	}
////		
////	
////	int maxp = max_profit(n - 1, c);
////	if (c - W[n] >= 0)
////	{
////		int temp_p = max_profit(n - 1, c - W[n])+P[n];
////		if (temp_p > maxp)
////		{
////			maxp = temp_p;
////			if(c==C)
////			num_obj[count_++] = n;
////		}
////	}
////	MAXP[n][c] = maxp;
////	return maxp;
////}
//
//int main_mp()
//{
//
//	cin >> N>>C;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> W[i] >> P[i];
//	}
//	
//	for(int i=0;i<=N;i++)
//		MAXP[i][0] = 0;
//	for (int i = 0; i <= C; i++)
//		MAXP[0][1] = 0;
//
//	for(int i=1;i<=N;i++)
//		for (int j = C; j >=1; j--)
//		{
//			MAXP[i][j] = MAXP[i - 1][j];
//			if (j - W[i] >= 0)
//				MAXP[i][j] = max(MAXP[i][j], MAXP[i-1][j - W[i]] + P[i]);
//		}
//	
//	int n=N, c=C;
//	while(n>0)	
//	{
//		if (MAXP[n][c] > MAXP[n - 1][c])
//		{
//			num_obj[count_++] = n;
//			c -= W[n];
//		}
//		n--;
//	}
//	int sum_w=0;
//	for (int i = count_-1; i >=0; i--)
//	{
//		cout << num_obj[i] << " " << W[num_obj[i]] << " " << P[num_obj[i]] << endl;
//		sum_w += W[num_obj[i]];
//	}
//	cout << "w=" << sum_w << ",pmax=" << MAXP[N][C] << endl;
//	return 0;
//}
//
