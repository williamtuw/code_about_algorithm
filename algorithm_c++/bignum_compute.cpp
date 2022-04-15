//作者:tchyou
//2019/4/3

// 用字符串实现
//有符号整形大数和浮点数的加减乘除模幂 运算
// 用位运算实现可以减少空间和时间 有待发布

#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class BigNumber
{
private:
	int sign = 1;//符号 1 为正 -1 为负
	string valueL = "";//左边
	string valueR = "";//右边
	string value = "";//不带小数点形式
	int decimalsPos = 0;//小数位的个数 111.111 为 3  11 为0 11.1 为1
	//在字符串左边补countL 个 零 
	string lPatch(string raw,int count)
	{
		return string(count , '0') + raw;
	}
	//在字符串右边补countR 个 零 
	string rPatch(string raw, int count)
	{
		return   raw + string(count , '0');
	}
	//在字符串左边补countL 个 零 	//在字符串右边补countR 个 零 
	string patch(string raw, int countL, int countR)
	{
		return string(countL, '0') + raw + string(countR, '0');
	}

public:

	BigNumber(string value, int pos,int sign):sign(sign) {
		if ((unsigned)pos >= value.length())value = lPatch(value, pos + 1 - value.length());
		setAttribute(value.substr(0, value.length() - pos), value.substr(value.length() - pos),sign);
	}
	BigNumber(string valueL, string valueR,int sign) {
		setAttribute(valueL, valueR, sign);	
	}
	BigNumber(int value) {
		setAttribute(std::to_string(value), "", 1);
	}
	BigNumber() {}
	void setAttribute(string valueL, string valueR, int sign) {
		this->valueL = stripL(valueL);
		this->valueR = stripR(valueR);
		this->sign = sign;
		value = this->valueL + this->valueR;
		decimalsPos = this->valueR.length();
	}
	static char cadd(const char& c1, const char& c2, int& flag)
	{
		int  rst = c1 - '0' + c2 - '0' + flag;
		flag = rst / 10;
		return rst % 10 + '0';
	}
	static string add(string num1, string num2)
	{
		string rst = "";
		int flag = 0;
		int thisL = num1.length();
		int otherL = num2.length();
		if (num1 == "0")return num2;
		if (num2 == "0")return num1;
		string shorter = thisL > otherL ? num2 : num1;
		string longer = shorter == num2 ? num1 : num2;
		int lL = longer.length();
		int sL = shorter.length();
		for (int i = 0; i < lL; i++)
		{
			if (i >= sL)
			{
				rst += cadd('0', longer[lL - i - 1], flag);
			}
			else
			{
				rst += cadd(shorter[sL - i - 1], longer[lL - i - 1], flag);
			}
		}
		if (flag)rst += '1';
		reverse(rst.begin(), rst.end());
		return rst;

	}

	static char cmul(const char& c1, const char& c2, int& flag)
	{
		int  rst = (c1 - '0') * (c2 - '0') + flag;
		flag = rst / 10;
		return rst % 10 + '0';
	}
	static string mulC(const string num, const char& c)
	{
		if (c == '0' || num == "0")return string("0");
		string rst = "";
		int flag = 0, len = num.length();
		for (int i = 0; i < len; i++)
		{
			rst += cmul(c, num[len - 1 - i], flag);
		}
		if (flag)rst += flag + '0';
		reverse(rst.begin(), rst.end());
		return rst;
	}
	static string powO(string num, int y)
	{
		if (y <= 0)return num;
		if (num == "0")return string("0");
		return num + string(y, '0');
	}
	static string mul(string ths, string other)
	{
		string rst("0");
		int thisL = ths.length();
		int otherL = other.length();
		if (ths == "0" || other == "0")	return rst;
		string shorter = thisL > otherL ? other : ths;
		string longer = shorter == other ? ths : other;
		int lL = longer.length();
		int sL = shorter.length();
		for (int i = 0; i < sL; i++)
		{
			rst = add(powO(mulC(longer, shorter[i]), sL - i - 1), rst);
		}
		return rst;
	}
	

	static char csub(const char& c1, const char& c2, int& flag)
	{
		int  rst = c1 - '0' - (c2 - '0') + flag;
		if (rst < 0)
		{
			flag = -1;
			return rst + 10 + '0';
		}
		flag = 0;
		return rst + '0';
	}


	static string substract(string ths, string other)
	{
		string rst = "";
		int flag = 0;
		int lL = ths.length();
		int sL = other.length();
		if (other == "0")return ths;
		if (sL == lL && other > ths)return "error";
		if (sL > lL) return "error";

		for (int i = 0; i < lL; i++)
		{
			if (i >= sL)
			{
				rst += csub(ths[lL - i - 1], '0', flag);
			}
			else
			{
				rst += csub(ths[lL - i - 1], other[sL - i - 1], flag);
			}
		}
		reverse(rst.begin(), rst.end());
		return stripL(rst);
	}
	static string tryMax(char& flag, string dived, string& divi)
	{
		flag = '1';
		string temp;
		string rst;
		while (true)
		{
			temp = mulC(divi, flag);
			if (substract(dived, temp) == "error")
			{
				flag--;
				return rst;
			}
			rst = temp;
			flag++;
		}
	}
	static string divTwo(string num)
	{
		string two("2");
		if (substract(num, two) == "error")return string("0");
		int index = 0, valueL = num.length();
		string rst;
		string que, temp;
		char flag;
		//que = num.substr(0, 0);
		while (index <= valueL - 1)
		{
			que += num[index];
			que = stripL(que);
			if (substract(que, two) == "error")
			{
				rst += "0";
			}
			else
			{
				temp = tryMax(flag, que, two);
				que = substract(que, temp);
				rst += flag;
			}
			index++;
		}
		return stripL(rst);
	}
	static string div(string dived, string divi, string& mod)
	{
		if (divi == "0")
		{
			mod = "error";
			return "error";
		}
		if (substract(dived, divi) == "error")
		{
			mod = dived;
			return "0";
		}
		int thsL = dived.length();
		int otherL = divi.length();
		string start(powO("1", thsL - otherL - 1));
		string end(powO("1", thsL - otherL + 1));
		string mid = divTwo(add(start, end));
		string temp("0");
		string one("1");
		while (true)
		{
			temp = mul(divi, mid);
			//temp 大于 value 则偏大
			if (substract(dived, temp) == "error")
			{
				end = substract(mid, one);
			}
			else//temp 小于等于 value
			{
				//如果temp+other-1 < value 则偏小
				if (substract(substract(add(temp, divi), one), dived) == "error")
				{
					start = add(mid, one);
				}
				else//value >=temp >= value - other +1 找到
				{
					mod = substract(dived, temp);
					return mid;
				}
			}
			mid = divTwo(add(start, end));
		}

	}

	static string pow(string num, int super)
	{
		if (super == 0)return string("1");
		if (super < 0)return string("0");
		string rst("1");
		for (int i = 0; i < super; i++)
		{
			rst = mul(rst, num);
		}
		return rst;
	}
	BigNumber reverseNumber()
	{
		return BigNumber(valueL, valueR, sign * -1);
	}
	int cmp(const BigNumber& other)
	{
		if (valueL.length() > other.valueL.length())return 1;
		else if (valueL.length() < other.valueL.length()) return -1;
		else
		{
			if (valueL == other.valueL)
			{
				return valueR.compare(other.valueR);
			}
			else
			{
				return valueL.compare(other.valueL);
			}
		}
	}
	//解析字符串
	bool parse(string raw)
	{
		reset();
		if (raw[0] == '+')raw = raw.substr(1);
		if (raw[0] == '-') {
			sign = -1;
			raw = raw.substr(1);
		}
		size_t index = raw.find_first_of('.');
		if (index == string::npos)
		{
			//无小数点
			value = stripL(raw);
			decimalsPos = 0;
			valueL = value;
			return true;
		}
		valueL = stripL(raw.substr(0, index));
		valueR = stripR(raw.substr(index + 1));
		if (valueR.find_first_of('.') != string::npos)return false;
		value = valueL + valueR;
		decimalsPos = valueR.length();
		return true;
	}
	static string stripL(string s)
	{
		//去除raw 前面多余的零
		if (s == "")return "";
		size_t index = s.find_first_not_of("0");
		if (index == string::npos)return "0";
		return s.substr(index);
	}
	static string stripR(string s)
	{
		//去除raw 后面多余的零
		if (s == "")return "";
		size_t index = s.find_last_not_of("0");
		if (index == string::npos)return "";
		return s.substr(0, index + 1);
	}
	//重置
	void reset()
	{
		decimalsPos = 0,sign = 1;
		value = valueL = valueR = "";
	}
	string getRealValue()
	{
		string pre = sign == -1 ? "-" : "";
		if (decimalsPos == 0)return pre + stripL(value);
		return pre + stripL(valueL) + "." + stripR(valueR);
	}
	//测试函数
	string getValue()
	{
		return value;
	}
	int getDecimalsPos()
	{
		return decimalsPos;
	}

	//将两个位数相同的数相加 num1,num2 >= 0
	string baseAdd(string num1, string num2,int& flag)
	{
		string rst = "";
		if (num1.find_first_not_of("0") == string::npos)return num2;
		if (num2.find_first_not_of("0") == string::npos)return num1;
		int num1L = num1.length(), num2L = num2.length();
		for (int i = 0; i < num1L; i++)
		{
			rst += cadd(num1[num1L - i - 1], num2[num2L - i - 1], flag);
		}
		if (flag)rst += "1";
		reverse(rst.begin(), rst.end());
		return rst;
	}
	//将两个位数相同的数相减 且 num1 >= num2 >=0
	string baseSub(string num1, string num2, int& flag)
	{
		string rst = "";
		if (num2.find_first_not_of("0") == string::npos)return num1;
		int num1L = num1.length(), num2L = num2.length();
		for (int i = 0; i < num1L; i++)
		{
			rst += csub(num1[num1L - i - 1], num2[num2L - i - 1], flag);
		}
		reverse(rst.begin(), rst.end());
		return rst;
	}
	BigNumber add(BigNumber other)
	{
		if (sign == other.sign) {
			int flag = 0;
			int maxLR = valueR.length() > other.valueR.length() ? valueR.length() : other.valueR.length();
			int maxLL = valueL.length() > other.valueL.length() ? valueL.length() : other.valueL.length();
			string rst = baseAdd(patch(value, maxLL - valueL.length(), maxLR - valueR.length()),
				patch(other.value, maxLL - other.valueL.length(), maxLR - other.valueR.length()), flag);
			return BigNumber(rst,maxLR,sign);
		}
		else if(sign == 1 && other.sign == -1)
		{
			return sub(other.reverseNumber());
		}
		else
		{
			// sign == -1 && other.sign == 1
			return other.sub(reverseNumber());
		}
	}
	BigNumber sub(BigNumber other)
	{
		if (sign != other.sign) return add(other.reverseNumber());
		else if(sign == -1 &&other.sign == -1) return other.reverseNumber().sub(reverseNumber());
		else //sign == other.sign == 1
		{
			if (cmp(other) == -1) return other.sub(*this).reverseNumber();
			else
			{
				int flag = 0;
				int maxLR = valueR.length() > other.valueR.length() ? valueR.length() : other.valueR.length();
				int maxLL = valueL.length() > other.valueL.length() ? valueL.length() : other.valueL.length();
				string rst = baseSub(patch(value, maxLL - valueL.length(), maxLR - valueR.length()),
					patch(other.value, maxLL - other.valueL.length(), maxLR - other.valueR.length()), flag);
				return BigNumber(rst,maxLR, sign);
			}
		}
	}
	BigNumber mul(BigNumber other)
	{
		string rst = mul(value, other.value);
		return BigNumber(rst, decimalsPos + other.decimalsPos, sign*other.sign);
	}
	BigNumber pow(int n)
	{
		if (n == 0)return BigNumber("1", 0,1);
		BigNumber rst(*this);
		for (int i = 0; i < n - 1; i++)
		{
			rst = rst.mul(*this);
		}
		return rst;
	}
}; 
int main_fmatrix()
{
	BigNumber bn1;
	BigNumber bn2;
	int n;
	string input1, input2,rst;
	while (cin >> input1 >> n )
	{
		/*cout << bool(bn.parse(input)) << endl;
		cout << bn.getValue() << endl;
		cout << bn.getDecimalsPos() << endl;
		cout << bn.getRealValue() << endl;*/
		bn1.parse(input1);
		
		rst = bn1.pow(n).getRealValue();
		if (rst[0] == '0'&&rst[1] == '.')rst = rst.substr(1);
		cout << rst << endl;
	}
	return 0;
}

int main() {
	main_fmatrix();
}