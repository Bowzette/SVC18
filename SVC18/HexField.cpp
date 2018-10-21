#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <Windows.h>

using namespace std;

enum fieldType { HILL, FOREST, MOUNTAIN, FIELD, PASTURE, DESERT }; //may change position

/*
	Class HexTile

	fieldtype	ressource
	HILL		BRICK
	FOREST		LUMBER
	MOUNTAIN	ORE
	FIELD		GRAIN
	PASTURE		WOOL
	DESERT		--------

	SoC Rulebook: catan(dot)com/down/?/files/downloads/catan_5th_ed_rules_eng_150303.pdf
	example codes:
	gamedevelopment.tutsplus(dot)com/tutorials/introduction-to-axial-coordinates-for-hexagonal-tile-based-games--cms-28820
	cplusplus(dot)com/forum/general/833/
*/

class HexTile {
	private:
		int x, y, z;
		fieldType type;
		bool robberState;
		int numberToken;
	public:
		HexTile() {}
		HexTile(int x, int y, fieldType type) {
			this->x = x;
			this->y = (y-(floor(x/2))); //double to int may be a problem???
			z = -x - this->y;
			this->type = type;
		}

		string getInfo() { //DEBUG
			return to_string(x) + "," + to_string(y) + "," + to_string(z);
		}

		int getX() { return x; }
		int getY() { return y; }
		int getZ() { return z; }
		fieldType getType() { return type; }
		bool getRobberState() { return robberState; }
		int getNumberToken() { return numberToken; }

		void setType(fieldType type) { this->type = type; }
		void setRobberState(bool robberState) { this->robberState = robberState; }
		void setNumberToken(int numberToken) { this->numberToken = numberToken; }
};

class HexField {
	public:
		HexField() {};
		HexField(int TESTSIZE) { //Creates a square field with a TESTSIZE size
			vector< vector<HexTile> > field(TESTSIZE, vector<HexTile>(TESTSIZE));
			for (int i = 0; i < TESTSIZE; i++) {
				for (int j = 0; j < TESTSIZE; j++) {
					field[i][j] = HexTile(i, j, HILL);
				}
			}
		}
};

int main() {
	HexField::HexField(5);
	return 0;
};