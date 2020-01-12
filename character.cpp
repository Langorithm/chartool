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


Character(const Race& r, const Job& firstLevel, string bg){


}

void Character::levelUp(const Job& j){

}



