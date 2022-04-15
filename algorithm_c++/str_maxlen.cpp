//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <stdlib.h>
//using namespace std;
//
//const int MAX = 1000;
//char str1[1000], str2[1000];
//int MAX_LEN[1000][1000];
//
//
//
//
//int main_str_maxlen()
//{
//	for (int i = 0; i < MAX; i++)
//		MAX_LEN[i][0] = 0;
//	for (int i = 0; i < MAX; i++)
//		MAX_LEN[0][i] = 0;
//	while (cin >> str1 >> str2)
//	{
//		int len1 = strlen(str1);
//		int len2 = strlen(str2);
//		
//		for(int i=1;i<=len1;i++)
//			for (int j = 1; j <= len2; j++)
//			{
//				if (str1[i-1] == str2[j-1])
//				{
//					MAX_LEN[i][j] = MAX_LEN[i - 1][j - 1] + 1;
//				}
//				else
//				{
//					MAX_LEN[i][j] = max(MAX_LEN[i - 1][j], MAX_LEN[i][j - 1]);
//				}
//			}
//		cout << MAX_LEN[len1][len2]<<endl;
//	}
//	return 0;
//}
//
