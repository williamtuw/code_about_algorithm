//#include <iostream>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//int F[6000];
//
//int min(int a, int b)
//{
//	return a < b ? a : b;
//}
//
//
//
//int main_humble_num()
//{
//	int i,a, b, c, d, n;
//	F[1] = 1;
//	a = b = c = d = 1;
//	for (i = 2; i <= 5842; i++)
//	{
//		F[i] = min(F[a] * 2, min(F[b] * 3, min(F[c] * 5, F[d] * 7)));
//		if (F[i] == F[a] * 2)a++;
//		if (F[i] == F[b] * 3)b++;
//		if (F[i] == F[c] * 5)c++;
//		if (F[i] == F[d] * 7)d++;
//	}
//	while (cin >> n, n)
//	{
//		if ((n % 10 == 1) && n != 11)cout << "The " << n << "st humble number is " << F[n] << "." << endl;
//		else if ((n % 10 == 2) && n != 12)cout << "The " << n << "nd humble number is " << F[n] << "." << endl;
//		else if ((n % 10 == 3) && n != 13)cout << "The " << n << "rd humble number is " << F[n] << "." << endl;
//		else cout << "The " << n << "th humble number is " << F[n] << "." << endl;
//	}
//
//	return 0;
//}
//
