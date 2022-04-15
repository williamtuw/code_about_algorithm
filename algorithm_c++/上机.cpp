//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int main_fmatrix()
//{
//	int n, a[10001], b[10001], c[10001];
//	int dp[10001][4];
//	cin >> n;
//	for (int i = 1; i <= n; i++)cin >> a[i];
//	for (int i = 1; i <= n; i++)cin >> b[i];
//	for (int i = 1; i <= n; i++)cin >> c[i];
//	memset(dp, -1, sizeof(dp));
//	dp[1][0] = a[1];
//	dp[1][2] = b[1];
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i][0] = max(dp[i - 1][2], dp[i - 1][3]) + a[i];
//		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];
//		dp[i][2] = max(dp[i - 1][3], dp[i - 1][2]) + b[i];
//		dp[i][3] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
//	}
//	cout << max(dp[n][0], dp[n][1]) << endl;
//	
//	return 0;
//}
//
