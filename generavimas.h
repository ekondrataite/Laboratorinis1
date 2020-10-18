#pragma once
#include "funkcijos.h"
#include "strukturos.h"

vector<int> pazymiu_generavimas(int skaicius);
vector<studentas> studentu_generavimas(int kiekis);

bool compareV(studentas a, studentas b);
bool compareP(studentas a, studentas  b);

vector<studentas> failo_nuskaitymas();
void irasymas(vector<studentas> sarasas);