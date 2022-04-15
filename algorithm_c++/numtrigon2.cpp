//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define MAX 101;
//int ARR[100][100];
//int N;
//int maxsum2()
//{
//
//	for(int i=N-2;i>=0;i--)
//		for (int j = 0; j < i+1; j++)
//		{
//			ARR[N - 1][j] = ARR[i][j] + max(ARR[N - 1][j], ARR[N - 1][j + 1]);
//		}
//	return ARR[N - 1][0];
//
//	
//}
//
//int main_nt()
//{
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < i + 1; j++)
//			cin >> ARR[i][j];
//	cout << maxsum2() << endl;
//	
//	return 0;
//}
//
