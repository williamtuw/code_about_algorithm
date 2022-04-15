//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//struct ClassWork
//{
//	char name[50];
//	int d, c;
//};
//int getBit(int byte, int where)
//{
//	return byte >> where & 1;
//}
//// bit设为1
//int setBit(int byte, int where)
//{
//	return byte | (1 << where);
//}
//int getPunish(int now, int c, int d)
//{
//	int punish = now + c - d;
//	return punish > 0 ? punish : 0;
//}
//int min_p, MIN_P_ARR[16], P_ARR[16], depth, punish, N, targetState, timeNow[32768];
//int MIN_P[32768];//MIN_P[state]代表到达state时的最小罚时间
//ClassWork classes[16];
////state 的bitx位代表第x作业完成状态
//void dfs(int state)
//{
//	int temp,tempState;
//	if (state == targetState)
//	{
//		if (punish < min_p)
//		{
//			min_p = punish;
//			memcpy(MIN_P_ARR, P_ARR, 4 * N);
//		}
//		else if (punish == min_p)
//		{
//			if (memcmp(MIN_P_ARR, P_ARR, 4 * N) > 0)
//			{
//				memcpy(MIN_P_ARR, P_ARR, 4 * N);
//			}
//		}
//		return;
//	}
//	for (int i = 0; i < N; i++)
//	{
//		if (!getBit(state, i))
//		{
//			temp = getPunish(timeNow[state], classes[i].c, classes[i].d);
//			punish += temp;
//			tempState = setBit(state, i);
//			if (punish <= min_p&&punish<=MIN_P[tempState])
//			{
//				MIN_P[tempState] = punish;
//				P_ARR[depth++] = i;
//				dfs(tempState);
//				depth--;
//			}
//			punish -= temp;
//		}
//	}
//}
//int main_fmatrix()
//{
//	int T, sumTime;
//
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		min_p = 1 << 30;
//		punish = depth = 0;
//		cin >> N;
//		for (int j = 0; j < N; j++)
//		{
//			cin >> classes[j].name >> classes[j].d >> classes[j].c;
//		}
//		//重置MIN_P
//		for (int j = 0; j < (int)pow(2, N); j++)MIN_P[j] = 1 << 30;
//		//计算timeNow
//		timeNow[0] = 0;
//		for (int j = 1; j < pow(2, N); j++)
//		{
//			sumTime = 0;
//			for (int k = 0; k < N; k++)
//			{
//				if (getBit(j, k))
//				{
//					sumTime += classes[k].c;
//				}
//			}
//			timeNow[j] = sumTime;
//		}
//		targetState = (int)pow(2, N) - 1;
//		dfs(0);
//		cout << min_p << endl;
//		for (int j = 0; j < N; j++)
//		{
//			int id = MIN_P_ARR[j];
//			cout << classes[id].name << endl;
//		}
//	}
//
//	return 0;
//}
//
