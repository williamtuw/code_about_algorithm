//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct DNA
//{
//	int id, inversionNum;
//	char value[50];
//}DNA_SQUENCE[100];
//bool operator < (const DNA& one, const DNA& other)
//{
//	return one.inversionNum < other.inversionNum || !(other.inversionNum < one.inversionNum)&& one.id < other.id;
//}
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
//int getInversionNumByIter(char* value, int len)
//{
//	int count = 0;
//	for (int i = 0; i < len; i++)
//		for (int j = i + 1; j < len; j++)
//			if (value[i] > value[j])count++;
//	return count;
//}
//
//int main_fmatrix()
//{
//	int n,m;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		DNA_SQUENCE[i].id = i;
//		cin >> DNA_SQUENCE[i].value;
//		DNA_SQUENCE[i].inversionNum = getInversionNum(DNA_SQUENCE[i].value, DNA_SQUENCE[i].value + n);
//	}
//	sort(DNA_SQUENCE, DNA_SQUENCE + m);
//	for (int i = 0; i < m; i++)
//		cout << DNA_SQUENCE[i].value << endl;
//
//	return 0;
//}jj