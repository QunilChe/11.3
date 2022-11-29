#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>

#include "vivid.h"
#include "var.h"
using namespace std;
using namespace nsVivid;
using namespace nsVar;
void nsVivid::Print()
{
	ofstream g(fname);

	g << "========================================================================="
		<< endl;
	g << "| No | ������� | г�.���. | kyrs | spec | fizyka | matematika | informatika | ������������� |��������� ������ |��������� | "
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