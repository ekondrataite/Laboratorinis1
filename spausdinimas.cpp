#include "biblioteka.h"

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