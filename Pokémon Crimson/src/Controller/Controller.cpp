#include "controller.h"

void Controller::init() {
	model.init();

	// Test initialization, future serialization
	Character& chara = model.getCharacter();
	chara.posX = 45;
	chara.posY = 45;
	chara.sizeX = 32;
	chara.sizeY = 32;
	chara.direction = 0;
	chara.sprint = false;
	chara.noId = 24056;
	chara.name = "Raphael";
	chara.money = 256;
	chara.stars = 2;
	chara.score = 10864;
	chara.pokedex = 108;
	chara.getInventory().loadInventory();
}

// Fonction de mise à jour du jeu à la réception d'un évènement
void Controller::update(int event) {
	GameState& gameState = model.getGameState();

	// Détection de l'état du jeu global
	if (gameState.mapMode) 
		mapUpdate(event);

	prevEvent = event;
}

// Fonction de mise à jour losque le joueur est dans la map
void Controller::mapUpdate(int event) {
	GameState& gameState = model.getGameState();

	// Entrée dans le menu
	if (event == 5 and !gameState.menuMode and prevEvent != 5) { // Event "X"
		gameState.menuMode = true;
		gameState.menuId = 0;
		// Reset des mouvements lors de l'ouverture du menu
		model.getCharacter().sprint = false;
		model.getCharacter().moveCount = 0;
		view.mapView.renderWorld();
	}
	else if (gameState.menuMode and event == 5 and prevEvent != 5) // Anti spam "X"
		gameState.menuMode = false;

	// TO DO : Action dans la map via le bouton "A" (vérif de coord et action en conséquence)
	// TO DO : Détection d'évènement extérieurs comme un combat (vérif de line of sight)

	// Détection des états puis envoi de l'évènement aux sous-fonctions
	if (gameState.menuMode)
		mapMenuUpdate(event);
	else if (gameState.pkdxMode)
		mapPokedexUpdate(event);
	else if (gameState.teamMode)
		mapTeamUpdate(event);
	else if (gameState.invMode)
		mapBagUpdate(event);
	else if (gameState.cardMode)
		mapCardUpdate(event);
	else mapMovementUpdate(event); // Default mode
}

// TO DO : Implémenter le reste des fonctions du menu
void Controller::mapMenuUpdate(int action) {
	GameState& gameState = model.getGameState();

	if (action != prevEvent) {
		switch (action) {
			case 1:	// Event "Z" -> up + anti-spam
				gameState.menuId--;
				if (gameState.menuId < 0) gameState.menuId = 6;
				break;

			case 2: // Event "S" -> down + anti-spam
				gameState.menuId++;
				if (gameState.menuId > 6) gameState.menuId = 0;
				break;

			case 6: // Event "A" -> confirmer
				switch (gameState.menuId) {
					case 0:	// Entrée dans le pokédex
						gameState.pkdxMode = true;
						gameState.menuMode = false;
						gameState.pkdxId = 0;
						break;

					case 1:	// Entrée dans l'équipe
						gameState.teamMode = true;
						gameState.menuMode = false;
						gameState.teamId = 0;
						break;

					case 2:	// Entrée dans l'inventaire
						gameState.invMode = true;
						gameState.menuMode = false;
						gameState.invMenu = false;
						gameState.invCatId = 0;
						gameState.invItemId = 0;
						model.getCharacter().getInventory().setIterators(0);
						break;

					case 3: // Entrée dans la carte de dresseur
						gameState.cardMode = true;
						gameState.menuMode = false;
						break;

					case 6: // Sortie du menu
						gameState.menuMode = false;
						break;

						// save, options.
				}
				break;

			case 7: // Event "E" -> retour
				gameState.menuMode = false;
				break;
		}
	}
	view.mapView.renderMenu();
	sf::sleep(sf::milliseconds(20));
}

// TO DO : Améliorer système de navigation dans l'interface
void Controller::mapTeamUpdate(int action) {
	GameState& gameState = model.getGameState();

	if (action != prevEvent) {
		switch (action) {
		case 1:
			gameState.teamId--;
			if (gameState.teamId < 0)
				gameState.teamId = model.getCharacter().getPkmnTeam().size();
			break;

		case 2:
			gameState.teamId++;
			if (gameState.teamId == model.getCharacter().getPkmnTeam().size() + 1)
				gameState.teamId = 0;
			break;

		case 6: // Action à effectuer
			if (gameState.teamId == model.getCharacter().getPkmnTeam().size()) {
				gameState.menuMode = true;
				gameState.teamMode = false;
				view.mapView.renderWorld();
				return;
			}
			break;

		case 7:
			gameState.menuMode = true;
			gameState.teamMode = false;
			view.mapView.renderWorld();
			return;
		}
	}

	view.mapView.renderTeam();
	sf::sleep(sf::milliseconds(30));
}

void Controller::mapPokedexUpdate(int action) {
	GameState& gameState = model.getGameState();

	switch (action) {
		case 1:
			gameState.pkdxId--;
			if (gameState.pkdxId < 0)
				gameState.pkdxId = 0;
			break;

		case 2:
			gameState.pkdxId++;
			if (gameState.pkdxId > 492)
				gameState.pkdxId = 492;
			break;

		case 3:
			gameState.pkdxId -= 10;
			if (gameState.pkdxId < 0)
				gameState.pkdxId = 0;
			break;

		case 4:
			if (gameState.pkdxId == 0)
				gameState.pkdxId = 9;
			else gameState.pkdxId += 10;
			if (gameState.pkdxId > 492)
				gameState.pkdxId = 492;
			break;

		case 7:
			gameState.menuMode = true;
			gameState.pkdxMode = false;
			view.mapView.renderWorld();
			return;
	}

	view.mapView.renderPokedex();
	sf::sleep(sf::milliseconds(100));
}

void Controller::mapCardUpdate(int action) {
	if (action == 7) {
		model.getGameState().cardMode = false;
		model.getGameState().menuMode = true;
		view.mapView.renderWorld();
	}
	else {
		view.mapView.renderCard();
		sf::sleep(sf::milliseconds(50));
	}
}

// TO DO : Validation dans le sous menu
void Controller::mapBagUpdate(int action) {
	GameState& gameState = model.getGameState();
	Inventory& inventory = model.getCharacter().getInventory();

	if (action != prevEvent) {
		switch (action) {
		case 1:
			if (!gameState.invMenu) {
				gameState.invItemId--;
				if (gameState.invItemId < 0)
					gameState.invItemId = 0;
			}
			else {
				gameState.invMenuId--;
				if (gameState.invMenuId < 0)
					gameState.invMenuId = 2 + (gameState.invCatId == 1 or gameState.invCatId == 4);
			}
			break;
		case 2:
			if (!gameState.invMenu) {
				gameState.invItemId++;
				if (gameState.invItemId > gameState.invMaxItemId)
					gameState.invItemId = gameState.invMaxItemId;
			}
			else {
				gameState.invMenuId++;
				if (gameState.invMenuId > 2 + (gameState.invCatId == 1 or gameState.invCatId == 4))
					gameState.invMenuId = 0;
			}
			break;
		case 3:
			gameState.invCatId--;
			if (gameState.invCatId < 0)
				gameState.invCatId = 7;
			gameState.invItemId = 0;
			inventory.setIterators(gameState.invCatId);
			break;
		case 4:
			gameState.invCatId++;
			if (gameState.invCatId > 7)
				gameState.invCatId = 0;
			gameState.invItemId = 0;
			inventory.setIterators(gameState.invCatId);
			break;
		case 6:	// Event "A" -> validation
			if (!gameState.invMenu) {
				gameState.invMenu = true;
				gameState.invMenuId = 0;
			}
			//  Validation dans le sous menu
			break;
		case 7: // Event "E" -> retour
			if (!gameState.invMenu) {
				gameState.invMode = false;
				gameState.menuMode = true;
				view.mapView.renderWorld();
				return;
			}
			else gameState.invMenu = false;
		}
		gameState.invMaxItemId = inventory.itEnd - inventory.itBegin;
	}

	view.mapView.renderBag();
	sf::sleep(sf::milliseconds(50));
}

// Fonction de déplacement dans la map (DONE)
void Controller::mapMovementUpdate(int movement) {
	Character& character = model.getCharacter(); // Syntax simp.

	switch (movement) {
	case 0:
		if (clock.getElapsedTime().asMilliseconds() > 100) {
			character.moveCount = 0;
			character.sprint = false;
			}
		break;

	case 1:
		if (model.getCharacter().direction == 1)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 1;
			sf::sleep(sf::milliseconds(40));
		}
		if (character.moveCount > 0) {
			character.posY--;
			character.sprint = false;
			for (float i = 0; i < 20; i++) {
				view.mapView.renderWorld(-1, (character.posY * 16 + 16 - (i - 19.0f) * 0.8f), (i > 9));
				sf::sleep(sf::milliseconds(15));
			}
		}
		clock.restart();
		break;

	case 2:
		if (character.direction == 0)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 0;
			sf::sleep(sf::milliseconds(40));
		}
		if (character.moveCount > 0) {
			character.posY++;
			character.sprint = false;
			for (float i = 0; i < 20; i++) {
				view.mapView.renderWorld(-1, (character.posY * 16 + 16 + (i - 19.0f) * 0.8f), (i > 9));
				sf::sleep(sf::milliseconds(15));
			}
		}
		clock.restart();
		break;

	case 3:
		if (character.direction == 2)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 2;
			sf::sleep(sf::milliseconds(40));
		}
		if (character.moveCount > 0) {
			character.posX--;
			character.sprint = false;
			for (float i = 0; i < 20; i++) {
				view.mapView.renderWorld((character.posX * 16 + 16 - (i - 19.0f) * 0.8f), -1, (i > 9));
				sf::sleep(sf::milliseconds(15));
			}
		}
		clock.restart();
		break;

	case 4:
		if (character.direction == 3)
			character.moveCount++;
		else {
			character.moveCount = 0;
			character.direction = 3;
			sf::sleep(sf::milliseconds(40));
		}
		if (character.moveCount > 0) {
			character.posX++;
			character.sprint = false;
			for (float i = 0; i < 20; i++) {
				view.mapView.renderWorld((character.posX * 16 + 16 + (i - 19.0f) * 0.8f), -1, (i > 9));
				sf::sleep(sf::milliseconds(15));
			}
		}
		clock.restart();
		break;

	// Sprint

	case 11:
		if (character.direction != 1)
			character.direction = 1;
		
		character.posY--;
		character.sprint = true;
		for (float i = 0; i < 10; i++) {
			view.mapView.renderWorld(-1, (character.posY * 16 + 16 - (i - 9.0f) * 1.6f), (i < 4));
			if (i == 4) character.moveCount++;
			sf::sleep(sf::milliseconds(12));
		}
		clock.restart();
		break;

	case 12:
		if (character.direction != 0)
			character.direction = 0;

		character.posY++;
		character.sprint = true;
		for (float i = 0; i < 10; i++) {
			view.mapView.renderWorld(-1, (character.posY * 16 + 16 + (i - 9.0f) * 1.6f), (i < 4));
			if (i == 4) character.moveCount++;
			sf::sleep(sf::milliseconds(12));
		}
		clock.restart();
		break;

	case 13:
		if (character.direction != 2)
			character.direction = 2;
		
		character.posX--;
		character.sprint = true;
		for (float i = 0; i < 10; i++) {
			view.mapView.renderWorld((character.posX * 16 + 16 - (i - 9.0f) * 1.6f), -1, (i < 4));
			if (i == 4) character.moveCount++;
			sf::sleep(sf::milliseconds(12));
		}
		clock.restart();
		break;

	case 14:
		if (character.direction != 3)
			character.direction = 3;

		character.posX++;
		character.sprint = true;
		for (float i = 0; i < 10; i++) {
			view.mapView.renderWorld((character.posX * 16 + 16 + (i - 9.0f) * 1.6f), -1, (i < 4));
			if (i == 4) character.moveCount++;
			sf::sleep(sf::milliseconds(12));
		}
		clock.restart();
		break;
	}
	if (movement != 0 and character.sprint) sf::sleep(sf::milliseconds(30));
	view.mapView.renderWorld();
}

Controller::Controller(MainView& v, Model& m) : view(v), model(m), prevEvent(0) {}
Controller::~Controller() {}