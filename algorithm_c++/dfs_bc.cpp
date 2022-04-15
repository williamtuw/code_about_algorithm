//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//
//int N,M,minS,totals;
//int minv[21];
//int mins[21];
//int MAXV_[100][100][20];
//
//int maxV(int i, int j, int n)
//{
//	int maxv = 0;
//	for (int k = 0; k < n; k++)
//		maxv += (i-k) * (i-k)*(j-k);
//	return maxv;
//}
//
//void dfs_bc(int v, int n,int r,int h)
//{
//	if (n == 0)
//	{
//		if (v)return;
//		minS = min(minS, totals);
//	}
//	if (v <= 0)return;
//	//×ªÒÆ
//	for(int i=r;i>=n;i--)
//		for (int j = h; j >= n; j--)
//		{
//			if (n == M) {
//				totals = i * i;
//			}
//
//			if (v >= i * i*j)
//			{
//				
//				if (totals + 2 * i*j + mins[n - 1] >= minS)continue;
//				if (v - i * i*j < minv[n - 1])continue;
//				int maxv;
//				if (!MAXV_[i - 1][j - 1][n - 1])
//					MAXV_[i - 1][j - 1][n - 1] = maxV(i - 1, j - 1, n - 1);
//
//				maxv = MAXV_[i - 1][j - 1][n - 1];
//
//				if (v - i * i*j > maxv)
//					continue;
//				/*if (v - i * i*j > maxV(i - 1, j - 1, n - 1))
//					continue; */
//
//				totals += 2 * i*j;
//				dfs_bc(v - i * i*j, n - 1, i - 1, j - 1);
//				totals -= 2 * i*j;
//			}
//				
//
//		}
//
//
//}
//
//int main_bc()
//{
//
//	cin >> N >>M;
//	mins[0] = 0;
//	minv[0] = 0;
//	memset(MAXV_, 0, sizeof(MAXV_));
//	for (int i = 1; i <= M; i++)
//	{
//		minv[i] = minv[i - 1] + i * i*i;
//		mins[i] = mins[i - 1] + 2 * i*i;
//	}
//	int maxr = sqrt((N - minv[M - 1]) / M);
//	int maxh = (N - minv[M - 1]) / (M*M);
//	minS = 1 << 30;
//	totals = 0;
//	if (maxh >= 1 && maxr >= 1)
//		dfs_bc(N, M, maxr, maxh);
//	if (minS == (1 << 30))
//		cout << 0 << endl;
//	else
//		cout << minS << endl;
//
//	return 0;
//}
//
