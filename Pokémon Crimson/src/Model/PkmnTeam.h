#pragma once

#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <json.hpp>

using json = nlohmann::json;

struct Pkmn {
	std::string name = "";
	int id;
	std::array<int, 6> stats = {};
	std::array<int, 4> attacks = {};
	int status = 0;

	// Later
	/*std::array<int, 6> debuf = {};
	int lvl = 0;
	int exp = 0;
	int ball = 0;
	+ IV and EV
	*/
};

class PkmnTeam
{
private:
	std::vector<Pkmn> pkmns;

public:
	// Charge l'équipe à partir d'un fichier de sauvegarde 
	void loadTeam();

	// Sauvegarde l'équipe dans un fichier de sauvegarde
	void saveTeam();

	// Retourne un pokémon de l'équipe
	Pkmn& getPkmn(int emp);

	// Ajoute un pokémon à l'équipe
	bool addPokemon(Pkmn& pkmn);

	// Constructeur de destructeur
	PkmnTeam();
	~PkmnTeam();

};

