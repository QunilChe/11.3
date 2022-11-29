
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>
#include "var.h" // підключили зовнішні оголошення змінних
#include "opr.h"
using namespace std;
using namespace nsOpr;
using namespace nsVar;
double nsOpr::LineSearch(Student* p){
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == KN)
		{
			n++;
			if (p[i].otsinka1 > 3 and p[i].otsinka2 > 3 and p[i].otsinkaPR > 3)
			{
				k++;
			}
		}
	}
	return k;

}
double nsOpr::LineSearch1(Student* p)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == INF)
		{
			n++;
			if (p[i].otsinka1 > 3 and p[i].otsinka2 > 3 and p[i].otsinkaCM > 3)
			{
				k++;
			}
		}
	}
	return k;
}
double nsOpr::LineSearch2(Student* p)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == ME, MF, FI)
		{
			n++;
			if (p[i].otsinka1 > 3 and p[i].otsinka2 > 3 and p[i].otsinkaPD > 3)
			{
				k++;
			}
		}
	}
	return k;
}
double nsOpr::Line(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == KN)
		{
			n++;
			if (((p[i].otsinka1 + p[i].otsinka2 > 3 + p[i].otsinkaPR > 3) / 3) < 4)
			{
				k++;
			}
		}
	}
	return (100.0 * k / n);
}
double nsOpr::Line1(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == INF)
		{
			n++;
			if (((p[i].otsinka1 + p[i].otsinka2 > 3 + p[i].otsinkaCM > 3) / 3) < 4)
			{
				k++;
			}
		}
	}
	return 100.0 * k / n;
}
double nsOpr::Line2(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == ME, MF, FI)
		{
			n++;
			if (((p[i].otsinka1 + p[i].otsinka2 > 3 + p[i].otsinkaPD > 3) / 3) < 4)
			{
				k++;
			}
		}
	}
	return 100.0 * k / n;
}
void nsOpr::Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].kurs > p[i1 + 1].kurs)
				||
				(p[i1].kurs == p[i1 + 1].kurs &&
					p[i1].spec > p[i1 + 1].spec)
				||
				(p[i1].kurs == p[i1 + 1].kurs &&
					p[i1].spec == p[i1 + 1].spec &&
					p[i1].prizv < p[i1 + 1].prizv))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}

}
int* nsOpr::IndexSort(Student* p, const int N, char* fname)
{ // використовуємо метод вставки для формування індексного масиву
//
// int i, j, value;
// for (i = 1; i < length; i++) {
// value = a[i];
// for (j = i - 1; j >= 0 && a[j] > value; j--) {
// a[j + 1] = a[j];
// }
// a[j + 1] = value;
// }
	int* I = new int[N]; // створили індексний масив
	for (int i = 0; i < N; i++)
		I[i] = i; // заповнили його початковими даними
	int i, j, value; // починаємо сортувати масив індексів
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 && (p[I[j]].kurs > p[value].kurs)
			||
			(p[I[j]].kurs == p[value].kurs &&
				p[I[j]].spec > p[value].spec)
			||
			(p[I[j]].kurs == p[value].kurs &&
				p[I[j]].spec == p[value].spec &&
				p[I[j]].prizv < p[value].prizv);
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
		ofstream g(fname, ios::binary);

		for (int i = 0; i < N; ++i)
			g << I[i] << " ";
		g.close();
	}
	return I;
}
int nsOpr::BinSearch(Student* p, const int N, const string prizv, const Kurs kurs, const Spec spec)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
	fstream f("1.dat", ios::binary);
	int x;
	Student stud;
	f.read((char*)&stud, sizeof(Student));

	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].prizv == prizv && p[m].kurs == kurs && p[m].spec == spec)
			return m;
		if ((p[m].kurs < kurs)
			||
			(p[m].kurs == kurs &&
				p[m].prizv < prizv)
			||
			(p[m].kurs == kurs &&
				p[m].prizv < prizv &&
				p[m].spec < spec))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}