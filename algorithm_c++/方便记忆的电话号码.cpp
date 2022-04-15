//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cmath>
//using namespace std;
//
//int NUM[10000000] = {0};
//
//int parse(string raw)
//{
//	int count = 0,result=0;
//	for (int i = raw.length()-1; i >=0 ; i--)
//	{
//		if (isdigit(raw[i]))
//		{
//			result += (int)pow(10, count)* (raw[i] - '0');
//			count++;
//		}
//		else if(isalpha(raw[i]))
//		{
//			if (raw[i] >= 'A'&&raw[i] <= 'P')
//			{
//				result += (int)pow(10, count)*((raw[i] - 'A') / 3 + 2);
//				count++;
//			}
//			else
//			{
//				result += (int)pow(10, count)*((raw[i] - 'Q') / 3 + 7);
//				count++;
//			}
//		}
//		if (count >= 7)break;
//
//	}
//	return result;
//}
//int main_fmatrix()
//{
//	int n;
//	string easyNum;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> easyNum;
//		NUM[parse(easyNum)]++;
//	}
//	bool flag = true;
//	for (int i = 0; i < 10000000; i++)
//	{
//		if (NUM[i] >= 2)
//		{
//			printf("%03d-%04d %d\n", i / 10000, i % 10000, NUM[i]);
//				flag = false;
//		}
//	}
//	if (flag)cout << "No duplicates." << endl;
//	return 0;
//}
//
