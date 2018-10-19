#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <Windows.h>

using namespace std;

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
	public:
		int x, y, z;
		enum fieldType { HILL, FOREST, MOUNTAIN, FIELD, PASTURE, DESERT };
		fieldType fieldtype;
		bool isRobber;
		int numberToken;
		HexTile() {}
		HexTile(int x, int y, fieldType fieldType) {
			this->x = x;
			this->y = (y-(floor(x/2))); //double to int may be a problem???
			z = -x - this->y; //TODO: improve code
			this->fieldtype = fieldType;
		}
		string getInfo() {
			return to_string(x) + "," + to_string(y) + "," + to_string(z);
		}
};

class HexField {
	public:
		HexField() {} //create standard game field here not in main()
};

int main() {
	srand(time(0));
	cout << "map generator test" << endl << endl << endl;
	int TESTSIZE = 5;
	vector< vector<HexTile> > field(TESTSIZE, vector<HexTile>(TESTSIZE));
	for (int i = 0; i < TESTSIZE; i++) {
		for (int j = 0; j < TESTSIZE; j++) {
			field[i][j] = HexTile(i, j, HexTile::HILL);
			cout << field[i][j].getInfo() << "\t\t";
		}
		cout << endl << endl << endl;
		if (i % 2 == 0) {
			cout << "\t";
		}
	}

	Sleep(8000);
	return 0;
};