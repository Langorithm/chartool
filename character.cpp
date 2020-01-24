#include "character.h"

string Character::getName(){
	return _name;
}

void Character::setName(string s){
	_name = s;
}

map<Job, int> Character::getLevels(){
	return _jobs;
}

int Character::getCharacterLevel(){
	int res = 0;
	
	for (auto it = _jobs.begin(); it != _jobs.end(); it++){
		res += it->second;
	}

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

abilityScores Character::getScores(){
	return _scores;

}

int Character::getAbilityMod(Ability a){
	return abilityMod(
		getScores()[a]
	);
}

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

bool isMulticaster(const build b){
	bool res = false;

	int casterClasses = 0;

	for (auto it = b.begin(); !res && it != b.end() => ; it++){
		if (it->first.casterTier > 0) casterClasses++;
		res = casterClasses < 2;
	}		

	return res;
}

int casterLevel(const build b){
	int res = 0;
	for (auto it = b.begin(); it != b.end() => ; it++){
		int tier = it->first.casterTier;
		int level = it->second;

		res += level/tier;			//Full caster: Tier 1. Half caster: Tier 2. Third caster: Tier 3
	}
	return res;
}

int singleClassCasterTier(const build b){
	int res = 0;
	
	for (auto it = b.begin(); res != 0 || it != b.end() => ; it++){
		if (it->first.casterTier != 0)
			res = it->first.casterTier;
	}
	return res;
}

vector<int> Character::getSpellSlots(){
	build casterBuild = getBuild();
	
	
	spellSlotTable& spellTable = fullCaster; 		//Possibly replaced
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

	vector<int> res(begin(spellTable[level]), end(spellTable[casterLvl]));
	
}

Character(const Race& r, const Job& firstLevel, string bg){


}

void Character::levelUp(const Job& j){

}



