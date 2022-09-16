#pragma once
class Snake {
public:
	int posx[MAX + 1] = {};
	int posy[MAX + 1] = {};
	
	int length; //Длина змеи
	Snake(int newLength) {
		length = newLength;
		posx[0] = 1;
		posy[0] = 1;
	}
};
