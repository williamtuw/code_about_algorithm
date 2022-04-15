#include<stdio.h>
#include <string>
//题目描述
//熄灯问题
//In an extended version of the game Lights Out, is a puzzle with 5 rows of 6 buttons each(the actual puzzle has 5 rows of 5 buttons each).Each button has a light.When a button is pressed, that button and each of its(up to four) neighbors above, below, right and left, has the state of its light reversed. (If on, the light is turned off; if off, the light is turned on.) Buttons in the corners change the state of 3 buttons; buttons on an edge change the state of 4 buttons and other buttons change the state of 5. For example, if the buttons marked X on the left below were to be pressed, the display would change to the image on the right.
//The aim of the game is, starting from any initial set of lights on in the display, to press buttons to get the display to a state where all lights are off.When adjacent buttons are pressed, the action of one button can undo the effect of another.For instance, in the display below, pressing buttons marked X in the left display results in the right display.Note that the buttons in row 2 column 3 and row 2 column 5 both change the state of the button in row 2 column 4, so that, in the end, its state is unchanged.


//Note:
//1. It does not matter what order the buttons are pressed.
//2. If a button is pressed a second time, it exactly cancels the effect of the first press, so no button ever need be pressed more than once.
//3. As illustrated in the second diagram, all the lights in the first row may be turned off, by pressing the corresponding buttons in the second row.By repeating this process in each row, all the lights in the first
//four rows may be turned out.Similarly, by pressing buttons in columns 2, 3 ? , all lights in the first 5 columns may be turned off.
//Write a program to solve the puzzle.
//输入
//The first line of the input is a positive integer n which is the number of puzzles that follow.Each puzzle will be five lines, each of which has six 0抯 or 1抯 separated by one or more spaces.A 0 indicates that the light is off, while a 1 indicates that the light is on initially.
//输出
//For each puzzle, the output consists of a line with the string : "PUZZLE #m", where m is the index of the puzzle in the input file.Following that line, is a puzzle - like display(in the same format as the input).In this case, 1's indicate buttons that must be pressed to solve the puzzle, while 0抯 indicate buttons, which are not pressed. There should be exactly one space between each 0 or 1 in the output puzzle-like display.
int getBit(char c, int i)
{
	return (c >> i) & 1;
}
void setBit(char& c, int i, int v)
{
	if (v)
	{
		c |= (1 << i);
	}
	else
	{
		c &= ~(1 << i);
	}
}
void flipBit(char& c, int i)
{
	c ^= (1 << i);
}
void outPutResult(int t, char* result)
{
	printf("PUZZLE #%d\n", t);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%d", getBit(result[i], j));
			if (j < 5)
				printf(" ");
		}
		printf("\n");
	}
}

void lightMain() {
	char ori_lights[5];
	char lights[5];
	char result[5];
	char switchs;

	int T;
	scanf("%d", &T);
	//处理每组数据
	for (int t = 1; t <= T; t++)
	{
		//读取原始数据
		memset(ori_lights, 0, sizeof(ori_lights));
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 6; j++)
			{
				int state;
				scanf("%d", &state);
				setBit(ori_lights[i], j, state);
			}
		//枚举第一行所有状态

		for (char n = 0; n < 64u; n++)
		{
			switchs = n;
			memcpy(lights, ori_lights, sizeof(ori_lights));

			for (int i = 0; i < 5; i++)
			{
				result[i] = switchs;
				for (int j = 0; j < 6; j++)
				{
					if (getBit(switchs, j))
					{
						flipBit(lights[i], j);
						if (j > 0)
							flipBit(lights[i], j - 1);
						if (j < 5)
							flipBit(lights[i], j + 1);
					}

				}
				if (i < 4)
					lights[i + 1] ^= switchs;
				switchs = lights[i];
			}
			if (lights[4] == 0)
			{
				//这种枚举情况是对的
				outPutResult(t, result);
				break;
			}
		}
	}
}