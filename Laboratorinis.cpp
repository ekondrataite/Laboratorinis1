
#include "biblioteka.h"
#include "strukturos.h"
#include "funkcijos.h"

int main()
{
	string pasirinkimas;
	do {
		try {
			cout << "Ar norite duomenis ivesti ar nuskaityti is failo?" << endl;
			cout << "Iveskite 'Nuskaityti', jei duomenis nuskaitysite is failo" << endl;
			cout << "Iveskite 'Ivesti', jei ranka ivesite duomenis" << endl;
			cin >> pasirinkimas;

			if (pasirinkimas != "Nuskaityti" && pasirinkimas != "Ivesti")
			{
				throw runtime_error("Klaidinga ivestis! Reikia ivesti 'Nuskaityti' arba 'Ivesti'");
			}
		}
		catch (runtime_error& x) {
			cout << x.what() << endl;
			cout << "Jusu ivestis: " << pasirinkimas << endl;
		}
	} while (pasirinkimas != "Nuskaityti" && pasirinkimas != "Ivesti");

	vector<studentas> grupe;
	studentas laikinas;

	if (pasirinkimas == "Nuskaityti") {

		ofstream mano_failas;
		fstream failas;

		string f;

		do {
			try {
				cout << "Iveskite failo pavadinima (faila nurodykite su .txt gale)" << endl;
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
		int n;
		//jei naudojama '!isdigit()' net ivedus teigiama skaiciu programa praso vel ivesti reiksme ir neleidzia toliau vykdyti programos.
		do {
			try {
				cout << "Iveskite studentu, kuriu duomenis pildysite, skaiciu: ";
				cin >> n;

				if (n < 0)
				{
					throw runtime_error("Ivestis turi buti teigiamas skaicius");
				}
			}
			catch (runtime_error& e) {
				cout << "Studentu skaicius turi buti teigiamas skaicius!" << endl;
				cout << "Jusu ivestis: " << n << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} while (n < 0);

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

			if (a == "Ne") {

				do {
					try {
						cout << "Iveskite studento egzamino ivertinima: " << endl;
						cin >> laikinas.egzaminas;

						if (laikinas.egzaminas < 0 || laikinas.egzaminas >= 11) {
							throw runtime_error("Klaidinga ivestis! Reikia ivesti skaiciu 10-baleje sistemoje");
						}
					}
					catch (runtime_error& x) {
						cout << x.what() << endl;
						cout << "Jusu ivestis: " << laikinas.egzaminas << endl;
					}
				} while (laikinas.egzaminas < 0 || laikinas.egzaminas >= 11);
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
			}
		}

		//pasirenkama pagal ka rusiuoti ir su rusiuojama;

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
			sort(grupe.begin(), grupe.end(), compareV);
		}
		else if (p == "P") {
			sort(grupe.begin(), grupe.end(), compareP);
		}
		spausdinimas(grupe);
	}
}


