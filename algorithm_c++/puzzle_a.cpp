//#include <iostream>
//#include <queue>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int PUZZLE[6][6];
//int visited[6][6];
//string result[25];
//int count_ = 0;
//struct Node
//{
//	int i,j;
//	Node* pre=NULL;
//	Node(int i, int j, Node* pre) :i(i), j(j),pre(pre) {}
//};
//
//
//int main_catch_cow()
//{
//	for (int i = 1; i <= 5; i++)
//		for (int j = 1; j <= 5; j++)
//			cin >> PUZZLE[i][j];
//	queue<Node> q;
//	memset(visited, 0, sizeof(visited));
//	q.push(Node(1, 1,NULL));
//	visited[1][1] = 1;
//	
//	while (!q.empty())
//	{
//		Node* node =new Node(q.front());
//
//		if (node->i == 5 && node->j ==5)
//		{
//			//Êä³ö
//			char buf[10];
//			while (node)
//			{
//				sprintf_s(buf, "(%d, %d)", node->i-1, node->j-1);
//				result[count_++] =  string(buf);
//				node = node->pre;
//			}
//			for(int i=count_-1;i>=0;i--)
//				cout << result[i] <<endl;
//			
//			break;
//		}
//		//ÉÏ
//		if (node->i > 1 && !visited[node->i - 1][node->j]&&PUZZLE[node->i - 1][node->j]!= 1)
//		{
//			visited[node->i - 1][node->j] = 1;
//			q.push(Node(node->i - 1, node->j, node));
//		}
//		//ÏÂ
//		if (node->i < 5 && !visited[node->i+1][node->j] && PUZZLE[node->i + 1][node->j] != 1)
//		{
//			visited[node->i + 1][node->j] = 1;
//			q.push(Node(node->i + 1,node->j, node));
//		}
//		//×ó
//		if (node->j > 1 && !visited[node->i][node->j-1] && PUZZLE[node->i][node->j - 1] != 1)
//		{
//			visited[node->i][node->j - 1] = 1;
//			q.push(Node(node->i,node->j - 1, node));
//		}
//		//ÓÒ
//		if (node->j < 5 && !visited[node->i][node->j+1] && PUZZLE[node->i][node->j + 1] != 1)
//		{
//			visited[node->i][node->j + 1] = 1;
//			q.push(Node(node->i,node->j + 1, node));
//		}
//		
//		q.pop();
//
//	}
//
//
//	return 0;
//}
//
