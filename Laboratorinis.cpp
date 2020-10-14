// pirmaVektoriai.cpp : This file contains the 'main' function. Program execution begins and ends there.
// github: https://github.com/ekondrataite/Laboratorinis
//
#include "biblioteka.h"
#include "strukturos.h"
#include "funkcijos.h"

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

		string f;
		cout << "Iveskite failo pavadinima (faila nurodykite su .txt gale)" << endl;
		cin >> f;

		failas.open(f);

		int rows = 0, cols = 0;
		string eilute, reiksme;
		string vardas1, pavarde1, vardas, pavarde;
		string rez;
		vector<string> rezultatai1;
		vector<string> rezultatai;
		vector<studentas> grupe;
		vector<int> laikinas;

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

				grupe.push_back(studentas{ vardas, pavarde, laikinas });

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
					mano_failas << left << setw(30) << grupe[i].vardas << setw(30) << grupe[i].pavarde << setw(30) << fixed << setprecision(2) << galutinis_balas(grupe[i].pazymiai.back(), vidurkis(grupe[i].pazymiai)) << setw(30);
					mano_failas << fixed << setprecision(2) << galutinis_balas(grupe[i].pazymiai.back(), mediana(grupe[i].pazymiai)) << endl;
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
			cout << "Iveskite studento varda, pavarde: " << endl;
			cin >> laikinas.vardas >> laikinas.pavarde;

			cout << "Ar egzamino ivertinima sugeneruoti automatiskai? " << endl;
			cout << "Iveskite 'Taip' arba 'Ne'" << endl;

			string a;
			cin >> a;


			if (a == "Taip") {
				srand(time(NULL));
				int sugeneruotas = rand() % 10 + 1;
				laikinas.egzaminas = sugeneruotas;

				cout << "Sugeneruotas egzamino ivertinimas: " << sugeneruotas << endl;
			}

			cout << "Ar semestro namu darbu ivertinimus sugeneruoti automatiskai? " << endl;
			cout << "Iveskite 'Taip' arba 'Ne'" << endl;

			string b;
			cin >> b;

			if (b == "Taip") {
				while (true) {
					srand(time(0));
					int sugeneruotas = rand() % 10 + 1;
					laikinas.pazymiai.push_back(sugeneruotas);

					cout << "Sugeneruotas ivertinimas: " << sugeneruotas << endl;

					cout << "Ar norite sugeneruoti dar viena pazymi?" << endl;
					cout << "Iveskite 'Taip' arba 'Ne'" << endl;

					string c;
					cin >> c;

					if (c == "Ne") {
						break;
					}
				}
				grupe.push_back(laikinas);
			}

			if (b == "Ne") {
				cout << "Iveskite studento egzamino ivertinimas: " << endl;
				cin >> laikinas.egzaminas;

				cout << "Iveskite studento semestro namu darbu pazymius." << endl;
				cout << "Suvede visus pazymius, suveskite 'end' ir spauskite Enter" << endl;

				string input;

				laikinas.pazymiai.reserve(50);

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