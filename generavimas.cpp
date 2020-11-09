#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <string>
#include <chrono>

using namespace std;

#include "funkcijos.h"
#include "strukturos.h"

//komparatoriai reikalingi rusiavimui;

bool compareV(studentas a, studentas b) {
    return a.vardas < b.vardas;
}
bool compareP(studentas a, studentas  b) {
    return a.pavarde < b.pavarde;
}

list<studentas> failo_nuskaitymas() {

	fstream failas;

	string f;

	do {
		try {
			cout << "Iveskite failo pavadinima: " << endl;
			cin >> f;
			failas.open(f);

			if (failas.fail())
			{
				throw runtime_error("Failas nerastas");
			}
		}
		catch (runtime_error& e) {
			cout << "Klaida! Failas nerastas. Iveskite egzistuojanti failo pavadinima" << endl;
			cout << "Jusu ivestis: " << f << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	} while (failas.fail());

	int rows = 0, cols = 0;
	string eilute, reiksme;
	string vardas1, pavarde1, vardas, pavarde;
	string rez;
	vector<string> rezultatai1;
	vector<string> rezultatai;
	list<studentas> grupe;
	float galutinis;

	//suzinome kiek yra eiluciu ir stulpeliu
	while (getline(failas, eilute)) {
		rows++;
		if (rows == 1) {
			stringstream ss(eilute);
			while (ss >> reiksme) {
				cols++;
			}
		}
	}
	failas.close();

	failas.open(f);

	if (failas.is_open()) {
		//nuskaitomos failo duomenu etiketes
		for (int i = 0; i < 1; i++) {
			failas >> vardas1 >> pavarde1;

			for (int j = 0; j < cols - 2; j++) {
				failas >> rez;
				rezultatai1.push_back(rez);
			}
			rezultatai1.clear();
			vector<string>().swap(rezultatai1);
		}

		//nuskaitomi failo duomenys
		for (int i = 1; i < rows; i++) {
			failas >> vardas >> pavarde >> galutinis;

			grupe.push_back(studentas{ vardas, pavarde, galutinis});

		}
	}
	failas.close();
	return grupe;
}

void irasymas(vector<studentas> sarasas) {
	auto startas = chrono::high_resolution_clock::now();

	fstream failas;

	string pavadinimas;
	cout << "Iveskite failo, i kuri irasysite duomenis, pavadinima" << endl;
	cin >> pavadinimas;

	failas.open(pavadinimas);

	failas << left << setw(30) << "Vardas" << setw(30) << "Pavarde" << setw(30) << "Galutinis balas (vidurkis)" << endl;

	for (int i = 0; i < sarasas.size(); i++) {
		failas << left << setw(30) << sarasas[i].vardas << setw(30) << sarasas[i].pavarde << setw(30) << fixed << setprecision(2) << sarasas[i].galutinis << endl;
	}

	failas.close();
	sarasas.clear();

	auto baigta = chrono::high_resolution_clock::now();
	chrono::duration<double> skirtumas = baigta - startas;

	cout << "Failo irasymas truko: " << skirtumas.count() << "s" << endl;
}