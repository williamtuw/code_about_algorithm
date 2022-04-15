//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int ARR[1000];
//int MAX_LEN[1000];
//int N;
//
//
//int maxlen()
//{
//	int max_len = 1;
//	MAX_LEN[N - 1] = 1;
//	for (int i = N - 2; i >= 0; i--)
//	{
//		MAX_LEN[i] = 1;
//		for (int j = i + 1; j < N; j++)
//		{
//			if (ARR[j] > ARR[i])
//			{
//				MAX_LEN[i] = max(MAX_LEN[i], MAX_LEN[j]+1);
//			}
//		}
//		max_len = max(max_len, MAX_LEN[i]);
//	}
//	return max_len;
//}
//
//int main_maxlen()
//{
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//			cin >> ARR[i];
//	cout << maxlen() << endl;
//	return 0;
//}
//
