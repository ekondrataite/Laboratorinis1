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
    studentas eilute;
    cout << "Iveskite varda ir pavarde: ";
    cin >> eilute.vardas >> eilute.pavarde;

    float n;
    cout << "Iveskite semestro pazymius: ";
    while (cin >> n)
        eilute.pazymiai.push_back(n);
}