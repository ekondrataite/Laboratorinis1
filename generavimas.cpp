#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <string>

using namespace std;

#include "funkcijos.h"
#include "strukturos.h"

float vidurkis(vector<int> pazymiai) {
    int dydis = pazymiai.size();

    return accumulate(pazymiai.begin(), pazymiai.end(), 0.000) / dydis;
}

float galutinis_balas(int egzaminas, float vidurkis) {
    return 0.4 * vidurkis + 0.6 * egzaminas;
}

vector<int> pazymiu_generavimas(int kiekis){
    vector<int> pazymiai(kiekis);
    
    random_device random;
    mt19937 generuoja(random());

    uniform_int_distribution<> d(1, 10);
    //This distribution produces random integers in a range [a,b] where each possible value has an equal likelihood of being produced.

    generate(pazymiai.begin(), pazymiai.end(), [&]() { return d(generuoja); });
    return pazymiai;
}

vector<studentas> studentu_generavimas(int kiekis) {

    int pazymiai;
    cout << "Iveskite kiek pazymiu kiekvienam studentui turi buti generuojama" << endl;
    cin >> pazymiai;

    vector<studentas> sarasas;

    for (int i = 0; i < kiekis; i++) {
        studentas laikinas;

        srand(time(0));

        laikinas.vardas = "Vardenis" + to_string(i);
        laikinas.pavarde = "Pavardenis" + to_string(i);
        laikinas.pazymiai = pazymiu_generavimas(pazymiai);
        laikinas.egzaminas = rand() % 10;
        laikinas.galutinis = galutinis_balas(laikinas.egzaminas, vidurkis(laikinas.pazymiai)); //pasirinkta, kad galutinis balas bus skaiciuojamas tik su vidurkiu.

        sarasas.push_back(laikinas);
    }
    return sarasas;
}


