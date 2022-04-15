//#include <iostream>
//#include <algorithm>
//using namespace std;
//void quick_sort(int arr[], int first, int last, bool inverse = false);
//void swap(int*a, int*b);
//void inverse(int arr[], int first, int last)
//{
//	for (int i = 0; i < (last-first+1) / 2; i++)
//	{
//		swap(arr + i+first, arr + last - i);
//	}
//}
//int inverse_num(int arr[],int first,int last)
//{
//	if (first >= last)
//		return 0;
//	int mid = first + (last - first) / 2, count=0;
//	int lbuf[128],rbuf[128];
//	for (int i = 0; i < mid-first+1; i++)
//	{
//		lbuf[i] = arr[i+first];
//	}
//	for (int i = 0; i < last-mid; i++)
//	{
//		rbuf[i] = arr[i+mid+1];
//	}
//	quick_sort(lbuf, 0, mid - first);
//	quick_sort(rbuf, 0, last-mid-1);
//	inverse(lbuf, 0, mid - first);
//	inverse(rbuf, 0, last - mid - 1);
//	
//	for (int i = 0; i < mid - first + 1; i++)
//	{
//		for (int j = 0; j < last - mid ; j++)
//		{
//			if (lbuf[i] > rbuf[j])
//			{
//				count += last - mid - j;
//				break;
//			}
//		}
//	}
//
//	return inverse_num(arr, first, mid) + inverse_num(arr, mid + 1, last) + count;
//}
//
//void main_inverse()
//{
//	int arr[128], len;
//	while (1)
//	{
//		cin >> len;
//		for (int i = 0; i < len; i++)
//		{
//			cin >> arr[i];
//		}
//		
//		cout << inverse_num(arr, 0, len - 1) << endl;
//	}
//	
//}