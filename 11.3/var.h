#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
namespace nsVar {
	extern enum Kurs { I = 1, II, III, IV, V, VI };
	extern enum Spec { ME, MF, FI, INF, KN };
	extern struct Student
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
	extern double proc;
	extern int ispec;
	extern int ikurs;
	extern Kurs kurs;
	extern Spec spec;
	extern string prizv;
	extern int found;
	extern char fname[100]; // ім'я першого файлу
	extern char fname2[100]; // ім'я першого файлу
	extern int N;
	extern Student* p = new Student[N];
}