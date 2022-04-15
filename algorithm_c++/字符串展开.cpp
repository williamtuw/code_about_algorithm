#include <iostream>

using namespace std;



int cin_num(char** str)
{
	int count=0;
	char str_num[3];
	while (**str >= '0'&&**str <= '9')
	{
		str_num[count++] = **str;
		*str = *str + 1;
	}
	return atoi(str_num);
}

char* expend_str(char* str, int n)
{
	
	int m;
	char* temp=0;
	//展开n次
	while (n--)
	{
		temp = str;
		//具体展开步骤
		while (*temp!='\0'&&*temp!=')')
		{

			if ('a' <= *temp && *temp <= 'z')
			{
				cout << *temp;
			}
			else if (*temp == '(' )
			{
				temp = expend_str(temp+1 ,1);
				
			}
			else
			{

				m = cin_num(&temp);
				if (*temp=='(')
				{
					temp = expend_str(temp+1, m);
							
				}
				else
					while (m--)
						cout << *temp ;
								
			}

			temp++;
		}
	}
	
	
	return temp;
}

int main_()
{
	int n;
	char buffet[250];
	cin >> n;

	while(n--)
	{
		cin >> buffet;
		expend_str(buffet,1);
		cout << endl;
	}
	return 0;
}