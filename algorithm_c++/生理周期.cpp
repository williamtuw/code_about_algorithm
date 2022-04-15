//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main_fmatrix()
//{
//	//体力，感情，智力 生理周期分别为 23 28 33
//	int p, e, i,d,j,t=1;
//	while (cin >> p >> e >> i >> d)
//	{
//		if (p == -1)break;
//		if (d >= i)j = d + 33 - (d - i) % 33;
//		else j = d + (i - d) % 33;
//		while (true)
//		{
//			if (abs(j - p) % 23 == 0 && abs(j - e) % 28 == 0)
//			{
//				printf("Case %d: the next triple peak occurs in %d days.\n", t, j - d);
//				break;
//			}
//			j += 33;
//		}
//		t++;
//	}
//	return 0;
//}
//
