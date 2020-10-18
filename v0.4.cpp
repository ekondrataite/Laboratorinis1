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

#include "strukturos.h"
#include "funkcijos.h"
#include "generavimas.h"

void spausdinimas(vector<studentas> grupe) {
    cout << left << setw(30) << "Vardas" << setw(30) << "Pavarde" << setw(30) << "Galutinis balas (vidurkis)" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        cout << left << setw(30) << grupe[i].vardas << setw(30) << grupe[i].pavarde << setw(30) << fixed << setprecision(2) << grupe[i].galutinis << endl;
    }
    grupe.clear();
}

int main()
{
    int studentu_sk;
    cout << "Iveskite kiek studentu norite sugeneruoti" << endl;
    cin >> studentu_sk;

    spausdinimas(studentu_generavimas(studentu_sk));
}
