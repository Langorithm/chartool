#include <map>
#include <set>
#include <string>
#include <vector>


using namespace std;


struct Feature {
	string name;
	string text;
	int uses;		// If passive, uses = 0
	bool longRest;		// Doesn't matter if uses = 0

};

enum Ability {STR, DEX, CON, INT, WIS, CHA};
int abilityMod(int score){
	score -= 10;
	score /= 2;
	if (score < 0) score--;
	return score;
};


typedef string 			proficiency;
typedef map<Ability, int>	abilityScores;

typedef map< set<Feature>, int > 	featureChoice;
typedef map< set<proficiency>, int > 	profChoice;
typedef set< map< int, set<Ability> > > abilityChoice;		

/* Examples for abilityChoice
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

struct Race {

	featureChoice 	raceFeats;
	abilityChoice	raceAbScores;
	set<Race>	subraces;
};

struct Job {
	
	int 			hitDie;
	profChoice 	  	skillChoices;
	set <proficiency> 	proficiencies;
	vector<featureChoice>	levels;
	set<Job>		subclasses;
};
