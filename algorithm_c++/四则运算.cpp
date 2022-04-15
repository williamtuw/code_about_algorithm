////计算四则表达式
//
//#include <iostream>
//
//using namespace std;
//
////表达式由多项加减组成,每一项有多个因子乘除组成,因子可以是数也可以是表达式
////四则表达式由数+ - * / ( ) 和数组成不含有空格
//
//double exp_value();
//double digit_value()
//{
//	//读取一个数并返回其值
//	char op = cin.peek();
//	char flag = 1;
//	double result = 0;
//	if (op == '-')
//	{
//		cin.get();
//		flag = -1;
//	}
//	char c = cin.peek();
//	while (isdigit(c))
//	{
//		cin.get();
//		result = result * 10 + c - '0';
//		c = cin.peek();
//	}
//	double w = 0.1;
//	if (c == '.')
//	{
//		cin.get();
//		c = cin.peek();
//		while (isdigit(c))
//		{
//			cin.get();
//			result += (c - '0')*w;
//			c = cin.peek();
//			w *= 0.1;
//		}
//	}
//
//	return result * flag;
//}
//
//double factor_value()
//{
//	//读取一个因子并返回其值
//	double result;
//	char op = cin.peek();
//	if (op == '(')
//	{
//		cin.get();
//		result = exp_value();
//		cin.get();
//	}
//	else
//	{
//		result = digit_value();
//	}
//	return result;
//}
//double term_value()
//{
//	//读取一项并返回其值
//	double result = factor_value();
//	char op = cin.peek();
//	while (op == '*' || op == '/')
//	{
//		op = cin.get();
//		if (op == '*')
//			result *= term_value();
//		else if (op == '/')
//			result /= term_value();
//		op = cin.peek();
//
//	}
//	return result;
//
//}
//
//double exp_value()
//{
//	//读取一个表达式并返回其值
//	double result = term_value();
//	char op = cin.peek();
//	while (op == '+' || op == '-')
//	{
//		op = cin.get();
//		if (op == '+')
//			result += term_value();
//		else if (op == '-')
//			result -= term_value();
//		op = cin.peek();
//		
//	}
//	return result;
//}
//
//
//int main_moudle()
//{
//	printf("%lf", exp_value());
//	return 0;
//}