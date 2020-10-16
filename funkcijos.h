#pragma once
#include "biblioteka.h"
#include "strukturos.h"

//funkcijos reikalingos galutinio balo apskaiciavimui;
float vidurkis(vector<int> pazymiai) {
	int dydis = pazymiai.size();
	return accumulate(pazymiai.begin(), pazymiai.end(), 0.000) / dydis;
}

float mediana(vector<int> pazymiai) {
	sort(pazymiai.begin(), pazymiai.end());

	if (pazymiai.size() % 2 == 0) {
		return (pazymiai[pazymiai.size() / 2 - 1] + pazymiai[pazymiai.size() / 2]) / 2;
	}
	else {
		return pazymiai[pazymiai.size() / 2];
	}
}

float galutinis_balas(int egzaminas, float vidurkis) {
	return 0.4 * vidurkis + 0.6 * egzaminas;
}

//komparatoriai reikalingi rusiavimui;

bool compareV(studentas a, studentas b) {
	return a.vardas < b.vardas;
}
bool compareP(studentas a, studentas  b) {
	return a.pavarde < b.pavarde;
}

//duomenu spausdinimas

void spausdinimas(vector<studentas> grupe) {
	cout << "Iseitis" << endl;
	cout << left << setw(30) << "Vardas" << setw(30) << "Pavarde" << setw(30) << "Galutinis balas (vidurkis)" << setw(35) << "Galutinis balas (mediana)" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	for (auto& g : grupe) {
		cout << left << setw(30) << g.vardas << setw(30) << g.pavarde << setw(30) << fixed << setprecision(2) << galutinis_balas(g.egzaminas, vidurkis(g.pazymiai)) << setw(30);
		cout << setw(30) << fixed << setprecision(2) << galutinis_balas(g.egzaminas, mediana(g.pazymiai)) << endl;
		g.pazymiai.clear();
	}
	grupe.clear();
}