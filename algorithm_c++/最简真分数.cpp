//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//struct Fraction
//{
//	//a分子,b分母
//	int a, b;
//	Fraction(int a, int b) :a(a), b(b) {}
//	Fraction(){}
//	bool operator < (const Fraction& other)
//	{
//		return (double)a / b < (double)other.a / other.b;
//	}
//};
//Fraction SQ[3010];//1计数
//int count_ = 0;
//bool is_easiest(int a, int b)
//{
//	int r;
//	if (a < b)
//	{
//		 r = a, a = b, b = r;
//	}
//	while (b) { r = a % b; a = b; b = r; }
//	if (a == 1)return true;
//	return false;
//}
//
//int main_humble_num()
//{
//	int a, b, k;
//	cin >> a >> b >> k;
//	for(int i=a;i<=b;i++)
//		for (int j = 1; j < i; j++)
//		{
//			if (is_easiest(j, i))
//				SQ[count_++] = Fraction(j, i);
//		}
//	sort(SQ, SQ + count_);
//	printf("n=%d\nThe %d Item=%d/%d\n", count_, k, SQ[k - 1].a, SQ[k - 1].b);
//	return 0;
//}
//
