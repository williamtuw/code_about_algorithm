//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//struct Movie
//{
//	int s, e;
//	bool operator < (const Movie& g) { return e < g.e; }
//};
//int N;
//Movie movies[100];
//int main_movie_feast()
//{
//	while(cin >> N)
//	{
//		if (!N)break;
//		for (int i = 0; i < N; i++) {
//			cin >> movies[i].s >> movies[i].e;
//		}
//		sort(movies, movies + N);
//		int count = 0, end = 0;
//		for (int i = 0; i < N; i++)
//		{
//			if (movies[i].s >= end)
//			{
//				count++;
//				end = movies[i].e;
//			}
//		}
//		cout << count << endl;
//	}
//	
//	
//	return 0;
//}
//
