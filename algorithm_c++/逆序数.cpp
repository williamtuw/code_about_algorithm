//#include <iostream>
//#include <algorithm>
//using namespace std;
//
////int getInversionNum(int* first, int* last)
////{
////	if (last - first == 1)return 0;
////	int count = 0;
////	int* mid = (last - first) / 2 + first;
////	int* tempL = new int[mid - first];
////	int* tempR = new int[last - mid];
////	memcpy(tempL, first, (mid - first) * sizeof(int));
////	memcpy(tempR, mid, (last - mid) * sizeof(int));
////	sort(tempL, tempL + (mid - first));
////	sort(tempR, tempR + (last - mid));
////	for (int i = 0; i < (mid - first); i++)
////		for (int j = 0; j < (last - mid); j++)
////			if (*(tempL + i) > *(tempR + j))
////			{
////				count++;
////			}
////			else break;
////	delete[] tempL;
////	delete[] tempR;
////	return getInversionNum(first, mid) + getInversionNum(mid, last) + count;
////}
//template <class T>
//int getInversionNum(T* first, T* last)
//{
//	if (last - first == 1)return 0;
//	int count = 0;
//	T* mid = (last - first) / 2 + first;
//	T* tempL = new T[mid - first];
//	T* tempR = new T[last - mid];
//	memcpy(tempL, first, (mid - first) * sizeof(T));
//	memcpy(tempR, mid, (last - mid) * sizeof(T));
//	sort(tempL, tempL + (mid - first));
//	sort(tempR, tempR + (last - mid));
//	for (int i = 0; i < (mid - first); i++)
//		for (int j = 0; j < (last - mid); j++)
//			if (tempL[i] > tempR[j])
//			{
//				count++;
//			}
//			else break;
//	delete[] tempL;
//	delete[] tempR;
//	return getInversionNum(first, mid) + getInversionNum(mid, last) + count;
//}
//
//int main_fmatrix()
//{
//	int n;
//	int arr[100];
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++)cin >> arr[i];
//		cout << getInversionNum(arr, arr + n);
//	}
//	return 0;
//}