//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cmath>
//using namespace std;
//
//���ⷽ�� ״ѹdp
//��ĿҪ�� min_p[2^N - 1]
//state ��bitxλ�����x��ҵ���״̬
//����ʽ //״̬ת�Ʒ���
//min_p[state] = min{min_p[state~]+ p}
///*
//���Ʒ��� state 0 -> 2^N - 1
//ʱ�临�Ӷ�
//N*(2^N - 1 )
//�ռ临�Ӷ�
//one state 2bytes
//states count 2^N
//*/
//0����
//int getBit(int byte, int where)
//{
//	return byte >> where & 1;
//}
//0���� bit��Ϊ0
//int setBit(int byte, int where)
//{
//	return byte & ~(1 << where);
//}
//int min_p[32768];//min_p[state]����state״̬�µ���Сpunish
//int timeNow[32768];//timeNow[state]������state״̬��������ʱ��
//int N;//��ҵ��
//int result[16], depth;//�������
//int optimalResult[16];
//struct ClassWork
//{
//	char name[50];
//	int d, c;
//};
//ClassWork classworks[16];//0����
//int getPunish(int now, int c, int d)
//{
//	int punish = now + c - d;
//	return punish > 0 ? punish : 0;
//}
//�ҵ����Ž�
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
//		����min_p
//		for (int j = 0; j < pow(2, N); j++)min_p[j] = 1 << 30;
//		
//		depth = 0;
//		for (int j = 0; j < N; j++)optimalResult[j] = 16;
//		����input
//		for (int j = 0; j < N; j++)
//		{
//			cin >> classworks[j].name >> classworks[j].d >> classworks[j].c;
//		}
//		���ñ߽�ֵ
//		min_p[0] = 0;
//		timeNow[0] = 0;
//		����ʱ��timeNow[state]
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
//		��ʼ����
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
//		����ָ��õ����˳��
//		state = (int)pow(2, N) - 1;
//		getOptimalResultDFS(state, N);
//		������
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
