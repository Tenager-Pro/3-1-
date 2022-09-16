#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define MAX 50
#define UP 1
#define RIGHT 2
#define DOWN -1
#define LEFT -2

class Game {
public:
	int level;
	Game(int newLevel) {
		level = newLevel;
	}


};
void initGrid(int, int);
void draw_grid();
void draw_food();
void draw_snake();

void levelOne(int, int);
void levelTwo(int, int);
void levelThree(int, int);
int random(int, int);
#endif // GAME_H_INCLUDED

