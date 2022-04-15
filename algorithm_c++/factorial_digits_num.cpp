//#include <cmath>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Item
//{
//	int id, n;
//	int result;
//};
//vector<Item> items;
//bool cmpById(Item item1, Item item2)
//{
//	return item1.id < item2.id;
//}
//bool cmpByN(Item item1, Item item2)
//{
//	return item1.n < item2.n;
//}
//int main_fmatrix()
//{
//	int T, index = 0;
//	double sum = 0;
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		Item item;
//		cin >> item.n;
//		item.id = i;
//		items.push_back(item);
//	}
//	sort(items.begin(), items.end(), cmpByN);
//	int maxN = items[items.size() - 1].n;
//	for (int i = 1; i <= maxN; i++)
//	{
//		sum += log10(i);		
//		while (index < T&&i == items[index].n)items[index++].result = (int)sum + 1;
//	}
//	sort(items.begin(), items.end(), cmpById);
//	for (int i = 0; i < T; i++)cout << items[i].result << endl;
//	return 0;
//	/*int n, x;
//	double sum;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		sum = 0;
//		cin >> x;
//		for (int j = x; j >= 1; j--)
//		{
//			sum += log10(j);
//		}
//		cout << (int)sum + 1 << endl;
//	}
//	return 0;*/
//}