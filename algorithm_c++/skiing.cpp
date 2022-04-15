//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//struct  Point
//{
//	int i, j, height;
//};
//const int MAXN = 100;
//int ARRAY[MAXN][MAXN], R, C;
//Point ARR_SORTED[MAXN*MAXN];
//int MAXL[MAXN*MAXN];
//bool point_sort(Point a, Point b) { return a.height < b.height; }
//
//int main_skiing()
//{
//	cin >> R >> C;
//	
//	for (int i = 0; i < R; i++)
//		
//		for (int j = 0; j < C; j++)
//		{
//			cin >> ARRAY[i][j];
//			ARR_SORTED[i*C + j].i = i;
//			ARR_SORTED[i*C + j].j = j;
//			ARR_SORTED[i*C + j].height= ARRAY[i][j];
//		}
//	for (int i = 0; i < R*C; i++)
//		MAXL[i] = 1;
//	sort(ARR_SORTED, ARR_SORTED + R * C,point_sort);
//	//从低到高更新
//	for (int i = 0; i < R*C; i++)
//	{
//
//		//左
//		
//		if (ARR_SORTED[i].j>0 && ARRAY[ARR_SORTED[i].i][ARR_SORTED[i].j-1] < ARR_SORTED[i].height)
//		{
//			MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j] = max(MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j], MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j - 1] + 1);
//		}
//		//上
//		if (ARR_SORTED[i].i > 0 && ARRAY[ARR_SORTED[i].i-1][ARR_SORTED[i].j] < ARR_SORTED[i].height)
//		{
//			MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j] = max(MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j], MAXL[(ARR_SORTED[i].i-1)*C + ARR_SORTED[i].j] + 1);
//		}
//		//右
//		if (ARR_SORTED[i].j < C-1 && ARRAY[ARR_SORTED[i].i][ARR_SORTED[i].j + 1] < ARR_SORTED[i].height)
//		{
//			MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j] = max(MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j], MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j + 1] + 1);
//		}
//		//下
//		if (ARR_SORTED[i].i < R-1 && ARRAY[ARR_SORTED[i].i + 1][ARR_SORTED[i].j] < ARR_SORTED[i].height)
//		{
//			MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j] = max(MAXL[ARR_SORTED[i].i*C + ARR_SORTED[i].j], MAXL[(ARR_SORTED[i].i + 1)*C + ARR_SORTED[i].j] + 1);
//		}
//
//
//	}
//
//
//	cout << *max_element(MAXL, MAXL + R * C)<<endl;
//	return 0;
//}
//
