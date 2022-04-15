#include <iostream>

using namespace std;

int main_()
{
	char a[1000], b[1000];
	int i;
	while (gets_s(a))
	{
		if (strcmp("START", a) == 0)
			memset(b, 0, 1000);
		else if (strcmp("END", a) == 0)
		
			cout << b<<endl;
		else if (strcmp("ENDOFINPUT", a) == 0)
			break;
		else
		{
			for (i = 0; a[i] != '\0'; i++)
			{
				if (a[i] >= 'A' && a[i] <= 'Z')
				{
					if (a[i] <= 'E')
					{
						b[i] = a[i] + 21;
					}
					else b[i] = a[i] - 5;
				}
				else
				{
					b[i] = a[i];
				}
			}
			
		}

	}

	return 0;
}