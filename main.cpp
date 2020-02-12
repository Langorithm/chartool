#include "character.h"
#include <iostream>

void printCharacter(Character pc){
	
	cout << "Name: " << pc.getName() << endl;
	cout << "Race: " << pc.getRace().name << endl;
	
	
//	cout << "Abilities: " << endl;
//	for (auto &pair : pc.getScores() ){
//		cout << '\t' << pair.second  << '|';
//		cout <<		abilityMod(pair.second)	<< endl;
//	}

	cout << "Build:" << endl;
	for (auto &pair : pc.getLevels() ){
		cout << '\t' << pair.first.name  << ' ';
		cout <<		pair.second	<< endl;
	}

	cout << "AC: " << pc.getAC() << endl;
	cout << "HP: " << pc.getMaxHP() << endl;
	cout << "Proficiency Bonus: " << pc.getProfBonus() << endl;
	cout << "Passive Perception: " << pc.getPassivePerception() << endl;
	cout << "Speed " << pc.getSpeed() << endl;

	cout << endl;
}



int main (){
	
	Race human;
	human.name = "Human";
	human.speed = 30;
	
	Race elf;
	elf.name = "Elf";
	elf.speed = 30;

	Job fighter;
	fighter.name = "Fighter";
	fighter.hitDie = 10;
	
	Job wizard;
	wizard.name = "Wizard";
	wizard.hitDie = 6;

	Character pc1(fighter,elf);
	pc1.levelUp(fighter);
	pc1.levelUp(wizard);
	Character pc2(wizard, human);

	for (int i = 0; i < 13; i++){
		pc2.levelUp(wizard);
	}
	printCharacter(pc1);
	printCharacter(pc2);
	return 0;
}
