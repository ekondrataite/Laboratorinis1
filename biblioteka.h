#pragma once
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

struct studentas {
	string vardas;
	string pavarde;
	vector<int> pazymiai;
	float egzaminas;
};

float vidurkis(vector<int>);

float mediana(vector<int>);

float galutinis_balas(int, float);