//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//class Stall
//{
//public:
//	int num, e;
//	Stall(int num,int e):num(num),e(e){}
//};
//struct Cmp
//{
//	bool operator()(const Stall& g, const Stall& g1) { return g.e > g1.e; }
//
//}; 
//
//
//struct Cow
//{
//	int s, e, num_stall;
//	bool operator < (const Cow& g) { return e < g.e; }
//
//
//}cows[50001];
//priority_queue< Stall,vector<Stall>,Cmp> q;
//int N;
//
//int main_stall_reserve()
//{
//	cin >> N;
//	int count = 0;
//	for (int i = 0; i < N; i++)
//		cin >> cows[i].s >> cows[i].e;
//	
//	sort(cows, cows + N);
//	for (int i = 0; i < N; i++)
//	{
//		if (q.empty())
//		{
//			cows[i].num_stall = count;
//			q.push(Stall(count++, cows[i].e));
//		}
//		else
//		{
//			const Stall temp = q.top();
//			if (cows[i].s > temp.e)
//			{
//				cows[i].num_stall = temp.num;
//				q.pop();
//				q.push(Stall(temp.num, cows[i].e));
//			}
//			else
//			{
//				cows[i].num_stall = count;
//				q.push(Stall(count++, cows[i].e));
//			}
//		}
//	}
//	for (int i = 0; i < N; i++)
//		cout << i << cows[i].num_stall << endl;
//	
//
//	return 0;
//}
//
