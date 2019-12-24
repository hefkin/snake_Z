#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale (LC_ALL, "Russian");
	srand(time(NULL));

	int sym = 0; int sym_g = 0; int k = 0;
	int w, q;

	cout << "Введите размерность массива: ";

	while (!(cin >> q) || (cin.peek() != '\n'))
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Некорректные данные, попробуйте снова" << endl;
	}

	while (q > 10)
	{
		cout << "Некорректные данные, попробуйте снова" << endl;
		while (!(cin >> q) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некорректные данные, попробуйте снова" << endl;
		}
	}

	w = q;
	system("cls");
	int** ar = new int* [w];

	cout << "___________________________________________________________________________" << endl << endl;
	cout << "Массив:" << endl;
	cout << "___________________________________________________________________________" << endl << endl;

	for (int i = 0; i < w; i++)
	{
		ar[i] = new int[q];
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < q; j++)
		{
			ar[i][j] = rand() % 10;
			sym = ar[i][j] + sym;
		}
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < q; j++)
		{
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < w; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 4; j >= 0; j--)
			{
				sym_g = sym_g + ar[i][j];
				k++;
				if (sym_g > sym - sym_g)
				{
					cout << "___________________________________________________________________________" << endl << endl;
					cout << "Длина головы - " << k << endl;
					cout << "___________________________________________________________________________" << endl << endl;
					exit(0);
				}
			}
		}
		else
		{
			for (int j = 0; j < q; j++)
			{
				sym_g = sym_g + ar[i][j];
				k++;
				if (sym_g > sym - sym_g)
				{
					cout << "___________________________________________________________________________" << endl << endl;
					cout << "Длина головы - " << k << endl;
					cout << "___________________________________________________________________________" << endl << endl;
					exit(0);
				}
			}
		}
	}
}