#include "biblioteka.h"
#include "komparatoriai.h"

void rusiavimas(string p, vector<studentas> grupe) {
	if (p == "V") {
		sort(grupe.begin(), grupe.end(), compareV);
	}
	else if (p == "P") {
		sort(grupe.begin(), grupe.end(), compareP);
	}
}