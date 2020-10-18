#include <chrono>

using namespace std;

#include "strukturos.h"
#include "funkcijos.h"
#include "generavimas.h"

int main()
{
    int studentu_sk;
    cout << "Iveskite kiek studentu norite sugeneruoti" << endl;
    cin >> studentu_sk;

	auto startas1 = chrono::high_resolution_clock::now();

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

	irasymas(sarasas);

	auto baigta1 = chrono::high_resolution_clock::now();
	chrono::duration<double> skirtumas1 = baigta1 - startas1;

	cout << "Faila sukurti uztruko: " << skirtumas1.count() << "s" << endl;

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

		auto startas2 = chrono::high_resolution_clock::now();

		vector<studentas> sarasas = failo_nuskaitymas();

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

		auto baigta2 = chrono::high_resolution_clock::now();
		chrono::duration<double> skirtumas2 = baigta2 - startas2;

		cout << "Studentu rusiavimas i dvi grupes uztruko: " << skirtumas2.count() << "s" << endl;

		auto startas3 = chrono::high_resolution_clock::now();

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

		auto baigta3 = chrono::high_resolution_clock::now();
		chrono::duration<double> skirtumas3 = baigta3 - startas3;

		cout << "Studentu isvedimas i naujus failus uztruko: " << skirtumas3.count() << "s" << endl;

		vargsiukai.close();
		kietiakai.close();

	}
	else {
		return 1;
	}
}


