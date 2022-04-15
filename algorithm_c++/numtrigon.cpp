//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define MAX 101;
//int ARR[101][101];
//int MAXSUM[101][101];
//int N;
//int maxsum(int i, int j)
//{
//	if (MAXSUM[i][j] != -1)
//		return MAXSUM[i][j];
//	if (i == N - 1)
//	{ 
//		return ARR[i][j]; 
//	}	
//	else
//	{
//		return ARR[i][j] + max(maxsum(i + 1, j), maxsum(i + 1, j + 1));
//	}
//}
//
//int main_nt()
//{
//	
//	cin >> N;
//	for (int i = 0; i < 101; i++)
//		for (int j = 0; j < i+1; j++)
//			MAXSUM[i][j] = -1;
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < i+1; j++)
//			cin >> ARR[i][j];
//	cout << maxsum(0, 0) << endl;
//	return 0;
//}
//
