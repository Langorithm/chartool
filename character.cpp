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


vector<int> Character::getSpellSlots(){
	spellSlotTable& spellTable = fullCaster; 		//Possibly replaced

	auto build = getLevels();
	

	auto it = build.begin();

	if (build.size() > 1){		//Multiclass Character
		
		//Determine caster level
		while (it != build.end()){
			//ERROR: No toma en cuenta multiclase del tipo Paladin/Fighter, solo Paladin/Sorcerer	


			it++;
		}


	
	} else {			//Single-classed Character
		int tier = it->first.casterTier;
		int level = getCharacterLevel();
		
		switch (tier){
			case (1): spellTable = fullCaster; break;
			case (2): spellTable = halfCaster; break;
			case (3): spellTable = thirdCaster; break;
			default : return {};
		}

			
		vector<int> res(begin(spellTable[level]), end(spellTable[level]));
		return res;
	
	}
	
}

Character(const Race& r, const Job& firstLevel, string bg){


}

void Character::levelUp(const Job& j){

}



