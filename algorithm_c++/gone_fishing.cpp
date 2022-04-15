//#include <iostream>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//int N, H, max_num,cur_total;
//int FI[26],DI[26],TI[25],FI_COPY[26];
//int	max_arr[26];
//int cur_arr[26];
//
//
//
//int sum(int* first, int* last)
//{
//	int summary = 0;
//	while (first != last)
//	{
//		summary += *first;
//		first++;
//	}
//	return summary;
//}
//int cmp(int* a, int* b,int n)
//{
//	return -1 如果 a<b
//	return 0 如果 a=b
//	return 1 如果 a>b
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		if (*a + i < *b + i)return -1;
//		if (*a + i > *b + i)return  1;
//	}
//	return 0;
//
//}
//int main_gone_fishing()
//{
//	int fish_pieces;
//	TI[0] = 0;
//	int cases = 0;
//	while (cin >> N)
//	{
//		cases++;
//		if (N == 0) break;
//		max_num = -1;
//		
//		
//		cin >> H;
//		for (int i = 1; i <= N; i++) cin >> FI[i];
//		for (int i = 1; i <= N; i++) cin >> DI[i];
//		for (int i = 1; i < N; i++) cin >> TI[i];
//
//		for (int i = 1; i <= N; i++)
//		{
//			cur_total = 0;
//			for (int k = 1; k <= N; k++)cur_arr[k] = 0;
//			for (int k = 1; k <= N; k++)FI_COPY[k]=FI[k];
//			fish_pieces = H * 60 / 5 - sum(TI, TI + i);
//			for (int j = 1; j <= fish_pieces;j++)
//			{
//				int* index = max_element(FI_COPY +1, FI_COPY + i +1);
//				cur_total += *index;
//				cur_arr[index - FI_COPY] ++;
//				FI_COPY[index - FI_COPY] = FI_COPY[index - FI_COPY]>DI[index - FI_COPY]? FI_COPY[index - FI_COPY] - DI[index - FI_COPY]:0;
//			}
//			
//			
//			if (cur_total == max_num)
//			{			
//				if(cmp(cur_arr+1,max_arr+1,i)>1)
//					for (int k = 1; k <= N; k++)
//						max_arr[k] = cur_arr[k];
//			}
//			else if(cur_total > max_num)
//			{
//				max_num = cur_total;
//				for (int k = 1; k <= N; k++) max_arr[k] = cur_arr[k];
//			}
//
//		}
//		if (cases != 1)cout << endl;
//		for (int i = 1; i <= N; i++)
//		{
//			cout << max_arr[i] * 5;
//			if (i != N)cout << ", ";
//		}
//		cout << endl << "Number of fish expected: " << max_num << endl;
//		
//		
//	}
//
//	return 0;
//}
//
