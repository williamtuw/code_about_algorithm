#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <winsock.h>
using namespace std;
#pragma comment( lib,"winmm.lib" )

struct Node
{
	int state;
	char c = 0;//上下左右 wsad
	Node* pre = NULL;
	Node(int state, char c, Node* pre) :state(state), c(c), pre(pre) {}
};
DWORD start, end;
char visited[45360];//45360
int S, E;
int FACT[9] = { 0,1,2,6,24,120,720,5040,40320 };
queue<Node> q;

//120 
//345
//678
void output(Node* node) {
	cout << timeGetTime() - start << endl;
	vector<char> result;
	while (node->c)
	{
		result.push_back(node->c);
		node = node->pre;
	}
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << endl;
}
void set_bit(char& byte, int bit)
{
	byte |= 1 << bit;
}
int get_bit(char&byte, int bit)
{
	return (byte >> bit) & 1;
}

int get_num(int state)
{
	char str[10];
	sprintf_s(str, "%09d", state);
	int sum = 0, count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (str[j] < str[i])count++;
		}
		sum += (str[i] - '0' - count)*FACT[8 - i];
		count = 0;
	}
	return sum;
}
int get_visited(int state)
{
	int num = get_num(state);
	return get_bit(visited[num / 8], num % 8);
}

void set_visited(int state)
{
	int num = get_num(state);
	set_bit(visited[num / 8], num % 8);
}
int find_index(int state,char c)
{
	char buf[10];
	sprintf_s(buf, "%09d", state);
	return strchr(buf, c)-buf;
}
void swap(char& c1, char &c2)
{
	char temp = c1;
	c1 = c2;
	c2 = temp;
}
int move(int state, char c)
{
	//上下左右 wsad
	char buf[10];
	sprintf_s(buf, "%09d", state);
	int index_0 = find_index(state,'0');
	switch (c)
	{
	case 'w': swap(buf[index_0], buf[index_0 - 3]); break;
	case 's': swap(buf[index_0], buf[index_0 + 3]); break;
	case 'a': swap(buf[index_0], buf[index_0 - 1]); break;
	case 'd': swap(buf[index_0], buf[index_0 + 1]); break;
	default:
		break;
	}
	return atoi(buf);
}
bool extend(Node* node, char c)
{
	int m_state = move(node->state, c);
	if (m_state == E)
	{
		//输出
		Node* n = new Node(m_state, c,node);
		output(n);
		return true;
	}
	if (!get_visited(m_state))
	{
		set_visited(m_state);
		q.push(Node(m_state, c,node));
	}
	return false;
}
int main_puzzle_e()
{
	cin >> S;
	start = timeGetTime();

	E = 120345678;
	memset(visited, 0, sizeof(visited));
	q.push(Node(S,0,NULL));
	set_visited(S);
	
	while (!q.empty())
	{
		Node* node = new Node(q.front());
		if (node->state == E){
			//输出
			output(node);
			break;
		}
		//空格移上
		if (find_index(node->state,'0')/3 >= 1){
			if(extend(node, 'w')) break;	
		}
		//空格移下
		if (find_index(node->state, '0') / 3 < 2){
			if (extend(node, 's')) break;
		}
		//空格移左
		if (find_index(node->state, '0') % 3 >= 1)
		{
			if (extend(node, 'a')) break;
		}
		//空格移右
		if (find_index(node->state, '0') % 3 < 2)
		{
			if (extend(node, 'd')) break;
		}
		q.pop();
	}
	return 0;
}

