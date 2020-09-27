// pirmaVektoriai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    std::vector<int> pazymiai;
    float egzaminas;
    float galutinis;
};

int main()
{
    vector<studentas> grupe;
    studentas laikinas;
    int n = 0;

    cout << "Iveskite studentu, kuriu duomenis pildysite, skaiciu: ";
    cin >> n;
    grupe.reserve(n);

    vector<int> pazymiai;

    for (int i = 0; i < n; i++) {
        cout << "Iveskite studento varda, pavarde, egzamino ivertinima: " << endl;
        cin >> laikinas.vardas >> laikinas.pavarde >> laikinas.egzaminas;

        grupe.push_back(laikinas);

        cout << "Iveskite studento semestro namu darbu pazymius" << endl;
        cout << "Suvede visus pazymius, suveskite 'end' ir spauskite Enter" << endl;
        
    }

    cout << "Ivesti duomenys" << endl;
    cout << "--------------------------" << endl;
    for (auto &g : grupe) {
        cout << g.vardas << " " << g.pavarde << " " << g.egzaminas << endl;
    }
    grupe.clear();

}