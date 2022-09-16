#pragma once
#include <vector>
class Wall {
public:
	std::vector <int> wallX = {};
	std::vector <int> wallY = {};
	Wall() {
		for (int x = 0; x <= columns; x++) {
			for (int y = 0; y <= rows; y++) {
				if (x = 0) {
					wallX.push_back(x);
					wallY.push_back(y);
				}
				if (x = columns) {
					wallX.push_back(x);
					wallY.push_back(y);
				}
				if (y = 0) {
					wallX.push_back(x);
					wallY.push_back(y);
				}
				if (y = rows) {
					wallX.push_back(x);
					wallY.push_back(y);
				}
				
			}
		}
	}
};
