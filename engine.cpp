#include "engine.h"

int Engine::getInput() {
	return getch();
}

void Engine::dealWithKeys(int ch) {

	//exit the game if we press q (TODO remove this in favor of a menu)
	if(ch == 'q' || ch == 'Q') {
		running = false;
	}
	else if( //The following should be sent to the player
		ch == KEY_LEFT	||	ch == KEY_RIGHT	||
		ch == KEY_UP	||	ch == KEY_DOWN	||
		ch == KEY_A1	||	ch == KEY_A3	||
		ch == KEY_C1	||	ch == KEY_C3	||
		ch == KEY_B2 ) {
		player_brain->setInput(ch);
	}
}

Engine::Engine() {
	running = true;

	Species s_donkey;
	s_donkey.name = "donkey";
	s_donkey.symbol = 'D';
	Stats s_donkey_stats;
	s_donkey_stats.speed = 89; //25 mph in ms/m
	s_donkey_stats.hitpoints = 50;
	s_donkey_stats.strength = 50;
	s_donkey_stats.armorclass = 10;
	s_donkey.stats = s_donkey_stats;
	species_list.push_back(s_donkey);

	Species s_human;
	s_human.name = "human";
	s_human.symbol = '@';
	Stats s_human_stats;
	s_human_stats.speed = 149; //15 mph
	s_human_stats.hitpoints = 10;
	s_human_stats.strength = 5;
	s_human_stats.armorclass = 0;
	s_human.stats = s_human_stats;
	species_list.push_back(s_human);

	//Testing, TODO remove
	object_list.push_back(new Object(new RenderComponent('!'), 3, 4));
	object_list.push_back(new Object(new RenderComponent('g'), 6, 1));
	object_list.push_back(new Object(new RenderComponent('3'), 23, 4));
	
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
	for(int i = 0; i < object_list.size(); i++) {
		object_list.at(i)->run();
	}
}

void Engine::render() {
	//Get screen dimensions
	int screen_min_x, screen_min_y, screen_max_x, screen_max_y;
	getbegyx(stdscr, screen_min_y, screen_min_x);
	getmaxyx(stdscr, screen_max_y, screen_max_x);

	//The view is going to be constantly centered on the player.
	//These variables should help with math.
	int view_offset_x = (screen_max_x - screen_min_x) / 2 - player->getX();
	int view_offset_y = (screen_max_y - screen_min_y) / 2 - player->getY();

	//Draw objects
	for(int i = 0; i < object_list.size(); i++) {
		mvaddch(
			object_list.at(i)->getY() + view_offset_y,
			object_list.at(i)->getX() + view_offset_x,
			object_list.at(i)->render()
		);
	}

	//Draw cursor
	curs_set(0);
	drawPointer(0, 0);
}
