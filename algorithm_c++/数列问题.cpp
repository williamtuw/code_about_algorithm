//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int ARR[100001];
//int MAX_W[100001];
//int MIN_L[100001];
//
//
//int main_fmatrix()
//{
//	int T, N, M,flag,x,min_value,max_w,i,j,k;
//	cin >> T;
//	for ( i = 0; i < T; i++)
//	{
//		memset(MIN_L, (int)-1e6, sizeof(MIN_L));
//		
//		cin >> N >> M;
//		for ( j = 1; j <= N; j++)
//			cin >> ARR[j];
//
//		º∆À„
//		for ( j = 1; j <= N; j++)
//		{
//			min_value = ARR[j];
//			MIN_L[1] = max(MIN_L[1], min_value);
//			for ( k = 2; k <= N - j + 1; k++)
//			{
//				int temp = k * min_value;
//				if (ARR[j + k - 1] >= min_value)
//					max_w = temp;
//				else
//				{
//					min_value = ARR[j + k - 1];
//					max_w = max(temp, max_w);
//				}
//				MIN_L[k] = max(MIN_L[k], temp);
//			}
//		}
//		MAX_W[N] = MIN_L[N];
//		for ( j = N-1; j > 0; j--)
//		{
//			MAX_W[j] = max(MAX_W[j], MAX_W[j + 1]);
//		}
//		for ( j = 1; j <= M; j++)
//		{
//			
//			cin >> flag >> x;
//
//			if (flag == 1)
//			{
//				if(x>N)cout << -1 << endl;
//				else
//				cout << MAX_W[x] << endl;
//			}
//			else
//			{
//				for ( k = 1; k <= N; k++)
//				{
//					if (MIN_L[k] >= x)
//					{
//						cout << k << endl;
//						
//						break;
//					}
//					
//				}
//				if(k==N+1)cout << -1 << endl;
//			}
//		}
//
//
//
//	}
//
//
//	return 0;
//}
//
