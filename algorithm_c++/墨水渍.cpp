//#include <iostream>
//#include <cstring>
//using namespace std;
//
//
//int R, C, N;
//int matrix[31][31] = { 0 };//1¼ÆÊý
//int base_matrix[8][8];
//void drop(int ri, int ci)
//{
//	int sum;
//	for (int i = 1; i <= 4; i++)
//		for (int j = (5 - i); j <= (3 + i); j++)
//			if ((ri + i - 4) > 0 && (ci + j - 4) > 0 && (ri + i - 4) <= R && (ci + j - 4) <= C)
//			{
//				sum = base_matrix[i][j] + matrix[ri + i - 4][ci + j - 4];
//				matrix[ri + i - 4][ci + j - 4] = sum > 9 ? 9 : sum;
//			}
//	for (int i = 5; i <= 7; i++)
//		for (int j = (i - 3); j <= (11 - i); j++)
//			if ((ri + i - 4) > 0 && (ci + j - 4) > 0 && (ri + i - 4) <= R && (ci + j - 4) <= C)
//			{
//				sum = base_matrix[i][j] + matrix[ri + i - 4][ci + j - 4];
//				matrix[ri + i - 4][ci + j - 4] = sum > 9 ? 9 : sum;
//			}
//	
//}
//void set_base_matrix()
//{
//	for (int i = 1; i <= 4; i++)
//		for (int j = (5 - i); j <= (3 + i); j++)
//			base_matrix[i][j] = base_matrix[i - 1][j] + 1;
//	for (int i = 5; i <= 7; i++)
//		for (int j = (i-3); j <= (11-i); j++)
//			base_matrix[i][j] = base_matrix[i - 1][j] - 1;
//}
//int main_humble_num()
//{
//	set_base_matrix();
//	int ri,ci;
//	
//	while (cin >> R >> C >> N)
//	{
//		memset(matrix, 0, sizeof(matrix));
//		for (int j = 0; j < N; j++)
//		{
//			cin >> ri >> ci;
//			drop(ri, ci);
//		}
//		for (int j = 1; j <= R; j++)
//		{
//			for (int k = 1; k <= C; k++)cout << matrix[j][k];
//			cout << endl;
//		}
//	}
//
//	return 0;
//}
//
