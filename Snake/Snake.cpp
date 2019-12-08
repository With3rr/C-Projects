#include <iostream>
#include <time.h>
#include<conio.h>
#include <string>
#include<windows.h>
#include "Avatar.h"
#include <fstream>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int xpoz, ypoz, xfruit, yfruit, score;
int* tailx = new int[100], * taily = new int[100], ntail, pamiec, prevx, prevy, ss, zz;
fstream plik;


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
	ntail = 0;
	pamiec = STOP;
	gameOver = false;
	direction = STOP;
	xpoz = width / 2;
	ypoz = height / 2;
	xfruit = rand() % (width - 1);
	yfruit = rand() % (height - 1);
	score=0;
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



	for (int i = 0; i < ntail; i++)
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
void wybierz(Avatar *a)
{
	int *wybor=new int;
	string* potwiedzeniehasla = new string;
	bool* konto = new bool;
	*konto = false;
	string* namee = new string;
	string* hasloo = new string;

	cout << "1-Stwórz konto"<<endl;
	cout << "2-Logowanie" << endl;
	cout << "3-Wyjdz" << endl;
	cin >> *wybor;
	switch (*wybor)
	{
	case 1:
		do
		{
			cout << "Podaj nickname:" << endl;
			 cin >> *namee;
			 *(a->name) = *namee;
			cout << "Podaj haslo:" << endl;
			cin >> *hasloo;
			*(a->haslo) = *hasloo;
			cout << "Potwierdz haslo:" << endl;
			cin >> *potwiedzeniehasla;
			if (*(a->haslo) == *potwiedzeniehasla)
			{
				cout << "Twoje konto zostało założone :)"<<endl;
				*konto = true;
				plik.open("snake.txt",ios::out);
				plik << *namee<<endl;
				plik << *hasloo << endl;
				
				
				system("cls");
				

			}
			else
			{
				cout << "Dane niepoprawne,prosze ponowic proces:";
				
				system("cls");

			}

		} while (*konto==false);
		delete konto;
		delete potwiedzeniehasla;
		delete wybor;
		
		
		
		break;
	case 2:
		cout << "Podaj nickname";
		//trzeba tu dokonczyc
			break;
	case 3:
		exit(0);
		break;
	}
	


	
	

}
void opcje(Avatar *s)
{
	int* wybor = new int;
	int* wybor2 = new int;

	cout << "1-Nowa gra"<<endl;
	cout << "2-Wyjdz"<<endl;
	cin >> *wybor;
	switch (*wybor)
	{
	case 1:
		cout << "Wybierz poziom trudnosci: " << endl;
		cout << "1-Latwy" << endl;
		cout << "2-Sredni" << endl;
		cout << "3-Trudny" << endl;
		cin >> *wybor2;
		switch (*wybor2)
		{
		case 1:
			s->ustawieniepoziomu(1);
			break;
		case 2:
			s->ustawieniepoziomu(2);
			break;
		case 3:
			s->ustawieniepoziomu(3);
			break;
		}
		break;
	case 2:
		exit(0);
		break;
	}
	




	
}
void spij(Avatar* aa)
{
	switch(*(aa->trudnosc))
	{
	case 0:
		Sleep(150);
		break;
	case 1:
		Sleep(75);
		break;
	case 2:
		break;
	}

}
int main()
{
	
	srand(time(NULL));
	Avatar* a1 = new Avatar;

	wybierz(a1);

	opcje(a1);
	
	Sleep(1000);

	Setup();

	while (!gameOver)
	{
		spij(a1);
		Draw();
		Input();
		Logic();




	}
	plik << score;
	
	

	return 0;
}
