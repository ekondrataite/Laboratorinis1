#include "biblioteka.h"
#include "studentas.h"

int main()
{
	list<studentas> sarasas = failo_nuskaitymas_list();

	list<studentas> vargsiukai;

	auto startas2 = chrono::high_resolution_clock::now();

	for (studentas& s : sarasas) {
		if (s.getGalutinis() < 5) {
			s.getVardas();
			s.getPavarde();
			s.getGalutinis();
			vargsiukai.push_back(s);
		}
	}
	sarasas.remove_if(salyga);

	auto baigta2 = chrono::high_resolution_clock::now();
	chrono::duration<double> skirtumas2 = baigta2 - startas2;
	cout << "Studentu suskirstymas i dvi grupes uztruko: " << skirtumas2.count() << "s" << endl;

	//irasymas(vargsiukai);
	//irasymas(sarasas);
}
