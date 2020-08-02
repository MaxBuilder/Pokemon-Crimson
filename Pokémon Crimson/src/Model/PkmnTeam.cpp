#include "PkmnTeam.h"

void PkmnTeam::loadTeam() {
	std::ifstream inputFile("assets/save/TeamSaveDef.json");
	json jsonSource;
	jsonSource = json::parse(inputFile);

	for (unsigned int i = 0; i < jsonSource.size(); i++) {
		Pkmn pkmn;
		pkmn.name = jsonSource[std::to_string(i)]["name"].get<std::string>();
		pkmn.id = jsonSource[std::to_string(i)]["id"].get<int>();
		pkmn.stats.at(0) = jsonSource[std::to_string(i)]["stats"]["hp"].get<int>();
		pkmn.stats.at(1) = jsonSource[std::to_string(i)]["stats"]["atk"].get<int>();
		pkmn.stats.at(2) = jsonSource[std::to_string(i)]["stats"]["def"].get<int>();
		pkmn.stats.at(3) = jsonSource[std::to_string(i)]["stats"]["atk_sp"].get<int>();
		pkmn.stats.at(4) = jsonSource[std::to_string(i)]["stats"]["def_sp"].get<int>();
		pkmn.stats.at(5) = jsonSource[std::to_string(i)]["stats"]["speed"].get<int>();
		pkmn.attacks.at(0) = jsonSource[std::to_string(i)]["attack"]["0"].get<int>();
		pkmn.attacks.at(0) = jsonSource[std::to_string(i)]["attack"]["1"].get<int>();
		pkmn.attacks.at(0) = jsonSource[std::to_string(i)]["attack"]["2"].get<int>();
		pkmn.attacks.at(0) = jsonSource[std::to_string(i)]["attack"]["3"].get<int>();
		pkmn.status = jsonSource[std::to_string(i)]["status"].get<int>();
		pkmn.gender = jsonSource[std::to_string(i)]["gender"].get<int>();
		pkmn.level = jsonSource[std::to_string(i)]["level"].get<int>();
		pkmn.maxHp = jsonSource[std::to_string(i)]["max_hp"].get<int>();

		pkmns.push_back(pkmn);
	}

	inputFile.close();
}

void PkmnTeam::saveTeam() {
	json jsonOutput;
	std::ofstream outputFile("assets/save/TeamSaveDef.json");

	for (unsigned int i = 0; i < pkmns.size(); i++) {
		jsonOutput[std::to_string(i)]["name"] = pkmns.at(i).name;
		jsonOutput[std::to_string(i)]["id"] = pkmns.at(i).id;
		jsonOutput[std::to_string(i)]["stats"]["hp"] = pkmns.at(i).stats.at(0);
		jsonOutput[std::to_string(i)]["stats"]["atk"] = pkmns.at(i).stats.at(1);
		jsonOutput[std::to_string(i)]["stats"]["def"] = pkmns.at(i).stats.at(2);
		jsonOutput[std::to_string(i)]["stats"]["atk_sp"] = pkmns.at(i).stats.at(3);
		jsonOutput[std::to_string(i)]["stats"]["def_sp"] = pkmns.at(i).stats.at(4);
		jsonOutput[std::to_string(i)]["stats"]["speed"] = pkmns.at(i).stats.at(5);
		jsonOutput[std::to_string(i)]["attack"]["0"] = pkmns.at(i).attacks.at(0);
		jsonOutput[std::to_string(i)]["attack"]["1"] = pkmns.at(i).attacks.at(1);
		jsonOutput[std::to_string(i)]["attack"]["2"] = pkmns.at(i).attacks.at(2);
		jsonOutput[std::to_string(i)]["attack"]["3"] = pkmns.at(i).attacks.at(3);
		jsonOutput[std::to_string(i)]["status"] = pkmns.at(i).status;
		jsonOutput[std::to_string(i)]["gender"] = pkmns.at(i).gender;
		jsonOutput[std::to_string(i)]["level"] = pkmns.at(i).level;
		jsonOutput[std::to_string(i)]["max_hp"] = pkmns.at(i).maxHp;
	}

	outputFile << jsonOutput;
	outputFile.close();
}

int PkmnTeam::size() {
	return pkmns.size();
}

Pkmn& PkmnTeam::getPkmn(int emp) {
	assert(emp >= 0 and emp < pkmns.size());
	return pkmns.at(emp);
}

PkmnTeam::PkmnTeam() {
	Pkmn pkmn = { "Arceus", 493, {381, 372, 372, 372, 372, 372}, 381, {1, 2, 3, 4}, 0, 0, 75 };
	pkmns.push_back(pkmn);
	pkmn = { "Dialga", 483, {381, 372, 372, 372, 372, 372}, 381, {1, 2, 3, 4}, 0, 0, 89 };
	pkmns.push_back(pkmn);
	pkmn = { "Palkia", 484, {381, 372, 372, 372, 372, 372}, 381, {1, 2, 3, 4}, 0, 0, 56 };
	pkmns.push_back(pkmn);
	pkmn = { "Torterra", 389, {381, 372, 372, 372, 372, 372}, 381, {1, 2, 3, 4}, 0, 2, 38 };
	pkmns.push_back(pkmn);
	pkmn = { "Simiabraz", 392, {381, 372, 372, 372, 372, 372}, 381, {1, 2, 3, 4}, 0, 1, 63 };
	pkmns.push_back(pkmn);
	pkmn = { u8"Pingoléon", 395, {381, 372, 372, 372, 372, 372}, 381, {1, 2, 3, 4}, 0, 1, 61 };
	pkmns.push_back(pkmn);
	//loadTeam();
	
}
PkmnTeam::~PkmnTeam() { saveTeam(); }
