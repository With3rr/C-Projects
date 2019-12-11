// ConsoleApplication9.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

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
int xpoz, ypoz, xfruit, yfruit, score,maxscore;
int* tailx = new int[100], * taily = new int[100], ntail, pamiec;
int* prevx = new int;
int* prevy = new int;
int* ss = new int;
int* zz = new int;
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
void czygameover()
{
	if (gameOver == true)
	{
		delete[] tailx;
		delete[] taily;

		tailx = new int[100];
		taily = new int[100];

	}
}
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
	score = 0;
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
			*(prevx) = tailx[0];
			*(prevy) = taily[0];
			tailx[0] = xpoz;
			taily[0] = ypoz;

		}
		else
		{
			*(ss) = tailx[i];
			*(zz) = taily[i];
			tailx[i] = *(prevx);
			taily[i] = *(prevy);
			*(prevx) = *(ss);
			*(prevy)=*(zz);

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
void wybierz(Avatar* a)
{
	int* wybor = new int;
	string* potwiedzeniehasla = new string;
	bool* konto = new bool;
	*konto = false;
	string* namee = new string;
	string* hasloo = new string;

	cout << "1-Stworz konto" << endl;
	cout << "2-Logowanie" << endl;
	cout << "3-Wyjdz" << endl;
	cin >> *wybor;
	switch (*wybor)
	{
	case 1:
		do
		{
			system("cls");
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
				system("cls");
				cout << "Konto zalozone :)" << endl;
				Sleep(100);
				*konto = true;
				plik.open("snake.txt", ios::out);
				plik << *namee << endl;
				plik << *hasloo << endl;
				maxscore = 0;
				Sleep(1000);


				system("cls");


			}
			else
			{
				cout << "Dane niepoprawne,prosze ponowic proces:";

				system("cls");

			}

		} while (*konto == false);
		delete konto;
		delete potwiedzeniehasla;
		delete wybor;



		break;
	case 2:
		system("cls");
		plik.open("snake.txt", ios::in);
		if (plik.good() == false)
		{
			cout << "Brak zapisanych kont !!!!";
			exit(0);
		}
		else
		{
			string tymimie, tymhaslo;
			string linia;
			int nr_lini = 1;
			while (getline(plik, linia))
			{
				switch (nr_lini)
				{
				case 1:
					*(a->name) = linia;
					break;
				case 2:
					*(a->haslo) = linia;
					break;
				case 3:
					maxscore = stoi(linia);
					break;
				}
				nr_lini++;
			}
			cout << "Podaj nick:";
			cin >> tymimie;
			cout << "Podaj haslo:";
			cin >> tymhaslo;
			if (*(a->name) != tymimie || tymhaslo != *(a->haslo))
			{
				cout << "Niepoprawne dane";
				Sleep(100);
				exit(0);
			}


		}
		

		break;
	case 3:
		exit(0);
		break;
	}






}
void opcje(Avatar* s)
{
	int* wybor = new int;
	int* wybor2 = new int;

	cout << "1-Nowa gra" << endl;
	cout << "2-Wyjdz" << endl;
	cin >> *wybor;
	system("cls");

	switch (*wybor)
	{
	case 1:
		cout << "Wybierz poziom trudnosci: " << endl;
		cout << "1-Latwy" << endl;
		cout << "2-Sredni" << endl;
		cout << "3-Trudny" << endl;
		cin >> *wybor2;
		system("cls");
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
	switch (*(aa->trudnosc))
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
struct
{
	char znak;
	int kod;
}aabb;
int main()
{

	srand(time(NULL));
	Avatar* a1 = new Avatar;

	wybierz(a1);
	system("cls");
	while (true)
	{
		opcje(a1);
		Setup();

		while (!gameOver)
		{
			spij(a1);
			Draw();
			Input();
			Logic();
			cout << endl;




		}
		if (score > maxscore)
		{
			maxscore = score;
		}
		if (gameOver)
		{
			system("cls");
			cout << "#############################" << endl;
			cout << "	KONIEC GRY     " << endl;
			cout << "#############################" << endl;
			cout << "Liczba zdobytych pkt:" << score<<endl;
			cout << "Max score: " << maxscore<<endl;
			cout << "Nacisnij klawisz aby kontynuowac:";
			while (true)
			{
				if (_kbhit())
				{
					aabb.znak = _getch();
					aabb.kod = static_cast<int>(aabb.znak);
					if (aabb.kod == 13)
					{
						break;
					}
					else if (aabb.kod = 27)
					{
						exit(0);
					}

				}


			}
			plik << maxscore;

			system("cls");

		}
		czygameover();
		
		


	}
	




	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
