////����������ʽ
//
//#include <iostream>
//
//using namespace std;
//
////���ʽ�ɶ���Ӽ����,ÿһ���ж�����ӳ˳����,���ӿ�������Ҳ�����Ǳ��ʽ
////������ʽ����+ - * / ( ) ������ɲ����пո�
//
//double exp_value();
//double digit_value()
//{
//	//��ȡһ������������ֵ
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
//	//��ȡһ�����Ӳ�������ֵ
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
//	//��ȡһ�������ֵ
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
//	//��ȡһ�����ʽ��������ֵ
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