//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//struct Point
//{
//	int i, j;
//};
//int visited[6][6];
//int ARRAY[6][6];
//int R, C;
//Point S, E;
//vector<string> PATHS;
//int depth;
//char path[36];
//
//a、b、c、d分别表示上、下、左、右。
//bool function(const string& str1, const string& str2)
//{
//	if (str1.length() != str2.length())return str1.length() < str2.length();
//	return str1 < str2;
//
//}
//void dfs_puzzle(int i, int j)
//{
//	if (i == E.i&&j == E.j)
//	{
//		保存路径
//			PATHS.push_back(string(path));
//		return;
//	}
//
//	if (visited[i][j])
//		return;
//	visited[i][j] = 1;
//	对边进行探索
//		上
//		if (i > 1 && ARRAY[i - 1][j] != 'W' && !visited[i - 1][j])
//		{
//			path[depth++] = 'a';
//			path[depth] = 0;
//			dfs_puzzle(i - 1, j);
//			depth--;
//		}
//	下
//		if (i < R && ARRAY[i + 1][j] != 'W' && !visited[i + 1][j])
//		{
//			path[depth++] = 'b';
//			path[depth] = 0;
//			dfs_puzzle(i + 1, j);
//			depth--;
//		}
//	左
//		if (j > 1 && ARRAY[i][j - 1] != 'W' && !visited[i][j - 1])
//		{
//			path[depth++] = 'c';
//			path[depth] = 0;
//			dfs_puzzle(i, j - 1);
//			depth--;
//		}
//	右
//		if (j < C && ARRAY[i][j + 1] != 'W' && !visited[i][j + 1])
//		{
//			path[depth++] = 'd';
//			path[depth] = 0;
//			dfs_puzzle(i, j + 1);
//			depth--;
//		}
//
//
//	visited[i][j] = 0;
//
//}
//
//int main_puzzle()
//{
//
//
//
//
//	while (cin >> R >> C)
//	{
//		memset(visited, 0, sizeof(visited));
//		depth = 0;
//		PATHS.clear();
//		for (int i = 1; i <= R; i++)
//			for (int j = 1; j <= C; j++)
//			{
//				char c;
//				cin >> c;
//				if (c == 'S')
//				{
//					S.i = i;
//					S.j = j;
//				}
//				if (c == 'E')
//				{
//					E.i = i;
//					E.j = j;
//				}
//				ARRAY[i][j] = c;
//			}
//
//		dfs_puzzle(S.i, S.j);
//		这里输出结果
//			cout << PATHS.size() << endl;
//		sort(PATHS.begin(), PATHS.end(), function);
//		for (int i = 0; i < PATHS.size(); i++)
//		{
//			cout << PATHS[i] << endl;
//		}
//
//	}
//
//
//	return 0;
//}
//
