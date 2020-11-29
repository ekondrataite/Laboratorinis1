// v0.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <list>

using namespace std;

#include "strukturos.h"
#include "funkcijos.h"

int main()
{
	string pasirinkimas;
	do {
		try {
			cout << "Pasirinkite koki konteineri norite naudoti grupavimui" << endl;
			cout << "Iveskite 'vector' arba 'list'." << endl;
			cin >> pasirinkimas;

			if (pasirinkimas != "vector" && pasirinkimas != "list") {
				throw runtime_error("Klaidinga ivestis! Reikia ivesti 'vector' arba 'list'");
			}
		}
		catch (runtime_error& e) {
			cout << e.what() << endl;
			cout << "Jusu ivestis: " << pasirinkimas << endl;
		}
	} while (pasirinkimas != "vector" && pasirinkimas != "list");

	if (pasirinkimas == "vector") {
		vector<studentas> sarasas = failo_nuskaitymas_vektorius();

		vector<vargsiukai> varg;

		auto startas2 = chrono::high_resolution_clock::now();

		for (studentas& s : sarasas) {
			if (s.galutinis < 5) {
				varg.push_back(vargsiukai{ s.vardas, s.pavarde, s.galutinis });
			}
		}
		sarasas.erase(remove_if(sarasas.begin(), sarasas.end(), salyga), sarasas.end());

		auto baigta2 = chrono::high_resolution_clock::now();
		chrono::duration<double> skirtumas2 = baigta2 - startas2;
		cout << "Studentu suskirstymas i dvi grupes uztruko: " << skirtumas2.count() << "s" << endl;
		sarasas.clear();
	}

	else if (pasirinkimas == "list") {
		list<studentas> sarasas = failo_nuskaitymas_list();

		list<vargsiukai> varg;

		auto startas2 = chrono::high_resolution_clock::now();

		for (studentas& s : sarasas) {
			if (s.galutinis < 5) {
				varg.push_back(vargsiukai{ s.vardas, s.pavarde, s.galutinis });
			}
		}
		sarasas.remove_if(salyga);

		auto baigta2 = chrono::high_resolution_clock::now();
		chrono::duration<double> skirtumas2 = baigta2 - startas2;
		cout << "Studentu suskirstymas i dvi grupes uztruko: " << skirtumas2.count() << "s" << endl;

		//irasymas(varg);
		sarasas.clear();
	}
	else {
		return 1;
	}
}
