
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include "var.h"
#include "form.h"

using namespace std;
using namespace nsForm;
using namespace nsVar;
void nsForm::Create2()
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