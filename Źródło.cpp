//INTERPOLACJA

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double wartosc(double, double*, double* );
int main()
{
	double arg, w;
	cin >> arg;
	double tabX[5], tabY[5];
	ifstream dane("dane.txt");
	if(dane.is_open())
	{
			for (int i = 0;!dane.eof(); i++)
			{
				dane >> tabX[i] >> tabY[i];
			}
	}
	else
	{
		cout << "Nie mozna otworzyc pliku." << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << tabX[i] << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << tabY[i]<< endl;
	}
dane.close();
w = wartosc(arg, tabX, tabY);
cout <<endl<<"Wartosc funkcji dla argumentu: "<< w << endl;
system("pause");
}
double wartosc(double arg, double *tabX, double *tabY)
{
	double w = 0,mnozenie=0,dodawanie=0;
	int i, j;
	double a,b;
	double *wski=tabX;
	double *wskj = tabX;
	double *wsky = tabY;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5 and j != i; j++)
		{
			a = (*wski);
			b = (*wskj);
			mnozenie = mnozenie * (arg - a) / (a - b);
			wskj++;
		}
		(*wskj) = tabX;
		w=w+( (*wsky) * mnozenie);
	}
	return w;
}