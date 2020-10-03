// pirmaVektoriai.cpp : This file contains the 'main' function. Program execution begins and ends there.
// github: https://github.com/ekondrataite/v.01-su-vektoriais
//

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

struct studentas {
	string vardas;
	string pavarde;
	vector<int> pazymiai;
	float egzaminas;
};

//funkcijos reikalingos galutinio balo apskaiciavimui;

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

//failo nuskaitymui

void skaityti_faila() {
	ifstream failas("kursiokai.txt");
	if (!failas.is_open()) {
		cout << "Klaida! Failas nenuskaitytas";
	}
	string mytext;
	getline(failas, mytext);
	while (getline(failas, mytext)) {
		vector<string> rezultatas;
		stringstream iss(mytext);
		for (string s; iss >> s;) {
			rezultatas.push_back(s);
			//cout << s << endl;
		}
	}
}

//duomenu spausdinimas

void spausdinimas(vector<studentas> grupe) {
	cout << "Iseitis" << endl;
	cout << left << setw(30) << "Vardas" << setw(30) << "Pavarde" << setw(30) << "Galutinis balas (vidurkis)" << setw(35) << "Galutinis balas (mediana)" << endl;
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	for (auto& g : grupe) {
		cout << left << setw(30) << g.vardas << setw(30) << g.pavarde << setw(30) << galutinis_balas(g.egzaminas, vidurkis(g.pazymiai)) << setw(30);
		cout << setw(30) << galutinis_balas(g.egzaminas, mediana(g.pazymiai)) << endl;
		g.pazymiai.clear();
	}
	grupe.clear();
}

int main()
{
	cout << "Ar norite duomenis ivesti ar nuskaityti is failo?" << endl;
	cout << "Iveskite 'Nuskaityti', jei duomenis nuskaitysite is failo" << endl;
	cout << "Iveskite 'Ivesti', jei ranka ivesite duomenis" << endl;

	string pasirinkimas;
	cin >> pasirinkimas;

	vector<studentas> grupe;
	studentas laikinas;

	//failo nuskaitymas

	if (pasirinkimas == "Nuskaityti") {
		//skaityti_faila(); 
		ofstream mano_failas;
		fstream failas;

		string f = "studentai10000.txt";

		failas.open(f);

		int rows = 0, cols = 0;
		string eilute, reiksme;
		string vardas1, pavarde1, vardas, pavarde;
		string rez;
		vector<string> rezultatai1;
		vector<string> rezultatai;
		vector<studentas> grupe;
		vector<int> laikinas;

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

		if (failas.fail()) {
			perror(nullptr);
			return 1;
		}

		else {
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
				failas >> vardas >> pavarde;

				for (int j = 0; j < cols - 2; j++) {

					failas >> rez;
					rezultatai.push_back(rez);

					for (int i = 0; i < rezultatai.size(); i++) {
						
						laikinas.push_back(stoi(rezultatai[i]));

						rezultatai.clear();
						vector<string>().swap(rezultatai);
					}
				}

				grupe.push_back(studentas{vardas, pavarde, laikinas});

				laikinas.clear();
			}

			//rusiavimas

			cout << "Iveskite kaip norite rusiuoti duomenis:" << endl;
			cout << "Jei rusiuosite pagal vardus iveskite 'V'" << endl;
			cout << "Jei rusiuosite pagal pavardes iveskite 'P'" << endl;

			string p;
			cin >> p;

			if (p == "V") {
				sort(grupe.begin(), grupe.end(), compareV);
			}
			else if (p == "P") {
				sort(grupe.begin(), grupe.end(), compareP);
			}

			//spausdinimas(grupe);

			//suvedimas i faila

			mano_failas.open("kursiokai.txt");

			if (mano_failas.fail())
			{
				perror(nullptr);
				return 1;
			}

			else {
				mano_failas << left << setw(30) << "Vardas" << setw(30) << "Pavarde" << setw(30) << "Galutinis balas (vidurkis)" << setw(35) << "Galutinis balas (mediana)" << endl;
				mano_failas << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < grupe.size(); i++) {
					mano_failas << left << setw(30) << grupe[i].vardas << setw(30) << grupe[i].pavarde << setw(30) << galutinis_balas(grupe[i].pazymiai.back(), vidurkis(grupe[i].pazymiai)) << setw(30);
					mano_failas << galutinis_balas(grupe[i].pazymiai.back(), mediana(grupe[i].pazymiai)) << endl;
					grupe[i].pazymiai.clear();
				}
				mano_failas.close();
				grupe.clear();
			}
		}

	}

	//duomenu suvedimas ranka;

	if (pasirinkimas == "Ivesti") {
		int n = 0;

		cout << "Iveskite studentu, kuriu duomenis pildysite, skaiciu: ";
		cin >> n;

		grupe.reserve(n);

		for (int i = 0; i < n; i++) {
			cout << "Iveskite studento varda, pavarde, egzamino ivertinima: " << endl;
			cin >> laikinas.vardas >> laikinas.pavarde >> laikinas.egzaminas;

			cout << "Iveskite studento semestro namu darbu pazymius." << endl;
			cout << "Suvede visus pazymius, suveskite 'end' ir spauskite Enter" << endl;

			laikinas.pazymiai.reserve(50);
			string input = "";
			while (input != "end") {

				cin >> input;
				if (input == "end") {
					break;
				}
				laikinas.pazymiai.push_back(stoi(input));
			}
			grupe.push_back(laikinas);

			cout << "Studentas: " << laikinas.vardas << " " << laikinas.pavarde << endl;
			cout << "Egzamino ivertinimas: " << laikinas.egzaminas << endl;
			cout << "Semestro namu darbu pazymiai: ";
			for (auto& p : laikinas.pazymiai) {
				cout << p << " ";
			}
			cout << endl;
		}

		//pasirenkama pagal ka rusiuoti ir su rusiuojama;

		cout << "Iveskite kaip norite rusiuoti duomenis:" << endl;
		cout << "Jei rusiuosite pagal vardus iveskite 'V'" << endl;
		cout << "Jei rusiuosite pagal pavardes iveskite 'P'" << endl;

		string p;
		cin >> p;

		if (p == "V") {
			sort(grupe.begin(), grupe.end(), compareV);
		}
		else if (p == "P") {
			sort(grupe.begin(), grupe.end(), compareP);
		}

		spausdinimas(grupe);
	}
}