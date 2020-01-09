#include <map>
#include <set>
#include <string>

using namespace std:

struct Feature {
	
	string text;
	int uses;		// If passive, uses = 0
	bool longRest;		// Doesn't matter if uses = 0

}

typedef map< set<Feature>, int > featChoice;
