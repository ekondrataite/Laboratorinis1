#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <ctime>
#include <cctype>
#include <cstring>
using namespace std;

#include "strukturos.h"
#include "funkcijos.h"
#include "generavimas.h"

int main()
{
    int studentu_sk;
    cout << "Iveskite kiek studentu norite sugeneruoti" << endl;
    cin >> studentu_sk;

    vector<studentas> sarasas = studentu_generavimas(studentu_sk);

	string p;
	do {
		try {
			cout << "Iveskite kaip norite rusiuoti duomenis:" << endl;
			cout << "Jei rusiuosite pagal vardus iveskite 'V'" << endl;
			cout << "Jei rusiuosite pagal pavardes iveskite 'P'" << endl;

			cin >> p;

			if (p != "V" && p != "P") {
				throw runtime_error("Klaidinga ivestis! Reikia ivesti 'V' arba 'P'");
			}
		}
		catch (runtime_error& x) {
			cout << x.what() << endl;
			cout << "Jusu ivestis: " << p << endl;
		}
	} while (p != "V" && p != "P");

	if (p == "V") {
		sort(sarasas.begin(), sarasas.end(), compareV);
	}
	else if (p == "P") {
		sort(sarasas.begin(), sarasas.end(), compareP);
	}

	vector<vargsiukai> varg;
	vector<kietiakai> kiet;

	for (int i = 0; i < sarasas.size(); i++) {
		if (sarasas[i].galutinis < 5) {
			varg.push_back(vargsiukai{ sarasas[i].vardas, sarasas[i].pavarde, sarasas[i].galutinis });
		}
		else if (sarasas[i].galutinis >= 5) {
			kiet.push_back(kietiakai{ sarasas[i].vardas, sarasas[i].pavarde, sarasas[i].galutinis });
		}
	}
	
	ofstream vargsiukai;
	ofstream kietiakai;

	vargsiukai.open("vargsiukai.txt");
	kietiakai.open("kietiakai.txt");

	vargsiukai << left << setw(30) << "Vardas" << setw(30) << "Pavarde" << setw(30) << "Galutinis balas (vidurkis)" << endl;
	
	for (int i = 0; i < varg.size(); i++) {
		vargsiukai << left << setw(30) << varg[i].vardas << setw(30) << varg[i].pavarde << setw(30) << fixed << setprecision(2) << varg[i].galutinis << endl;
	}

	kietiakai << left << setw(30) << "Vardas" << setw(30) << "Pavarde" << setw(30) << "Galutinis balas (vidurkis)" << endl;

	for (int i = 0; i < kiet.size(); i++) {
		kietiakai << left << setw(30) << kiet[i].vardas << setw(30) << kiet[i].pavarde << setw(30) << fixed << setprecision(2) << kiet[i].galutinis << endl;
	}

	vargsiukai.close();
	kietiakai.close();
}
