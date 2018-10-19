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
	int x, y;
	enum fieldType { HILL, FOREST, MOUNTAIN, FIELD, PASTURE, DESERT };
	bool isRobber;
	int z = -x - y; //explanation gamedevelopment.tutsplus(dot)com/tutorials/introduction-to-axial-coordinates-for-hexagonal-tile-based-games--cms-28820
	int numberToken = 1 + rand() % ((12 + 1) - 1); //platzhalter, da der Zahlenwert nicht wirklich zufällig ist. (die 7 gibts nicht)
	HexTile() {}
	HexTile(int x, int y, fieldType fieldType) {
		//hier kommt ma(g)gie rein
	}
	string getToken() {
		return to_string(numberToken);
	}
};

int main() {
	srand(time(0));
	cout << "map generator test" << endl;
	vector< vector<HexTile> > field(5, vector<HexTile>(5)); //explanation cplusplus(dot)com/forum/general/833/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			field[i][j] = HexTile(i, j, HexTile::HILL);
			cout << field[i][j].getToken() << "\t";
		}
		cout << endl;
	}

	Sleep(4000);
	return 0;
};