//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//
//int N;
//int visited[30][60];
//
//
//
//int ways(int i, int j, int n)
//{
//	int ways_=0;
//	if (n == 0)return 1;
//	visited[i][j] = 1;
//	if (!visited[i + 1][j])ways_ += ways(i + 1, j, n - 1);
//	if (!visited[i][j+1])ways_ += ways(i, j+1, n - 1);
//	if (!visited[i][j-1])ways_ += ways(i, j-1, n - 1);
//	
//	visited[i][j] = 0;
//	return ways_;
//}
//
//int main_castle()
//{
//
//	cin >> N;
//	memset(visited, 0, sizeof(visited));
//	cout << ways(0,25,N) << endl;
//	return 0;
//}
//
