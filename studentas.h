#pragma once
#include "biblioteka.h"

class studentas {
private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    float galutinis;

public:

    bool compareV(const studentas& a, const studentas& b);
    bool compareP(const studentas& a, const studentas& b);

    studentas() {};
    studentas(string vard, string pav, vector<int> paz, int egz, float gal);

    //destructor
    ~studentas() {};

    // copy assignment operator
    studentas& operator=(const studentas& s)
    {
        vardas = s.vardas;
        pavarde = s.pavarde;
        pazymiai = s.pazymiai;
        egzaminas = s.egzaminas;
        galutinis = s.galutinis;
        return *this;
    };

    //copy constructor
    studentas(const studentas& s) : vardas(s.vardas), pavarde(s.pavarde), pazymiai(s.pazymiai), egzaminas(s.egzaminas), galutinis(s.galutinis)
    {
    }

    //getteriai

    const string& getVardas()
    {
        return vardas;
    }

    const string& getPavarde()
    {
        return pavarde;
    }

    const vector<int>& getPazymiai()
    {
        return pazymiai;
    }

    const int& getEgzaminas()
    {
        return egzaminas;
    }

    const double& getGalutinis()
    {
        return galutinis;
    }

    //setteriai

    void setVardas(const string& vard)
    {
        vardas = vard;
    }

    void setPavarde(const string& pav)
    {
        pavarde = pav;
    }

    void setPazymiai(const vector<int>& paz)
    {
        pazymiai = paz;
    }

    void setEgzaminas(const int& egz)
    {
        egzaminas = egz;
    }

    void setGalutinis(const float& gal)
    {
        galutinis = gal;
    }

};

bool compareV(studentas& a, studentas& b);
bool compareP(studentas& a, studentas& b);
list<studentas> failo_nuskaitymas_list();
bool salyga(studentas& eilute);
void irasymas(list<studentas> sarasas);