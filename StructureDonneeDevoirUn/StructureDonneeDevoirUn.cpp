// StructureDonneeDevoirUn.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <fstream>
#include "myStuct.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include "FileHelper.h"
#include "DossierProfesseur.h"


int main()
{
	FileHelper fileManager;

	std::vector<std::string> profInfo = fileManager.ReadFile("FP.txt");
	std::vector<std::string> commandes = fileManager.ReadFile("FT.txt");

	DossierProfesseur prof = DossierProfesseur(&profInfo);
	for (int i = 0; i < commandes.size(); i++)
	{
		switch (commandes[i][0])
		{
		case '-':
			prof.supprimer(commandes[i].erase(0, 2));
			break;
		case '#':
			prof.afficherProfMoinsEtudiant();
			break;
		case '*':
			prof.afficherCoursMoinsDemande();
			break;
		case '%':
			prof.afficherNbProfPourCours(commandes[i].erase(0, 2));
			break;
		case '$':
			prof.updateSaveFile();
			break;
		default:
			cout << "Commande non trouvé: " << commandes[i] << endl;
			break;
		}
	}
	prof.~DossierProfesseur();
}




// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
