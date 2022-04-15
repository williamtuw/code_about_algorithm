//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cmath>
//using namespace std;
//
//解题方法 状压dp
//题目要求 min_p[2^N - 1]
//state 的bitx位代表第x作业完成状态
//递推式 //状态转移方程
//min_p[state] = min{min_p[state~]+ p}
///*
//递推方向 state 0 -> 2^N - 1
//时间复杂度
//N*(2^N - 1 )
//空间复杂度
//one state 2bytes
//states count 2^N
//*/
//0计数
//int getBit(int byte, int where)
//{
//	return byte >> where & 1;
//}
//0计数 bit设为0
//int setBit(int byte, int where)
//{
//	return byte & ~(1 << where);
//}
//int min_p[32768];//min_p[state]代表state状态下的最小punish
//int timeNow[32768];//timeNow[state]代表到达state状态所花掉的时间
//int N;//作业数
//int result[16], depth;//结果序列
//int optimalResult[16];
//struct ClassWork
//{
//	char name[50];
//	int d, c;
//};
//ClassWork classworks[16];//0计数
//int getPunish(int now, int c, int d)
//{
//	int punish = now + c - d;
//	return punish > 0 ? punish : 0;
//}
//找到最优解
//void getOptimalResultDFS(int state, int n)
//{
//	int temp;
//	if (n == 0)
//	{
//		if(memcmp(result, optimalResult, 4 * N) < 0)memcpy(optimalResult, result, 4 * N);
//		return;
//	}
//	for (int k = 0; k < N; k++)
//	{
//		if (getBit(state, k))
//		{
//			temp = setBit(state, k);
//			if (min_p[state] == min_p[temp] + getPunish(timeNow[temp], classworks[k].c, classworks[k].d))
//			{
//				result[N - 1 - depth++] = k;
//				getOptimalResultDFS(temp, n - 1);
//				depth--;
//			}
//		}
//	}
//}
//int main_fmatrix()
//{
//	int T, temp, sumTime, state;
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> N;
//		重置min_p
//		for (int j = 0; j < pow(2, N); j++)min_p[j] = 1 << 30;
//		
//		depth = 0;
//		for (int j = 0; j < N; j++)optimalResult[j] = 16;
//		读入input
//		for (int j = 0; j < N; j++)
//		{
//			cin >> classworks[j].name >> classworks[j].d >> classworks[j].c;
//		}
//		设置边界值
//		min_p[0] = 0;
//		timeNow[0] = 0;
//		计算时间timeNow[state]
//		for (int j = 1; j < pow(2, N); j++)
//		{
//			sumTime = 0;
//			for (int k = 0; k < N; k++)
//			{
//				if (getBit(j, k))
//				{
//					sumTime += classworks[k].c;
//				}
//			}
//			timeNow[j] = sumTime;
//		}
//		开始递推
//		for (int j = 1; j < pow(2, N); j++)
//		{
//			for (int k = 0; k < N; k++)
//			{
//				if (getBit(j, k))
//				{
//					temp = setBit(j, k);
//					min_p[j] = min(min_p[j], min_p[temp] + getPunish(timeNow[temp], classworks[k].c, classworks[k].d));
//				}
//			}
//		}
//
//		倒叙恢复得到最佳顺序
//		state = (int)pow(2, N) - 1;
//		getOptimalResultDFS(state, N);
//		输出结果
//		cout << min_p[(int)pow(2, N) - 1] << endl;
//		for (int j = 0; j < N; j++)
//		{
//			cout << classworks[optimalResult[j]].name << endl;
//		}
//	}
//
//	return 0;
//}
//
