//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define EXCEPT int(1e6);
//
//
//int W, H, M;
//int MINSQ[21][21][21];
//
//int main_mins()
//{
//	//递推公式 minsq(w,h,m) = min(sv,sh)
//	//sv = min{si,i=1,2,...w-1}si表示左边切成w为i的minsq
//	//si = min{sik,k=0,1,2,..m-1} sik表示左边切k刀的minsq
//	//sik = max(minsq(i,h,k),minsq(w-i,h,m-1-k))
//	//sh = min{si,i=1,2,...h-1}si表示上半块切成h为i的minsq
//	//si = min{sik,k=1,2,..m-2} sik表示上半块切k刀的minsq
//	//sik = max(minsq(w,i,k),minsq(w,h-i,m-1-k))
//
//	cin >> W >> H >> M;
//	for (int i = 0; i <= H; i++)
//		for (int j = 0; j <= M; j++)
//			MINSQ[0][i][j] = EXCEPT;
//	for (int i = 0; i <= W; i++)
//		for (int j = 0; j <= M; j++)
//			MINSQ[i][0][j] = EXCEPT;
//	for (int i = 0; i <= W; i++)
//		for (int j = 0; j <= H; j++)
//			MINSQ[i][j][0] = i*j;
//	for(int i=1;i<=W;i++)
//		for (int j = 1; j <= H; j++)
//			for (int k = 1; k <= M-1; k++)
//			{
//				MINSQ[i][j][k] = EXCEPT;
//				//sv
//				for (int m = 1; m < i; m++)
//				{
//					//si
//					for (int n = 0; n <= k - 1; n++)
//					{
//						MINSQ[i][j][k] = min(MINSQ[i][j][k], max(MINSQ[m][j][n], MINSQ[i-m][j][k-1-n]));
//					}
//				}
//				//sh
//				for (int m = 1; m < j; m++)
//				{
//					//si
//					for (int n = 0; n <= k - 1; n++)
//					{
//						MINSQ[i][j][k] = min(MINSQ[i][j][k], max(MINSQ[i][m][n], MINSQ[i][j-m][k-1-n]));
//					}
//				}
//				//minsq(w,h,m) = min(sv,sh)
//			}
//	
//	cout << MINSQ[W][H][M - 1]<<endl;
//	return 0;
//}
//
