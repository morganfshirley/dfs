#ifndef BASELOGICCOMPONENT_H
#define BASELOGICCOMPONENT_H

/**
 * Define motivations, which are elaborated in the .cpp file
 */

#define M_AMBITION	0
#define M_HUNGER	1
#define M_THIST		2
#define M_MALICE	3
#define M_FRIGHT	4
#define M_WANDERLUST	5
#define M_WORRY		6
#define M_PLAYER	7

//We can have M_PLAYER always have the highest value and calculate the total 
//motivations based off of that
#define M_NUMBER	M_PLAYER + 1

#include "component.h"

#include <vector>

class BaseLogicComponent : public Component {
private:
	//get the highest motivation. 
	//children should change this if they want to ignore certain motivations`
	virtual int getHighestMotivation();

	virtual void act();

	double initiative;
	double motivation_weights[M_NUMBER];

	std::vector<int> planned_path;
	void planPath(int, int);

	void move(int);
public:
	BaseLogicComponent();
	virtual void run();
	
	virtual void setMotivationWeight(int, double);
};

#endif //BASELOGICCOMPONENT_H
