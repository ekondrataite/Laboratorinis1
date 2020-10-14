#include "biblioteka.h"

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