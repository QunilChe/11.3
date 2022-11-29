// кращий спосіб
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
enum Kurs { I = 1, II, III, IV, V, VI };
enum Spec { ME, MF, FI, INF, KN };
string specStr[] = { "математика і економіка", "трудове навчання", "фізика та інформатика", "інформатика", "компютерні науки" }; //були посади стали оцінки

struct Student
{
	string prizv;
	unsigned rikNar;
	unsigned kurs;
	Spec spec;
	union
	{
		int otsinka1;
		int otsinka2;
		int otsinkaPR;
		int otsinkaCM;
		int otsinkaPD;
	};
};
void PrintIndexSorted(Student* p, int* I, const int N);
int BinSearch(Student* p, const int N, const string prizv, const Kurs kurs, const Spec spec);
void Create(Student* p, const int N);
void Print(Student* p, const int N, char* fname);
double LineSearch(Student* p, const int N);
double LineSearch1(Student* p, const int N);
double LineSearch2(Student* p, const int N);
double Line(Student* p, const int N);
double Line1(Student* p, const int N);
void Sort(Student* p, const int N );
double Line2(Student* p, const int N);
int* IndexSort(Student* p, const int N, char* fname);
void Create2(char* fname, Student* p)
{
	ofstream f(fname, ios::binary);
	char ch;
	Student stud;
	do
	{
		cout << endl;
		cout << "name: "; cin.sync();
		cin >> stud.prizv;
		cout << "age: "; cin >> stud.rikNar;
		cout << "salary: "; cin >> stud.kurs;
		switch (stud.spec)
		{
		case KN:
			cout << " otsinka3 : "; cin >> stud.otsinka1;
			cout << " otsinka3 : "; cin >> stud.otsinka2;
			cout << " otsinka3 : "; cin >> stud.otsinkaPR;
			break;
		case INF:
			cout << " otsinka3 : "; cin >> stud.otsinka1;
			cout << " otsinka3 : "; cin >> stud.otsinka2;
			cout << " otsinka3 : "; cin >> stud.otsinkaCM;
			break;
		case ME:
		case MF:
		case FI:
			cout << " otsinka3 : "; cin >> stud.otsinka1;
			cout << " otsinka3 : "; cin >> stud.otsinka2;
			cout << " otsinka3 : "; cin >> stud.otsinkaPD;
			break;
		}
		cout << endl;
		cout << "Continue? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}
int main()
{
	double proc;
	int ispec;
	int ikurs;
	Kurs kurs;
	Spec spec;
	string prizv;
	int found;
	char fname[100]; // ім'я першого файлу
	cout << "enter file name 1: "; cin >> fname;
	char fname2[100]; // ім'я першого файлу
	cout << "enter file name 2: "; cin >> fname2;
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	int N;
	cout << "Введіть N: "; cin >> N;
	Student* p = new Student[N];
	//Create(p, N);
	Create2(fname2, p);

	Print(p, N, fname);
	double hg = LineSearch(p, N);
	double cg = LineSearch1(p, N);
	double rg = LineSearch2(p, N);
	int gg = (hg + cg + rg);

	double hj = LineSearch(p, N);
	double cj = LineSearch1(p, N);
	double rj = LineSearch2(p, N);
	int gj = (hj + cj + rj);
	cout << "кількість студентів, які вчаться без трійок:" << gg << endl;
	cout << "процент студентів, у яких середній бал менший 4:" << gj << endl;
	return 0;
	//Sort(p, N);

	IndexSort(p, N, fname);

	//PrintIndexSorted(p, IndexSort(p, N, fname), N);
	cout << "Введіть ключі пошуку:" << endl;
	cout << " посада (0 - робітник, 1 - інженер, 2 - службовець): ";
	cin >> ikurs;
	kurs = (Kurs)ikurs;
	cout << "Введіть ключі:" << endl;
	cin >> ispec;
	spec = (Spec)ispec;
	cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
	cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
	cout << " прізвище: "; getline(cin, prizv);
	cout << endl;
	if ((found = BinSearch(p, N, prizv, kurs, spec)) != -1)
		cout << "Знайдено працівника в позиції " << found + 1 << endl;
	else
		cout << "Шуканого працівника не знайдено" << endl;

	
}
void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "stydent No " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " рік нар.: "; cin >> p[i].rikNar;
		cout << " курс.:    "; cin >> p[i].kurs;
		cout << " spec (0 - робітник, 1 - інженер, 2 - службовець): ";
		cin >> spec;
		p[i].spec = (Spec)spec;

		switch (p[i].spec)
		{
		case KN:
			cout << " otsinka3 : "; cin >> p[i].otsinka1;
			cout << " otsinka3 : "; cin >> p[i].otsinka2;
			cout << " otsinka3 : "; cin >> p[i].otsinkaPR;
			break;
		case INF:
			cout << " otsinka3 : "; cin >> p[i].otsinka1;
			cout << " otsinka3 : "; cin >> p[i].otsinka2;
			cout << " otsinka3 : "; cin >> p[i].otsinkaCM;
			break;
		case ME:
		case MF:
		case FI:
			cout << " otsinka3 : "; cin >> p[i].otsinka1;
			cout << " otsinka3 : "; cin >> p[i].otsinka2;
			cout << " otsinka3 : "; cin >> p[i].otsinkaPD;
			break;
		}
		cout << endl;

	}
}
void Print(Student* p, const int N, char* fname)
{
	ofstream g(fname);

	g << "========================================================================="
		<< endl;
	g << "| No | Прізвище | Рік.нар. | kyrs | spec | fizyka | matematika | informatika | програмування |чисельних методів |педагогіки | "
		<< endl;
	g << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		g << "| " << setw(3) << right << i + 1 << " ";
		g << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].rikNar << " ";
		g << "| " << setw(3) << right << p[i].kurs << " ";
		g << "| " << setw(11) << left << specStr[p[i].spec - 1];
		g << "| " << setw(3) << right << p[i].otsinka1 << " ";
		g << "| " << setw(3) << right << p[i].otsinka2 << " ";
		g << "| " << setw(3) << right << p[i].kurs << " ";

		switch (p[i].spec)
		{
		case KN:
			g << "| " << p[i].otsinkaPR << " " << endl;
			break;
		case INF:
			g << "| " << p[i].otsinkaCM << " " << endl;
		case ME:
		case MF:
		case FI:
			g << "| " << p[i].otsinkaPD << " " << endl;
			break;
		}
	}
	g << "========================================================================="
		<< endl;
	g << endl;
	g.close();
}
double LineSearch(Student* p, const int N)
{
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
double LineSearch1(Student* p, const int N)
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
double LineSearch2(Student* p, const int N)
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
double Line(Student* p, const int N)
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
	return 100.0 * k / n;
}
double Line1(Student* p, const int N)
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
double Line2(Student* p, const int N)
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
void Sort(Student* p, const int N)
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
int* IndexSort(Student* p, const int N, char* fname)
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

int BinSearch(Student* p, const int N, const string prizv, const Kurs kurs, const Spec spec)
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