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

#include "strukturos.h"

void studentu_suskirstymas(list<studentas> sarasas);

bool compareV(studentas a, studentas b);
bool compareP(studentas a, studentas  b);

list<studentas> failo_nuskaitymas();
void irasymas(vector<studentas> sarasas);