#pragma once
#include "biblioteka.h"

class zmogus
{
public:
    zmogus() {};

    zmogus(string vard, string pav);

    zmogus& operator=(const zmogus& z) {
        vardas = z.vardas;
        pavarde = z.pavarde;
        return *this;
    };

    virtual ~zmogus() = 0;

    virtual const string& getVardas() = 0;
    virtual const string& getPavarde() = 0;

    void setVardas(const string& vard)
    {
        vardas = vard;
    }

    void setPavarde(const string& pav)
    {
        pavarde = pav;
    }

protected:
    string vardas;
    string pavarde;
};

