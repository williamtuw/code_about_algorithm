//#include <iostream>
//#include <queue>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//bool visited[100001];
//
//
//struct Node
//{
//	int p, steps;
//	Node(int p, int s) :p(p), steps(s) {}
//};
//
//
//int main_catch_cow()
//{
//	queue<Node> q;
//	cin >> N >> M;
//	q.push(Node(N, 0));
//	memset(visited, 0, sizeof(visited));
//	visited[N] = 1;
//	while (!q.empty())
//	{
//		Node node = q.front();
//		if (node.p  == M)
//		{
//			cout << node.steps << endl;
//			break;
//		}
//		
//		if (node.p > 0 && !visited[node.p - 1])
//		{
//			
//			visited[node.p - 1] = 1;
//			q.push(Node(node.p - 1, node.steps + 1));
//		}
//		if (node.p < 100000 && !visited[node.p + 1])
//		{
//			
//			visited[node.p + 1] = 1;
//			q.push(Node(node.p + 1, node.steps + 1));
//		}
//		if (node.p * 2 <= 100000 && !visited[node.p * 2])
//		{
//			
//			visited[node.p * 2] = 1;
//			q.push(Node(node.p * 2, node.steps + 1));
//		}
//		q.pop();
//
//	}
//
//
//	return 0;
//}
//
