#include "DossierProfesseur.h"
#include "myStuct.h"
#include <vector>
#include <iostream>
#include "FileHelper.h"
#include "CustomHelpers.h"

DossierProfesseur::DossierProfesseur(std::vector<std::string>* file)
{
	myStuct::Professeur* pntProf = new myStuct::Professeur();

	for (int cpt = 0; cpt < file->size(); cpt++)
	{
		myStuct::Professeur* tempProf = new myStuct::Professeur();

		tempProf->nom = (*file)[cpt++];
		tempProf->ancien = stoi((*file)[cpt++]);

		tempProf->listeCours = new myStuct::Cours();
		tempProf->listeCours->sigle = (*file)[cpt++];

		myStuct::Cours* pntCour = tempProf->listeCours;

		while ((*file)[cpt] != "&")
		{
			myStuct::Cours* tempCour;
			tempCour = new myStuct::Cours();
			tempCour->sigle = (*file)[cpt++];

			pntCour->suivant = tempCour;

			pntCour = tempCour;
		}
		cpt++;
		tempProf->listeEtudiants = new myStuct::Etudiants();
		tempProf->listeEtudiants->nom = (*file)[cpt++];

		myStuct::Etudiants* pntEtudiant = tempProf->listeEtudiants;

		while ((*file)[cpt] != "&")
		{
			myStuct::Etudiants* tempEtudiant;
			tempEtudiant = new myStuct::Etudiants();
			tempEtudiant->nom = (*file)[cpt++];

			pntEtudiant->suivant = tempEtudiant;

			pntEtudiant = tempEtudiant;
		}

		if (laTete == nullptr)
		{
			laTete = tempProf;
			pntProf = tempProf;
		}
		else
		{
			pntProf->suivant = tempProf;
			pntProf = tempProf;
		}
	}
}

DossierProfesseur::~DossierProfesseur()
{
	myStuct::Professeur* nextProf = NULL;
	while (laTete != NULL)
	{
		nextProf = laTete->suivant;
		laTete = NULL;
		delete laTete;
		laTete = nextProf;
	}
}

bool DossierProfesseur::supprimer(string name)
{
	try
	{
		myStuct::Professeur* nowProf = laTete;
		myStuct::Professeur* previousProf = NULL;
		while (nowProf != NULL)
		{
			if (nowProf->nameEquals(name))
			{
				//This if is usefull only it the teacher is at the index 0
				if (previousProf == NULL)
				{
					laTete = nowProf->suivant;
					return true;
				}

				//This is usefull only if the teacher is at the last index
				if (nowProf->suivant == NULL)
				{
					previousProf->suivant = NULL;
					return true;
				}

				previousProf->suivant = nowProf->suivant;
				return true;
			}
			previousProf = nowProf;
			nowProf = nowProf->suivant;
		}
		return false;
	}
	catch (const std::exception& ex)
	{
		cout << "Error occurred: " << ex.what() << endl;
		return false;
	}
}


bool DossierProfesseur::afficherProfMoinsEtudiant() const
{
	myStuct::Professeur* tempProf = laTete;
	myStuct::Professeur* moinProf = new myStuct::Professeur();
	int moinsEtudiant = -1;
	while (tempProf != NULL)
	{
		myStuct::Etudiants* tempEtudiant = tempProf->listeEtudiants;
		int nbEtudiant = 0;
		while (tempEtudiant != NULL)
		{
			tempEtudiant = tempEtudiant->suivant;
			nbEtudiant++;
		}

		if (moinsEtudiant == -1 || moinsEtudiant > nbEtudiant)
		{
			moinsEtudiant = nbEtudiant;
			moinProf = tempProf;
		}

		tempProf = tempProf->suivant;
	}

	displayOne(moinProf);

	return true;
}

bool DossierProfesseur::afficherCoursMoinsDemande() const
{
	try
	{
		int nbMoinFois = -1;
		myStuct::Cours* moinsCours = new myStuct::Cours();

		myStuct::Professeur* tempProf = laTete;
		while (tempProf != NULL)
		{
			myStuct::Cours* tempCours = tempProf->listeCours;
			while (tempCours != NULL)
			{
				int cptcours = 0;
				myStuct::Professeur* tempProf2 = laTete;
				while (tempProf2 != NULL)
				{
					myStuct::Cours* tempCours2 = tempProf2->listeCours;
					while (tempCours2 != NULL)
					{
						if (tempCours->sigle == tempCours2->sigle)
							cptcours++;

						tempCours2 = tempCours2->suivant;
					}
					tempProf2 = tempProf2->suivant;
				}
				if (nbMoinFois == -1 || nbMoinFois > cptcours)
				{
					nbMoinFois = cptcours;
					moinsCours = tempCours;
				}
				tempCours = tempCours->suivant;
			}
			tempProf = tempProf->suivant;
		}

		cout << "Le cours le moins demande est " << moinsCours->sigle << endl;
		return true;
	}
	catch (const std::exception& ex)
	{
		cout << "Error occurred: " << ex.what() << endl;
		return false;
	}

}

bool DossierProfesseur::afficherNbProfPourCours(std::string coursdonne)
{
	try
	{
		int cptProf = 0;
		myStuct::Cours* moinsCours = new myStuct::Cours();
		myStuct::Professeur* tempProf = laTete;
		while (tempProf != NULL)
		{
			myStuct::Cours* tempCours = tempProf->listeCours;
			while (tempCours != NULL)
			{
				if (tempCours->sigle == coursdonne)
					cptProf++;

				tempCours = tempCours->suivant;
			}
			tempProf = tempProf->suivant;
		}
		cout << "Il y a " << cptProf << " professeur(s) pour le cours " << coursdonne << endl;
		return true;
	}
	catch (const std::exception& ex)
	{
		cout << "Error occurred: " << ex.what() << endl;
		return false;
	}

}

bool DossierProfesseur::updateSaveFile()
{
	std::vector<std::string> tempList;
	myStuct::Professeur* tempProf = laTete;
	while (tempProf != NULL)
	{
		tempList.push_back(tempProf->nom);
		tempList.push_back(to_string(tempProf->ancien));

		myStuct::Cours* tempCour = tempProf->listeCours;
		while (tempCour != NULL)
		{
			tempList.push_back(tempCour->sigle);
			tempCour = tempCour->suivant;
		}

		tempList.push_back("&");

		myStuct::Etudiants* tempEtudiant = tempProf->listeEtudiants;
		while (tempEtudiant != NULL)
		{
			tempList.push_back(tempEtudiant->nom);
			tempEtudiant = tempEtudiant->suivant;
		}
		tempList.push_back("&");

		tempProf = tempProf->suivant;
	}
	FileHelper fileManager;
	fileManager. Writefile("FP.txt", false, tempList);

	return true;
}

bool DossierProfesseur::displayAll()
{
	try
	{
		myStuct::Professeur* tempProf = laTete;
		while (tempProf != NULL)
		{
			displayOne(tempProf);

			cout << "==========" << endl;

			tempProf = tempProf->suivant;
		}
		return true;
	}
	catch (const std::exception& ex)
	{
		cout << "Error occurred: " << ex.what() << endl;
		return false;
	}

}

bool DossierProfesseur::displayOne(myStuct::Professeur* prof)
{
	try
	{
		cout << prof->nom << endl;
		cout << "----------" << endl;
		cout << prof->ancien << endl;
		cout << "----------" << endl;

		myStuct::Cours* tempCour = prof->listeCours;
		while (tempCour != NULL)
		{
			cout << tempCour->sigle << endl;
			tempCour = tempCour->suivant;
		}

		cout << "----------" << endl;

		myStuct::Etudiants* tempEtudiant = prof->listeEtudiants;
		while (tempEtudiant != NULL)
		{
			cout << tempEtudiant->nom << endl;
			tempEtudiant = tempEtudiant->suivant;
		}
		return true;
	}
	catch (const std::exception& ex)
	{
		cout << "Error occurred: " << ex.what() << endl;
		return false;
	}

}

	