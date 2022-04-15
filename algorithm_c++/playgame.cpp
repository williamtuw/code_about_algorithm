//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//vector<int> arr;
//
//int main_humble_num()
//{
//	int T, n, m,num,temp,flag;
//	vector<int>::iterator iter;
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		arr = vector<int>();
//		cin >> n >> m;
//		for (int j = 0; j < n; j++)
//		{
//			cin >> num;
//			arr.push_back(num);
//		}
//		for (int k = 1; k <= m; k++)
//		{
//			//Å¼shouÆæÎ²
//			if ((k - 1) % n == 0)flag = 1;
//				temp = k % n ? k % n : n;
//				iter = find(arr.begin(), arr.end(), temp);
//				arr.erase(iter);
//				if (flag % 2)
//				{
//					arr.push_back(temp);
//				}
//				else
//				{
//					arr.insert(arr.begin(), temp);
//
//				}
//				flag ++ ;
//		}
//
//		for (iter = arr.begin(); iter != arr.end(); iter++)
//		{
//			cout << *iter;
//			if (iter == --arr.end())cout << endl;
//			else cout << " ";
//			
//		}
//	}
//	
//	return 0;
//}
//
