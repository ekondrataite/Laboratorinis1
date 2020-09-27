// pirmaVektoriai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct studentas {
	string vardas;
	string pavarde;
	std::vector<int> pazymiai;
	float egzaminas;
	float galutinis;
};

float vidurkis(vector<int> pazymiai) {
	int suma = 0;
	int dydis = pazymiai.size();

	for (int i = 0; i < dydis; i++) {
		suma += pazymiai[i];
	}
	return suma / dydis;
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

float galutinis_balas(float vidurkis, int egzaminas) {
	return 0.4 * vidurkis + 0.6 * egzaminas;
}

int main()
{
	vector<studentas> grupe;
	studentas laikinas;
	int n = 0;

	cout << "Iveskite studentu, kuriu duomenis pildysite, skaiciu: ";
	cin >> n;

	grupe.reserve(n);

	for (int i = 0; i < n; i++) {
		cout << "Iveskite studento varda, pavarde, egzamino ivertinima: " << endl;
		cin >> laikinas.vardas >> laikinas.pavarde >> laikinas.egzaminas;

		cout << "Iveskite studento semestro namu darbu pazymius" << endl;
		cout << "Suvede visus pazymius, suveskite 'end' ir spauskite Enter" << endl;

		laikinas.pazymiai.reserve(50);
		string input = "";
		while (input != "end") {

			cin >> input;
			if (input == "end") {
				break;
			}
			laikinas.pazymiai.push_back(std::stoi(input));
		}
		grupe.push_back(laikinas);

		cout <<"Studentas: " << laikinas.vardas << " " << laikinas.pavarde << endl;
		cout << "Egzamino ivertinimas: " << laikinas.egzaminas << endl;
		cout << "Semestro namu darbu pazymiai: ";
		for (auto& p : laikinas.pazymiai) {
			cout << p << " ";
		}
		cout << endl;
	}

	cout << "Iseitis" << endl;
	cout << "--------------------------" << endl;
	for (auto& g : grupe) {		
		cout << g.vardas << " " << g.pavarde << " Gal.Vid: " << galutinis_balas(vidurkis(g.pazymiai), g.egzaminas);
		cout << " Gal.Med: " << galutinis_balas(mediana(g.pazymiai), g.egzaminas) << endl;
		g.pazymiai.clear();
	}
	grupe.clear();

}
