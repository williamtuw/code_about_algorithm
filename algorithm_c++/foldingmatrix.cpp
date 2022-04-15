//#include <iostream>
//#include <cstring>
//using namespace std;
//int fmatrix[1001][1001];
//
//
//
//int main_fmatrix()
//{
//	int a, n, direction,num,last;
//	
//	cin >> a >> n >> direction;
//	num=last = a;
//	int gap = direction == 2 ? -1 : 1;
//	
//	for (int i = 0; i < n; i++)
//	{
//		
//		
//		for (int j = 0; j < i + 1; j++)
//		{
//			fmatrix[j][i] = num;
//			num += gap;
//		}
//		for (int k = i-1; k >=0; k--)
//		{
//			fmatrix[i][k] = num;
//			num += gap;
//		}
//		if (gap == -1) {
//			num = last + (i + 1) * 2 + 1;
//			last = num;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%4d", fmatrix[i][j]);
//		}
//		cout << endl;
//	}
//		
//			
//	return 0;
//}
//
