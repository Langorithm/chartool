#include "character.h"
string Character::getName(){
	return _name;
}

void Character::setName(string s){
	_name = s;
}

const Race& Character::getRace(){
	return _race;
}

build Character::getLevels(){
	return _jobs;
}


int Character::getCharacterLevel(){
	int res = 0;
	
	for (auto it = _jobs.begin(); it != _jobs.end(); it++){
		res += it->second;
	}
	return res;
}

int Character::getProfBonus(){
	int res = getCharacterLevel();
	res /= 4;
	res += 2;
	return res;
}

int Character::getMaxHP(){
	return _maxHP;
}

int Character::getInitiative(){
	return _initiative;
}

int Character::getSpeed(){
	return _speed;
}

int Character::getAC(){
	return _AC;
}

int Character::getPassivePerception(){
	return 10 + getRollMod("Perception");
}


void Character::setMaxHP(int n){
	_maxHP = n;
}

void Character::setInitiative(int n){
	_initiative = n;
}

void Character::setSpeed(int n){
	_speed = n;
}



//int Character::getAbilityMod(Ability a){
//	return abilityMod(
//		getScores()[a]
//	);
//}

int Character::getRollMod(proficiency P){
	//TO DO
	return 0;
}


set<proficiency> Character::getProficiencies(){
	return _proficiencies;
}

set<Feature> Character::getFeatures(){
	return _features;
}

	/* getSpellSlots Auxiliary/
bool isMulticaster(const build& b){
	bool res = false;

	int casterClasses = 0;

	for (auto it = b.begin(); !res && it != b.end(); it++){
		if (it->first.casterTier > 0) casterClasses++;
		res = casterClasses < 2;
	}		

	return res;
}

	/ getSpellSlots Auxiliary*
int casterLevel(const build& b){
	int res = 0;
	for (auto it = b.begin(); it != b.end() ; it++){
		int tier = it->first.casterTier;
		int level = it->second;

		res += level/tier;			//Full caster: Tier 1. Half caster: Tier 2. Third caster: Tier 3
	}
	return res;
}

	* getSpellSlots Auxiliary 
	 PRE: No tiene más de una clase caster 
	POST: res = tier de la clase caster /
int singleClassCasterTier(const build& b){
	int res = 0;
	
	for (auto it = b.begin(); res != 0 || it != b.end(); it++){
		if (it->first.casterTier != 0)
			res = it->first.casterTier;
	}
	return res;
}

vector<int> Character::getSpellSlots(){
	build casterBuild = getLevels();
	
	
	spellSlotsTable& spellTable = fullCaster; 		//Possibly replaced
	int casterLvl = casterLevel(casterBuild);


	if (!isMulticaster(casterBuild)){
		int tier = singleClassCasterTier(casterBuild);
		
		switch (tier) {
			case (1): spellTable = fullCaster; break;
			case (2): spellTable = halfCaster; break;
			case (3): spellTable = thirdCaster; break;
			default : return {};
		}
	}

	vector<int> res(begin(spellTable[casterLvl]), end(spellTable[casterLvl]));
	
}


void Character::levelUp(const Job& j){
	
	//Add level to character's build
	auto it = _jobs.find(j);
	if (it != _jobs.end() )
		it->second++;
	else
		_jobs[j] = 1;
	
	//Increase Max HP
	_maxHP += j.hitDie/2 + 1;


	//Activate Passive Features

}
*/

Character::Character(Job j, const Race& r) : _race(r) {
	
	_name = "joe the " + r.name;
	_jobs[j] = 1;
	_background = "barber";
	_scores[STR] = 10;
	_scores[DEX] = 10;
	_scores[CON] = 10;
	_scores[INT] = 10;
	_scores[WIS] = 10;
	_scores[CHA] = 10;
	_maxHP = j.hitDie;
	_initiative = 0;
	_speed = r.speed;
	_AC = 10;	
}
