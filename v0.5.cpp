// v0.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <list>

using namespace std;

#include "strukturos.h"
#include "funkcijos.h"

int main()
{
	string x;
	do {
		try {
			cout << "Ar norite studentu faila sugrupuoti i 'vargsiukus' ir 'kietiakus'?" << endl;
			cout << "Iveskite 'Taip' arba 'Ne'" << endl;
			cin >> x;

			if (x != "Taip" && x != "Ne") {
				throw runtime_error("Klaidinga ivestis! Reikia ivesti 'V' arba 'P'");
			}
		}
		catch (runtime_error& e) {
			cout << e.what() << endl;
			cout << "Jusu ivestis: " << x << endl;
		}
	} while (x != "Taip" && x != "Ne");

	if (x == "Taip") {

		auto startas1 = chrono::high_resolution_clock::now();

		list<studentas> sarasas = failo_nuskaitymas();

		auto baigta1 = chrono::high_resolution_clock::now();
		chrono::duration<double> skirtumas1 = baigta1 - startas1;
		cout << "Duomenu is failo nuskaitymas uztruko: " << skirtumas1.count() << "s" << endl;

		auto startas2 = chrono::high_resolution_clock::now();

		vector<vargsiukai> varg;
		vector<kietiakai> kiet;

		for (studentas& s : sarasas) {
			if (s.galutinis < 5) {
				varg.push_back(vargsiukai{ s.vardas, s.pavarde, s.galutinis });
			}
			else if (s.galutinis >= 5) {
				kiet.push_back(kietiakai{ s.vardas, s.pavarde, s.galutinis });
			}
		}

		auto baigta2 = chrono::high_resolution_clock::now();
		chrono::duration<double> skirtumas2 = baigta2 - startas2;
		cout << "Studentu suskirstymas i dvi grupes uztruko: " << skirtumas2.count() << "s" << endl;

	}
	else {
		return 1;
	}
}
