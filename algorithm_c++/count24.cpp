//// 输入4个小于10的数判断是否能构成表达式值为24
//#include <math.h>
//#include <iostream>
//using namespace std;
//#define EPS 1e-6
//bool is_zero(double value)
//{
//	if (fabs(value) < EPS)return true;
//	return false;
//}
//
//bool count24(double num[], int n)
//{
//	if (n == 1) {
//		if (is_zero(num[0] - 24))
//			return true;
//		return false;
//	}
//	double buf[5];
//	
//	for (int i = 0; i < n; i++)
//	{
//		//任意挑两个计算
//		for (int j = i + 1; j < n; j++)
//		{
//			//将没有挑中的保存起来
//			int count = 0;
//			for (int k = 0; k < n; k++)
//			{			
//				if (k != i && k != j)
//				{
//					buf[count++] = num[k];
//				}
//			}
//			buf[count] = num[i] + num[j];
//			if (count24(buf, n - 1))
//				return true;
//			buf[count] = num[i] - num[j];
//			if (count24(buf, n - 1))
//				return true;
//			buf[count] = num[j] - num[i];
//			if (count24(buf, n - 1))
//				return true;
//			buf[count] = num[i] * num[j];
//			if (count24(buf, n - 1))
//				return true;
//			if (!is_zero(num[i])) {
//				buf[count] = num[j] / num[i];
//				if (count24(buf, n - 1))
//					return true;
//			}
//			if (!is_zero(num[j])) {
//				buf[count] = num[i] / num[j];
//				if (count24(buf, n - 1))
//					return true;
//			}
//		}
//	}
//	return false;
//}
//
//void main_count24()
//{
//	double buf[4];
//	for (int i = 0; i < 4; i++)
//	{
//		cin >> buf[i];
//	}
//	cout<<count24(buf, 4);
//}