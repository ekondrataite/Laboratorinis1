// pirmaVektoriai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    std::vector<int> pazymiai;
    float egzaminas;
    float galutinis;
};

float galutinis_balas(vector<int> pazymiai, int egzaminas) {
    int suma = 0;
    int dydis = pazymiai.size();

    for (int i = 0; i < dydis; i++) {
        suma += pazymiai[i];
    }

    float vidurkis = suma / dydis;

    float galutinis = 0.4 * vidurkis + 0.6 * egzaminas;

    return galutinis;
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
            if (input == "end"){
                break;
            }
            laikinas.pazymiai.push_back(std::stoi(input));
        }
        grupe.push_back(laikinas);
    }

    cout << "Ivesti duomenys" << endl;
    cout << "--------------------------" << endl;
    for (auto &g : grupe) {
        cout << "Studentas: " << g.vardas << " " << g.pavarde << endl;
        cout << "Egzamino ivertinimas: " << g.egzaminas << endl;
        cout << "Semestro namu darbu pazymiai: ";
        for (auto& p : g.pazymiai) {
            cout << p << " ";
        }
        cout << endl;
        cout << "Galutinis balas: " << galutinis_balas(g.pazymiai, g.egzaminas) << endl;
        g.pazymiai.clear();
    }
    grupe.clear();

}