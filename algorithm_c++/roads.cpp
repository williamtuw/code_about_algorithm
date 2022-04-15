//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//struct Road
//{
//	int e, l, t;
//};
//int K,N,R;
//vector<vector<Road>> NODES(110);
//int visited[110];
//int minlen=1<<30;
//int sumlen=0;
//int minl[101][10001];
//void dfs_roads(int n,int k)
//{
//	if (n == N)
//	{
//		minlen = min(minlen, sumlen);
//		return ;
//	}
//		
//	if (visited[n])
//		return ;
//	visited[n] = 1;
//	
//	for (int i = 0; i < NODES[n].size(); i++)
//	{
//		Road r = NODES[n][i];
//		if(k<r.t) continue;
//		if (visited[r.e]) continue;
//		if (sumlen + r.l > minlen)continue;
//		if (sumlen + r.l >= minl[r.e][k - r.t])continue;
//		sumlen += r.l;
//		dfs_roads(r.e,k-r.t);
//		sumlen -= r.l;
//		minl[r.e][k - r.t] = sumlen + r.l;
//		
//	}
//	visited[n] = 0;
//	
//}
//
//int main_roads()
//{
//
//	cin >> K>>N>>R;
//	for (int i = 0; i < R; i++)
//	{
//		Road r;
//		int s;
//		cin >> s >> r.e >> r.l >> r.t;
//		if(s!=r.e)
//			NODES[s].push_back(r);
//	}
//	for (int i = 1; i <= N; i++)
//		for (int j = 0; j <= K; j++)
//			minl[i][j] = 1 << 30;
//	memset(visited, 0, sizeof(visited));
//	dfs_roads(1, K);
//	if(minlen < (1<<30))
//		cout << minlen << endl;
//	else
//		cout << -1 << endl;
//		
//	return 0;
//}
//
