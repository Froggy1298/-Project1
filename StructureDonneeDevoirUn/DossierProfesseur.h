#pragma once
#include "myStuct.h"
#include <vector>
#include <iostream>

class DossierProfesseur
{
private:
	myStuct::Professeur* laTete;
public:
	/// <summary>
	/// Dédicace à PA
	/// </summary>
	/// <param name="test"></param>
	DossierProfesseur(std::vector<std::string>* test);

	//This is the deconstor
	~DossierProfesseur();

	/// <summary>
	/// This will delete a professor
	/// </summary>
	/// <param name="name">name of the professor that will be delete</param>
	/// <returns>if the professor is sucessuly deleted</returns>
	bool supprimer(string name);

	/// <summary>
	/// This will display the teacher with the least student
	/// </summary>
	/// <returns>If the function correctly displayed the teacher</returns>
	bool afficherProfMoinsEtudiant() const;

	/// <summary>
	/// This will display the class with the least demand
	/// </summary>
	/// <returns>If the function correcly displayed the class</returns>
	bool afficherCoursMoinsDemande() const;

	/// <summary>
	/// This will display the number teacher for the given class
	/// </summary>
	/// <param name="coursdonne">The class for witch we want to reaseach the number of teacher</param>
	/// <returns>If the function correctly displayed the number</returns>
	bool afficherNbProfPourCours(std::string coursdonne);

	/// <summary>
	/// This will save the current linked liste to the save file
	/// </summary>
	/// <returns>If the function correcly saved the list to the save file</returns>
	bool updateSaveFile();

	/// <summary>
	/// Will display all the containt of the list
	/// </summary>
	/// <returns>If the function correctly displayed the list</returns>
	bool displayAll();

	/// <summary>
	/// Will display one teacher
	/// </summary>
	/// <returns>if the function worked correctly</returns>
	static bool displayOne(myStuct::Professeur* prof);
};