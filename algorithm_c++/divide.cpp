////
//
//#include <iostream>
//using namespace std;
//
//int count_division(int m, int n)
//{
//	if (m == 0)
//		return 1;
//	if (n == 0)
//		return 0;
//	if (n > m)
//		return count_division(m, m);
//	
//
//	return count_division(m, n - 1) + count_division(m - n, n);
//
//	
//}
//void main_divide()
//{
//	int m, n;
//	cin >> m >> n;
//	cout << count_division(m, n);
//}
