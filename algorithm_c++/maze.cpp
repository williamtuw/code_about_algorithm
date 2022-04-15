#include <iostream>

using namespace std;
int W, H;
char MAP[20][20];
int SX,SY;

int DFS(int r, int c)
{
	if (r < 0 || c < 0 || c >= W || r >= H || MAP[r][c] == '#')
		return 0;
	
	MAP[r][c] = '#';
	


	return 1+DFS(r+1,c)+ DFS(r, c+1)+ DFS(r, c-1)+ DFS(r-1, c);
}

int main_()
{
	while (cin >> W>>H)
	{

		for (int i=0;i<H;i++)
		{
			cin >> MAP[i];
			for (int j=0;j<W;j++)
			{
				
				if (MAP[i][j]=='@')
				{
					SX = i;
					SY = j;
					MAP[i][j] = '.';
				}
			}
		}
		//´¦Àí
		cout << DFS(SX,SY)<<endl;

	}

	return 0;
}