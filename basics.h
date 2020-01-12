#include <map>
#include <set>
#include <string>
#include <vector>


using namespace std:

struct Feature {
	string name;
	string text;
	int uses;		// If passive, uses = 0
	bool longRest;		// Doesn't matter if uses = 0

}

enum abilityScore {STR, DEX, CON, INT, WIS, CHA};

typedef string Proficiency;
typedef map< set<Feature>, int > featChoice;
typedef set< map< int, set<abilityScore> > > scoreChoice;		


/* Examples for scoreChoice
	ORC: +2 Str, +1 Con, -2 Int
	{A}
	A(2)  -> {STR}
	A(1)  -> {CON}
	A(-2) -> {INT}
	-----------------
	HALF ELF: "+2 Cha, +1 to two other"
	{A}
	A(2) -> {CHA}
	A(1) -> {STR,DEX,CON,INT,WIS,CHA}
	A(1) -> {STR,DEX,CON,INT,WIS,CHA}
	-----------------
	CHANGELING: "+2 Cha, +1 to any"
	{A,B}
	A(2) -> {CHA}
	B(1) -> {STR,DEX,CON,INT,WIS,CHA}
*/




struct race {

	featureChoice 	raceFeats;
	scoreChoice	raceAbScores
}


