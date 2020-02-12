#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>


using namespace std;


struct Feature {
	string name;
	string text;
	int uses;		// If passive, uses = 0
	bool longRest;		// Doesn't matter if uses = 0

};

enum Ability {STR, DEX, CON, INT, WIS, CHA};
//int abilityMod(int score){
//	score -= 10;
//	score /= 2;
//	if (score < 0) score--;
//	return score;
//};


typedef string 			proficiency;
typedef map<Ability, int>	abilityScores;
typedef int			spellSlotsTable[][20];

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

const spellSlotsTable fullCaster = {
	{2},	
	{3},	
	{4,2},	
	{4,3},	
	{4,3,2},	
	{4,3,3},	
	{4,3,3,1},	
	{4,3,3,2},	
	{4,3,3,3,1},	
	{4,3,3,3,2},	
	{4,3,3,3,2,1},	
	{4,3,3,3,2,1},	
	{4,3,3,3,2,1,1},	
	{4,3,3,3,2,1,1},	
	{4,3,3,3,2,1,1,1},	
	{4,3,3,3,2,1,1,1},	
	{4,3,3,3,2,1,1,1,1},	
	{4,3,3,3,3,1,1,1,1},	
	{4,3,3,3,3,2,1,1,1},	
	{4,3,3,3,3,2,2,1,1}	
};

const spellSlotsTable halfCaster  = {
	{},
	{2},	
	{3},	
	{3},	
	{4,2},	
	{4,2},	
	{4,3},	
	{4,3},	
	{4,3,2},	
	{4,3,2},	
	{4,3,3},	
	{4,3,3},	
	{4,3,3,1},	
	{4,3,3,1},	
	{4,3,3,2},	
	{4,3,3,2},	
	{4,3,3,3,1},	
	{4,3,3,3,1},	
	{4,3,3,3,2},	
	{4,3,3,3,2}	
};
const spellSlotsTable thirdCaster  = {
	{},
	{},
	{2},
	{3},
	{3},
	{3},
	{4,2},
	{4,2},
	{4,2},
	{4,3},
	{4,3},
	{4,3},
	{4,3,2},
	{4,3,2},
	{4,3,2},
	{4,3,3},
	{4,3,3},
	{4,3,3},
	{4,3,3,1},
	{4,3,3,1}
};

struct Race {
	string		name;
	featureChoice 	raceFeats;
	abilityChoice	raceAbScores;
	set<Race>	subraces;
	int 		speed;
};

struct Job {
	string 			name;
	int 			hitDie;
	profChoice 	  	skillChoices;
	set <proficiency> 	proficiencies;
	vector<featureChoice>	levels;
	set<Job>		subclasses;
	int			casterTier;

	bool operator<(const Job other) const {
		return name < other.name;
	}
};

typedef map< Job, int>  build;
//typedef map< reference_wrapper<Job>, int>  build;

