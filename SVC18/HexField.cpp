#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib>
#include <ctime>
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
*/
class HexTile {
	public:
		int x, y, z;
		enum fieldType { HILL, FOREST, MOUNTAIN, FIELD, PASTURE, DESERT };
		bool isRobber;
		int numberToken = 1 + rand() % ((12 + 1) - 1); //platzhalter, da der Zahlenwert nicht wirklich zufällig ist. (die 7 gibts nicht)
		HexTile() {}
		HexTile(int x, int y, fieldType fieldType) {
			this->x = x;
			this->y = y;
			z = -x - y; //explanation gamedevelopment.tutsplus(dot)com/tutorials/introduction-to-axial-coordinates-for-hexagonal-tile-based-games--cms-28820
			//this->fieldType = fieldType;
		}
		string getInfo() {
			return to_string(x) + "," + to_string(y) + "," + to_string(z);
		}
};

class HexField {
	public:
		HexField() { //create standard game field

		}
};

int main() {
	srand(time(0));
	cout << "map generator test" << endl;
	vector< vector<HexTile> > field(5, vector<HexTile>(5)); //explanation cplusplus(dot)com/forum/general/833/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			field[i][j] = HexTile(i, j, HexTile::HILL);
			cout << field[i][j].getInfo() << "\t\t";
		}
		cout << endl;
	}

	Sleep(8000);
	return 0;
};