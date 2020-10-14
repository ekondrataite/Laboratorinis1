#include "komparatoriai.h"

//komparatoriai reikalingi rusiavimui;

bool compareV(studentas a, studentas b) {
	return a.vardas < b.vardas;
}
bool compareP(studentas a, studentas  b) {
	return a.pavarde < b.pavarde;
}