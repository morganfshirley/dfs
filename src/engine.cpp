#include "engine.h"

int Engine::getInput() {
	return getch();
}

void Engine::dealWithKeys(int ch) {

	//exit the game if we press q (TODO remove this in favor of a menu)
	if(ch == 'q' || ch == 'Q') {
		running = false;
	}
	else {
		player_brain->setInput(ch);
	}
		
}

Engine::Engine() {
	running = true;

	//Load species
	std::ifstream species_file;
	species_file.open("species.dat");

	Species new_species;
	while(loadSpecies(&new_species, &species_file)) {
		species_list.push_back(new_species);
	}
	
	species_file.close();

	//Testing, TODO remove
	object_list.push_back(new Object(new SpeciesComponent(&(species_list.at(4))), 3, 4));
	object_list.push_back(new Object(new SpeciesComponent(&(species_list.at(3))), 6, 1));
	object_list.push_back(new Object(new SpeciesComponent(&(species_list.at(2))), 23, 4));
	
	//Donkey
	object_list.push_back(new Object(4, 7));
	object_list.back()->addComponent(new SpeciesComponent(&(species_list.at(0)))); 
	BaseLogicComponent *donkey_brain = new BaseLogicComponent();
	donkey_brain->setMotivationWeight(5, 100);
	object_list.back()->addComponent(donkey_brain);

	//Player
	player = new Object(10, 10);
	player->addComponent(new SpeciesComponent(&(species_list.at(1)))); 
	object_list.push_back(player);	
	player_brain = new PlayerLogicComponent();
	player->addComponent(player_brain);	

	srand(time(NULL));
}

Engine::~Engine() {
	while(object_list.size() > 0) {
		Object *deleted_ptr = object_list.back();
		object_list.pop_back();
		delete deleted_ptr;
	}
}

bool Engine::isRunning() {
	return running;
}

void Engine::run() {
	if(player_brain->getInitiative() >= 0) {
		//Keyboard input
		int ch = getInput();
		dealWithKeys(ch);
	}

	//Run objects
	for(std::size_t i = 0; i < object_list.size(); i++) {
		object_list.at(i)->run();
	}
}

void Engine::render() {
	//Get screen dimensions
	int screen_min_x, screen_min_y, screen_max_x, screen_max_y;
	getbegyx(stdscr, screen_min_y, screen_min_x);
	getmaxyx(stdscr, screen_max_y, screen_max_x);

	//The status bar may exist at some point! Here are some placeholder values.
	int status_bar_size = 0;
	int status_bar_top_size = 0;

	//The view is going to be constantly centered on the player.
	//These variables should help with math.
	int view_offset_x = (screen_max_x - screen_min_x) / 2 - player->getX();
	int view_offset_y = (screen_max_y - screen_min_y) / 2 - player->getY();

	//Draw objects
	for(std::size_t i = 0; i < object_list.size(); i++) {
		//Only draw the object if it's on the screen.
		if(	object_list.at(i)->getY() + view_offset_y < screen_max_y - status_bar_size &&
			object_list.at(i)->getY() + view_offset_y > screen_min_y + status_bar_top_size &&
			object_list.at(i)->getX() + view_offset_x < screen_max_x &&
			object_list.at(i)->getX() + view_offset_x > screen_min_x) {

			mvaddch(
				object_list.at(i)->getY() + view_offset_y,
				object_list.at(i)->getX() + view_offset_x,
				object_list.at(i)->render()
			);
		}
	}

	//Draw cursor
	curs_set(0);
	drawPointer(0, 0);
}
