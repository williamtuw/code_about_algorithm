//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//struct Gift
//{
//	int v, w;
//	double p;
//	bool operator < (const Gift& g){ return p > g.p; }
//};
//int N, W;
//Gift gift[101];
//int main_clau_gift()
//{
//	cin >> N >> W;
//	for (int i = 1; i <= N; i++) {
//		cin >> gift[i].v >> gift[i].w;
//		gift[i].p = (double)gift[i].v / gift[i].w;
//	}
//	sort(gift+1, gift + N+1);
//	int rest = W,index = 1;
//	double totalv = 0;
//	while (rest>0)
//	{
//		totalv += (gift[index].w >= rest ? rest * gift[index].p : gift[index].v);
//		rest -= gift[index].w;
//		index++;
//	}
//	printf("%.1lf\n", totalv);
//	return 0;
//}
//
