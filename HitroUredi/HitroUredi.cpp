// HitroUredi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

void Meni() {
	cout << endl << endl;
	cout << "Hitro uredi-izbira: \n \n";
	cout << "1 Generiraj nakljucno zaporedje \n";
	cout << "2 Generiraj urejeno narascajoce zaporedje \n";
	cout << "3 Generiraj urejeno padajoce zaporedje \n";
	cout << "4 Izpis zaporedja \n";
	cout << "5 Uredi \n";
	cout << "6 Konec \n";
	cout << endl;
	cout << "Vasa izbira: ";
}
void Preveri(int p[], int dno, int vrh) {
	for (int i = dno; i < vrh - 1; i++) {
		if (p[i + 1] < p[i]) {
			cout << endl;
			cout << "Polje je napacno urejeno!" << endl;
			break;
		}
	}
}
void Izpis(int p[], int velikostPolja) {
	for (int i = 0; i < velikostPolja; i++) {
		cout << p[i] << "\t";
	}
}
void Swap(int &a, int &b) {
	int temp = a;
	a = b; 
	b = temp;
}
int Deli(int p[], int dno, int vrh) {
	int mediana = (dno + vrh) / 2;
	int l = dno;
	int d = vrh;
	Swap(p[mediana], p[l]);
	int primerjalniEl = p[l];
	
		while (l < d) {
			while (p[l] <= primerjalniEl && l < vrh) {
				l++;
			}
			while (p[d] > primerjalniEl && d >dno) {
				d--;
			}
			if (l < d) {
				Swap(p[l], p[d]);
			}
		}
		Swap(p[dno], p[d]);
			
	
	return d;
}

void HitroUredi(int p[], int dno, int vrh) {
	if (dno < vrh) {
		int delilni_i = Deli(p, dno, vrh);
		HitroUredi(p, dno, delilni_i - 1);
		HitroUredi(p, delilni_i + 1, vrh);
	}
}

void VpisPodatkov(int p[], int velikost) {
	srand(time(NULL));
	for (int i = 0; i < velikost; i++) {
		p[i] = rand() % 1000000 + 1;
	}
}
void Gen_Nara_Zaporedje(int p[], int velikost) {
	VpisPodatkov(p, velikost);
	HitroUredi(p, 0, velikost - 1);
}
void ObrniZaporedje(int p[], int velikost) {
	int k = velikost - 1;
	for (int i = 0; i < k; i++) {
		Swap(p[i], p[k]);
		k--;
	}
}
void Gen_Pada_Zaporedje(int p[], int velikost) {
	VpisPodatkov(p, velikost);
	HitroUredi(p, 0,velikost-1);
	ObrniZaporedje(p, velikost);
}

int main()
{
	int* p = new int[100000000];
	int izbira_menu, dno, vrh, velikost;
	clock_t start, finish;
	double duration = 0;;

	do {
		Meni();
		cin >> izbira_menu;

		switch (izbira_menu)
		{
		case 1:
			//Vnos nakljuènega zaporedja
			cout << "Vnesi velikost polja: ";
			cin >> velikost;
			VpisPodatkov(p, velikost);
			cout << endl;

			break;
		case 2:
			//Narašèujoèe zaporedje
			cout << "Vnesi velikost polja: ";
			cin >> velikost;
			Gen_Nara_Zaporedje(p, velikost);

			break;
		case 3:
			//Padajoèe zaporedje
			cout << "Vnesi velikost polja: ";
			cin >> velikost;
			Gen_Pada_Zaporedje(p, velikost);
			break;

		case 4: 
			//Izpis zaporedja
			cout << "Zaporedje: " << endl;
			Izpis(p, velikost);
			cout << endl;
			break;
		case 5:
			//Zaèetek urejanja
			start = clock();
			HitroUredi(p, 0, velikost-1);
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			//cout << "Zaporedje je urejeno!" << endl;
			//Izpis(p, velikost);
			Preveri(p, 0, velikost);

			break;

		case 6:
			cout << "Cas trajanja urejanja: " << duration << "s";
			return 0;
		default:
			break;
		}
	} while (izbira_menu !=6);

	system("pause");
    return 0;
}

