//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//class LongIntByStr
//{
//public:
//	string value = "0";
//	bool operator < (const LongIntByStr& other)
//	{
//		int thL = value.length();
//		int othL = other.value.length();
//		if (thL < othL)return true;
//		else if (thL == othL && value < other.value)return true;
//		return false;
//	}
//
//	LongIntByStr(const char* v)
//	{
//		value = string(v);
//	}
//	LongIntByStr(string v)
//	{
//		value = v;
//	}
//	LongIntByStr()
//	{
//	}
//
//	
//	string trim(string s)
//	{
//		if (s[0] != '0')return s;
//		string rst;
//		int flag = 1;
//		for (int i = 0; i < (int)s.length(); i++)
//		{
//			if (flag && s[i] == '0'&&i < ((int)s.length() - 1))continue;
//			flag = 0;
//			rst += s[i];
//		}
//		return rst;
//	}
//	LongIntByStr add(LongIntByStr& other)
//	{
//		string rst = "";
//		int flag = 0;
//		int thisL = value.length();
//		int otherL = other.value.length();
//		if (other.value == "0")return *this;
//		if (value == "0")return other;
//		LongIntByStr* shorter = thisL > otherL ? &other : this;
//		LongIntByStr* longer = shorter == &other ? this : &other;
//		int lL = longer->value.length();
//		int sL = shorter->value.length();
//		for (int i = 0; i < lL; i++)
//		{
//			if (i >= sL)
//			{
//				rst += cadd('0', longer->value[lL - i - 1], flag);
//			}
//			else
//			{
//				rst += cadd(shorter->value[sL - i - 1], longer->value[lL - i - 1], flag);
//			}
//		}
//		if (flag)rst += '1';
//		reverse(rst.begin(), rst.end());
//		return LongIntByStr(rst);
//
//	}
//	char cadd(const char& c1, const char& c2, int& flag)
//	{
//		int  rst = c1 - '0' + c2 - '0' + flag;
//		flag = rst / 10;
//		return rst % 10 + '0';
//	}
//	
//	char csub(const char& c1, const char& c2, int& flag)
//	{
//		int  rst = c1 - '0' - (c2 - '0') + flag;
//		if (rst < 0)
//		{
//			flag = -1;
//			return rst + 10 + '0';
//		}
//		flag = 0;
//		return rst + '0';
//	}
//	LongIntByStr substract(LongIntByStr& other)
//	{
//		string rst = "";
//		int flag = 0;
//		int lL = value.length();
//		int sL = other.value.length();
//		if (other.value == "0")return *this;
//		if (*this < other)return LongIntByStr("error");
//
//		for (int i = 0; i < lL; i++)
//		{
//			if (i >= sL)
//			{
//				rst += csub(value[lL - i - 1], '0', flag);
//			}
//			else
//			{
//				rst += csub(value[lL - i - 1], other.value[sL - i - 1], flag);
//			}
//		}
//		reverse(rst.begin(), rst.end());
//		return LongIntByStr(trim(rst));
//	}
//
//};
//
//int M,numLen;
//LongIntByStr min_sum,sum_, N_NUM;
//bool visited[51][51];
//LongIntByStr MIN_SUM[51][51];
//
////最优性减枝
////sum_ >= min_sum return
////设置数组MIN_SUM[n][m]表示在状态为n,m时的最小临时sum 
//void dfs(int n, int m)
//{
//	if (m == 0)
//	{
//		LongIntByStr temp(N_NUM.value.substr(numLen - n));
//		sum_ = sum_.add(temp);
//		min_sum = min_sum < sum_? min_sum :sum_;
//		sum_ = sum_.substract(temp);
//		return;
//	}
//	if (n < m + 1 || visited[n][m])
//	{
//		return;
//	}
//	if (MIN_SUM[n][m].value == N_NUM.value|| sum_ < MIN_SUM[n][m])MIN_SUM[n][m].value = sum_.value;
//	else return;
//	visited[n][m] = true;
//	LongIntByStr temp;
//	for (int i = 1; i <= n - m; i++)
//	{
//		temp.value =  N_NUM.value.substr(numLen - n, i);
//		sum_ = sum_.add(temp);
//		if(sum_<min_sum)
//			dfs(n - i, m - 1);
//		sum_ = sum_.substract(temp);
//	}
//
//	visited[n][m] = false;
//}
//int main_fmatrix()
//{
//	while (cin >> M)
//	{
//		memset(visited, false, sizeof(visited));	
//		sum_.value = "0";
//		cin >> N_NUM.value;
//		min_sum = N_NUM;
//		numLen = N_NUM.value.length();
//		for (int i = 1; i <= numLen; i++)
//			for (int j = 1; j <= M; j++)
//				MIN_SUM[i][j] = N_NUM;
//		dfs(numLen, M);
//		cout << min_sum.value << endl;
//	}
//	return 0;
//}
//
