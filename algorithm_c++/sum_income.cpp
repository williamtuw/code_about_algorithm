//#include <iostream>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//struct Data
//{
//	int id;
//	int sumIncome;
//	int n;
//}ARR[60];
//
//int NUMMAX = 1000000007;
//
//bool comByN(const Data& f, const Data& s)
//{
//	return f.n < s.n;
//}
//bool comById(const Data& f, const Data& s)
//{
//	return f.id < s.id;
//}
//
//int main_fmatrix()
//{
//	int T,a=1,b=1,index=0,sum=1,temp,num_p;
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> ARR[i].n;
//		ARR[i].id = i+1;
//	}
//	sort(ARR, ARR + T, comByN);
//	num_p = 1;
//	for (int i = 1; i <= ARR[T - 1].n; i++)
//	{
//		if (ARR[index].n == i)
//		{
//			ARR[index].sumIncome = sum;
//			index++;
//		}
//		temp = b;
//		b = (a + b)%NUMMAX;
//		a = temp;
//		num_p = (num_p * 2)%NUMMAX;
//		sum = sum + (num_p * a)%NUMMAX;
//		sum %= NUMMAX;
//		//cout << sum << endl;
//		/*if (sum <= 0)
//			cout << sum << endl;*/
//		
//	}
//	sort(ARR, ARR + T, comById);
//	for (int i = 0; i < T; i++)cout << "Case " << ARR[i].id << ": " << ARR[i].sumIncome << endl;
//
//
//	return 0;
//}
//
