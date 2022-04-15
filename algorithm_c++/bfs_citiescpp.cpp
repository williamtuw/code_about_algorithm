//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <queue>
//struct Node
//{
//	int i, j;
//	Node(int i,int j):i(i),j(j){}
//};
//
//using namespace std;
//int N, M;
//vector<vector<int>> Roads(49);
//bool visited[50][50];
//
//
//int main_humble_num()
//{
//	queue<Node> q;
//	int from, to,flag;
//	cin >> N >> M;
//	memset(visited, 0, sizeof(visited));
//	for (int i = 0; i < M; i++)
//	{
//		cin >> from >> to;
//		Roads[from].push_back(to);
//	}
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//		{
//			flag = 0;
//			memset(visited, 0, sizeof(visited));
//			q = queue<Node>();
//			q.push(Node(i, j));
//			visited[i][j] = true;
//			while (!q.empty())
//			{
//				Node node = q.front();
//				for (vector<int>::iterator iter = Roads[node.i].begin(); iter != Roads[node.i].end(); iter++)
//				{
//					if (*iter == node.j)
//					{
//						//’“µΩ
//						flag = 1;
//						break;
//					}
//				}
//
//				for (vector<int>::iterator iter = Roads[node.i].begin(); iter != Roads[node.i].end(); iter++)
//				{
//					
//					if (*iter == node.j)
//					{
//						//’“µΩ
//						flag = 1;
//						break;
//					}
//					if (visited[*iter][node.j])continue;
//					else
//					{
//						visited[*iter][node.j] = true;
//						q.push(Node(*iter, node.j));
//					}
//				}
//				if(flag)break;
//				q.pop();
//			}	
//			if (flag)cout << 1;
//			else cout << 0;
//			if (j == N - 1)cout << endl;
//			else cout << " ";
//		}
//	
//	return 0;
//}
//
