//#include <iostream>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//struct Island
//{
//
//	int x,y;
//	double s,e;
//	bool operator < (const Island& is) { return s < is.s; }
//
//}islands[1001];
//
//int N,D;
//
//int main_install_radar()
//{
//	int case_num = 0,num_radar = 0;
//	bool flag;
//	double ranges, rangee;
//	while (cin >> N >> D)
//	{
//		case_num++;
//		num_radar = 1;	
//		flag = false;
//		if (N == 0 && D == 0)
//			break;
//		for (int i = 0; i < N; i++)
//		{
//			cin >> islands[i].x >> islands[i].y;
//			if (islands[i].y > D)
//			{
//				flag = true;
//			}
//			
//		}
//		if (flag)
//		{
//			cout << "Case " << case_num << ": " << -1 << endl;
//			continue;
//		}
//		for (int i = 0; i < N; i++)
//		{
//			double range = sqrt(D * D - islands[i].y*islands[i].y);
//			islands[i].s = islands[i].x - range;
//			islands[i].e = islands[i].x + range;
//		}
//		sort(islands, islands + N);
//		ranges = islands[0].s, rangee = islands[0].e;
//		for (int i = 1; i < N; i++)
//		{
//			if (islands[i].s > rangee)
//			{
//				num_radar++;
//				ranges = islands[i].s, rangee = islands[i].e;
//			}
//			else
//			{
//				ranges = islands[i].s, rangee = rangee > islands[i].e ? islands[i].e : rangee;
//			}
//		}
//		cout << "Case " << case_num << ": " << num_radar << endl;
//	}
//	
//	return 0;
//}
//
