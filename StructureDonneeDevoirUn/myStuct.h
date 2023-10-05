#pragma once
#include <string>

using namespace std;
static class myStuct
{
    public:
        struct Etudiants {
            string nom;
            Etudiants* suivant;
        };

        struct Cours {
            string sigle;
            Cours* suivant;
        };

        struct Professeur {
            string nom;
            int ancien;
            Cours* listeCours;
            Etudiants* listeEtudiants;
            Professeur* suivant;

            bool nameEquals(std::string name, bool caseInsensitive);
        };
};

