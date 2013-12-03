#include "species.h"

#include <iostream>

//Load the species from the file.
//Parameters: Pointer to species, pointer to file.
bool loadSpecies(Species *species, std::ifstream *file) {
	std::string line;
	std::string word = "";
	std::string value = "";
	if(file->is_open() && std::getline(*file, line)) {
		int i = 0;
		//If it's blank or something:
		while(line[i] == '\n' || line[i] == '\0' || line[i] == '#') {
			if(!std::getline(*file, line)) {
				return false;
			}
			std::cout << "Bloop\n";
		}
		std::cout << line << "\n\n";
		//If this isn't a species:
		if(line[i] != '[') {
			//TODO: add throw here
			return false;
		}
		while(line[i] != ']') { //loop until the end of the species.
			i++; //Get us into position. i=1.
			//Get a word.
			while(line[i] != '=' && line[i] != ' ') {
				word.push_back(line[i]);
				i++; //Go to the next character.
			}
			std::cout << i << '\n';
			while(line[i] == '=' || line[i] == ' ') {
				i++; //Get to the first character of the value.
			}
			std::cout << i << '\n';
			if(line[i] != '"') { //We should see a "
				//TODO: add throw here
				return false;
			}
			std::cout << i << '\n';
			i++; //Get into position to read the value.
			while(line[i] != '"') {
				value.push_back(line[i]);
				i++; //Go to the next character.
			}
			std::cout << i << '\n';
			i++; 

			std::cout << i << '\n';
			//Figure out what it is! 
			//Our strategy should be *not* to fail on invalid input.
			if(word.compare("name") == 0) {
				species->name = value;
			}
			if(word.compare("symbol") == 0) {
				species->symbol = value[0];
			}
			if(word.compare("speed") == 0) {
				species->stats.speed = atoi(value.c_str());
			}
			if(word.compare("hitpoints") == 0) {
				species->stats.hitpoints = atoi(value.c_str());
			}
			if(word.compare("strength") == 0) {
				species->stats.strength = atof(value.c_str());
			}
			if(word.compare("armorclass") == 0) {
				species->stats.armorclass = atof(value.c_str());
			}

			//Clear the word and value
			word.clear();
			value.clear();
		}
	}
	else {
		return false;
	}
	return true;
}
