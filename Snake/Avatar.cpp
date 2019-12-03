#include <iostream>
#include <time.h>
#include<conio.h>
#include <string>
#include<windows.h>
#include "Avatar.h"
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int xpoz, ypoz, xfruit, yfruit, score;
int* tailx = new int[100], * taily = new int[100], ntail,pamiec, prevx, prevy, ss, zz;

enum eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
	

};
eDirection direction;
void Setup()
{
	gameOver = false;
	direction = STOP;
	xpoz = width / 2;
	ypoz = height / 2;
	xfruit = rand() % (width - 1);
	yfruit = rand() % (height - 1);
}
void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";

	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{

		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}


			if (i == ypoz && j == xpoz)
			{

				cout << "O";

			}
			else if (i == yfruit && j == xfruit)
			{
				cout << "F";

			}
			else
			{
				bool czy = false;

				for (int s = 0; s < 10; s++)
				{
					if (tailx[s] == j && taily[s] == i)
					{
						cout << "o";
						czy = true;
					}

				}
				if (czy == false)
				{
					cout << " ";

				}



			}

			if (j == width - 1)
			{
				cout << "#";

			}


		}

		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";

	}

	cout << endl;

	cout << "Score: " << score;


}
void Input()
{

	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (pamiec != RIGHT)
			{
				direction = LEFT;
				pamiec = LEFT;

			}
			
			break;
		case 'd':
			if (pamiec != LEFT)
			{
				direction = RIGHT;
				pamiec = RIGHT;
			}
			
			break;
		case 'w':
			if (pamiec != DOWN)
			{
				direction = UP;
				pamiec = UP;
			}
			break;
		case 's':
			if (pamiec != UP)
			{
				direction = DOWN;
				pamiec = DOWN;

			}
			
			break;
		case 'o':
			gameOver = true;
			break;

		}

	}


}
void Logic()
{
	
	
	
	for (int i = 0; i <ntail ; i++)
	{
		if (i == 0)
		{
			prevx = tailx[0];
			prevy = taily[0];
			tailx[0] = xpoz;
			taily[0] = ypoz;

		}
		else
		{
			ss = tailx[i];
			zz = taily[i];
			tailx[i] = prevx;
			taily[i] = prevy;
			prevx = ss;
			prevy = zz;

		}
		


	}

	




	switch (direction)
	{
	case LEFT:
		xpoz--;
		break;
	case RIGHT:
		xpoz++;
		break;
	case UP:
		ypoz--;
		break;
	case DOWN:
		ypoz++;
		break;


	}
	if (xpoz > width - 1 || xpoz < 0 || ypoz>height - 1 || ypoz < 0)
	{
		gameOver = true;
		

	}
	for (int i = 0; i < ntail; i++)
	{
		if (xpoz == tailx[i] && ypoz == taily[i])
		{
			gameOver = true;
		}

	}
	

	if (xpoz == xfruit && ypoz == yfruit)
	{
		
		score += 100;
		xfruit = rand() % (width - 1);
		yfruit = rand() % (height - 1);
		ntail++;
	}




}
void Menu(void)
{
	cout << "Welcome to the snake world!!!"<<endl;
	cout<<"Create your avatar:"

}
int main()
{
	
	




	srand(time(NULL));
	Setup();


	while (!gameOver)
	{

		Sleep(50);
		Draw();
		Input();
		Logic();



	}

	return 0;
}
