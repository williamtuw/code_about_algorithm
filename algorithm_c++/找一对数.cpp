//#include <iostream>
//#include <algorithm>
//using namespace std;
//void swap(int*a, int*b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void quick_sort(int arr[], int first, int last, bool inverse = false)
//{
//	
//	if (first >= last)
//		return;
//	int k = arr[first];
//	int i = first, j = last;
//	while (i != j)
//	{
//		while (arr[j] >= k &&j > i)
//			j--;
//		swap(arr + i, arr + j);
//		while (arr[i]  <= k &&i < j)
//			i++;
//		swap(arr + i, arr + j);
//	}
//	quick_sort(arr, first, i - 1);
//	quick_sort(arr, i + 1, last);
//	
//}
//
//int binarysearch(int arr[], int first, int last, int value)
//{
//	int a = first, b = last;
//	int mid = a + (b - a) / 2;
//	while (a<=b)
//	{
//		if (arr[mid] == value) {
//			return mid;
//		}
//		else if (arr[mid] > value)
//		{
//			b = mid-1;
//		}
//		else
//		{
//			a = mid+1;
//		}
//		mid = a + (b - a) / 2;
//	}
//	return -1;
//}
//
//
//void main_find_double()
//{
//	int arr[128],n,m,index;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	quick_sort(arr,0,n-1);
//	for (int i = 0; i < n; i++)cout << arr[i];
//	for (int i = 0; i < n; i++)
//	{
//		int value = m - arr[i];
//
//		if ((index=binarysearch(arr, i + 1, n - 1, value)) != -1)
//		{
//			cout << arr[i] << " " << arr[index] << endl;
//			cout << "找到啦!" << endl;
//			return;
//		}
//
//	}
//	cout << "没有找到!" << endl;
//}