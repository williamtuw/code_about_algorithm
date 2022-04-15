//#include <iostream>
//#include <cstring>
//using namespace std;
//
//void setState(int* state,int case_)
//{
//	memset(state, 0, 24);
//	switch (case_)
//	{
//	case 6: state[5] = 1; break;
//	case 5:	state[0] = 11; break;
//	case 4:state[1] = 5; break;
//	case 3:state[2] = 4; break;
//	default:
//		break;
//	}
//}
//int main_moudle()
//{
//	int flag[6];
//	int state[6];//当前箱子的容量
//	int array[6];//当前要放入的货物
//	int count;//最小所需箱子数
//	memset(flag, 0, sizeof(flag));
//	while (true)
//	{
//		count = 0;
//		for (int i = 0; i < 6; i++)
//			cin >> array[i];
//		if (!memcmp(flag, array, sizeof(flag)))break;
//		while (memcmp(flag, array, sizeof(flag)))
//		{
//			//每次循环放满一个箱子
//			//从大到小放
//			count++;
//			setState(state, 6);
//			if (array[5] > 0)
//			{
//				array[5]--;
//				state[5]--;
//				continue;
//			}
//			if (array[4] > 0)
//			{
//				array[4]--;
//				setState(state, 5);
//			}
//			else if (array[3] > 0)
//			{
//				array[3]--;
//				setState(state, 4);
//			}
//			else setState(state, 3);
//			while (state[2] > 0&&array[2]>0)
//			{
//				array[2]--;
//				state[2]--;
//			}
//
//			switch (state[2])
//			{
//			case 4:state[1] = 9; break;
//			case 3:state[1] = 5; state[0] = 7; break;
//			case 2:state[1] = 3; state[0] = 6; break;
//			case 1:state[1] = 1; state[0] = 5; break;
//			default:
//				break;
//			}
//			while (state[1] > 0 && array[1] > 0)
//			{
//				array[1]--;
//				state[1]--;
//			}
//			
//			state[0] += state[1] * 4;
//			while (state[0] > 0 && array[0] > 0)
//			{
//				array[0]--;
//				state[0]--;
//			}
//			
//		}
//		//输出结果
//		cout << count << endl;
//	}
//
//	return 0;
//}
//
