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

bool compareV(studentas a, studentas b);
bool compareP(studentas a, studentas  b);

vector<studentas> failo_nuskaitymas_vektorius();
list<studentas> failo_nuskaitymas_list();
void irasymas(list<vargsiukai> sarasas);
bool salyga(const studentas& eilute);