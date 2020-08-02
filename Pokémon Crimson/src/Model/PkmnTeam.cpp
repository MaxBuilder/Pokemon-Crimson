#include "PkmnTeam.h"

void PkmnTeam::loadTeam() {
	std::ifstream inputFile("assets/save/TeamSave.json");
	json jsonSource;
	jsonSource = json::parse(inputFile);

	for (int i = 0; i < jsonSource.size(); i++) {
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

		pkmns.push_back(pkmn);
	}

	inputFile.close();
}

void PkmnTeam::saveTeam() {
	json jsonOutput;
	std::ofstream outputFile("assets/save/TeamSaveOut.json");

	for (int i = 0; i < pkmns.size(); i++) {
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
	}

	outputFile << jsonOutput;
	outputFile.close();
}

Pkmn& PkmnTeam::getPkmn(int emp) {
	assert(emp >= 0 and emp < pkmns.size());
	return pkmns.at(emp);
}

PkmnTeam::PkmnTeam() {/*
	Pkmn pkmn = { "Arceus", 493, {120, 120, 120, 120, 120, 120}, {1, 2, 3, 4}, 0 };
	pkmns.push_back(pkmn);
	pkmn = { "Dialga", 483, {120, 120, 120, 120, 120, 120}, {1, 2, 3, 4}, 0 };
	pkmns.push_back(pkmn);
	pkmn = { "Palkia", 484, {120, 120, 120, 120, 120, 120}, {1, 2, 3, 4}, 0 };
	pkmns.push_back(pkmn);
	pkmn = { "Torterra", 389, {120, 120, 120, 120, 120, 120}, {1, 2, 3, 4}, 0 };
	pkmns.push_back(pkmn);
	pkmn = { "Simiabraz", 492, {120, 120, 120, 120, 120, 120}, {1, 2, 3, 4}, 0 };
	pkmns.push_back(pkmn);
	pkmn = { u8"Pingoléon", 495, {120, 120, 120, 120, 120, 120}, {1, 2, 3, 4}, 0 };
	pkmns.push_back(pkmn);*/
	loadTeam();
	
}
PkmnTeam::~PkmnTeam() { saveTeam(); }
