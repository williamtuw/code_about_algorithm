//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//int getBit(int byte, int where)
//{
//	return byte >> where & 1;
//}
//// bit设为1
//int setBit(int byte, int where)
//{
//	return byte | (1 << where);
//}
//
//int max_value, MAX_VALUE_SQU[16], squence[16], depth, value, N, targetState;
//int MAX_VALUE[32768];//MAX_VALUE[state]代表到达state时的最大收益
//int ARRAY[16][16];//ARRAY[i][j]第i个藏宝图的第j天收益
////state 的bitx位代表第x藏宝图完成状态
//int getTrueAmount(int byte)
//{
//	int amount = 0;
//	for (int i = 0; i < N; i++)
//	{
//		if (byte & 1)amount++;
//		byte >>= 1;
//	}
//	return amount;
//}
//void dfs(int state)
//{
//	int  tempState;
//	if (state == targetState)
//	{
//		if (value > max_value)
//		{
//			max_value = value;
//			memcpy(MAX_VALUE_SQU, squence, 4 * N);
//		}
//		else if (value == max_value)
//		{
//			if (memcmp(MAX_VALUE_SQU, squence, 4 * N) > 0)
//			{
//				memcpy(MAX_VALUE_SQU, squence, 4 * N);
//			}
//		}
//		return;
//	}
//	for (int i = 0; i < N; i++)
//	{
//		if (!getBit(state, i))
//		{
//			tempState = setBit(state, i);
//			value += ARRAY[i][getTrueAmount(tempState)-1];
//			if (value >= MAX_VALUE[tempState])
//			{
//				MAX_VALUE[tempState] = value;
//				squence[depth++] = i;
//				dfs(tempState);
//				depth--;
//			}
//			value -= ARRAY[i][getTrueAmount(tempState)-1];
//		}
//	}
//}
//int main_fmatrix()
//{
//	max_value = -1;
//	value = depth = 0;
//	cin >> N; 
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			cin >> ARRAY[i][j];
//
//	//重置MAX_VALUE
//	for (int j = 0; j < (int)pow(2, N); j++)MAX_VALUE[j] = -1;
//	
//	targetState = (int)pow(2, N) - 1;
//	dfs(0);
//	cout << max_value << endl;
//	for (int j = 0; j < N; j++)
//	{
//		cout << MAX_VALUE_SQU[j]+1 << endl;
//	}
//	return 0;
//}
//
