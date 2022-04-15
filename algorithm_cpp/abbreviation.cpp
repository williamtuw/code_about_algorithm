#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;




int main_fmatrix()
{
	int T, count_abb, count_word, flag = 0;
	cin >> T;
	cin.get();
	char buf[101], word[101];
	char abb[101];

	for (int i = 0; i < T; i++)
	{
		count_abb = count_word = 0;
		cin.getline(buf, 100);
		for (int j = 0; j < (int)strlen(buf) + 1; j++)
		{
			if (buf[j] != ' '&&buf[j] != '\0')
			{
				word[count_word++] = buf[j];
				word[count_word] = 0;
				flag = 1;
			}
			else if (flag)
			{
				//ÕÒµ½Ò»¸ö´Ê
					int len = strlen(word);
				transform(word, word + len, word, toupper);
				if (len > 2 && strcmp(word, "THE") != 0 && strcmp(word, "AND") != 0 && strcmp(word, "FOR") != 0)
					abb[count_abb++] = word[0];
				count_word = 0;
				flag = 0;
			}

		}
		abb[count_abb] = 0;
		cout << abb << endl;
	}

	return 0;
}

