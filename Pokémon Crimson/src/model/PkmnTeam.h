#pragma once

#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <json.hpp>

using json = nlohmann::json;

// TO DO : Add enum to stats
struct Pkmn {
	std::string name = "";
	int id = 0;
	std::array<int, 6> stats = {};
	int maxHp = 0;
	std::array<int, 4> attacks = {};
	int status = 0;
	int gender = 0;
	int level = 0;

	// Later
	/*std::array<int, 6> debuf = {};
	int lvl = 0;
	int exp = 0;
	int ball = 0;
	+ IV and EV
	*/

	int getHp() {
		return stats.at(0);
	}

	int getMaxHp() {
		return maxHp;
	}

	bool isKo() {
		return stats.at(0) == 0;
	}
};

class PkmnTeam
{
private:
	std::vector<Pkmn> pkmns;

public:
	// Charge l'�quipe � partir d'un fichier de sauvegarde 
	void loadTeam();

	// Sauvegarde l'�quipe dans un fichier de sauvegarde
	void saveTeam();

	// Retourne un pok�mon de l'�quipe
	Pkmn& getPkmn(int emp);

	// Retourne la taille de l'�quipe 
	int size();

	// Ajoute un pok�mon � l'�quipe
	bool addPokemon(Pkmn& pkmn);

	// Constructeur de destructeur
	PkmnTeam();
	~PkmnTeam();

};

