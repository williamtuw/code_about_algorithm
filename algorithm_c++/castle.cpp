#include <iostream>
#include <algorithm>

using namespace std;


int R, C;
int ARRAY[60][60];
int COLOR[60][60];
int ROOMNUM = 0, MAX_AREA = 0, roomarea;


void dfs(int i, int j)
{
	if (COLOR[i][j])
		return;
	roomarea++;
	COLOR[i][j] = ROOMNUM;
	if ((ARRAY[i][j] & 1) == 0)dfs(i, j - 1);
	if ((ARRAY[i][j] & 2) == 0)dfs(i - 1, j);
	if ((ARRAY[i][j] & 4) == 0)dfs(i, j + 1);
	if ((ARRAY[i][j] & 8) == 0)dfs(i + 1, j);
}

int main_castle()
{

	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> ARRAY[i][j];
	memset(COLOR, 0, sizeof(COLOR));
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{

			if (!COLOR[i][j])
			{
				roomarea = 0;
				ROOMNUM++;
				dfs(i, j);
				MAX_AREA = max(MAX_AREA, roomarea);
			}
		}
	cout << ROOMNUM << endl << MAX_AREA << endl;
	return 0;
}

