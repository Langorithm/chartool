#include "basics.h"

class Character{

public:
	string 		getName();
	void 		setName(string s);

	map<Job, int>	getLevels();
	string		getRaceName();

	int		getCharacterLevel();
	int		getProfBonus();
	int 		getMaxHP();
	int		getInitiative();
	int		getSpeed();
	int		getPassivePerception();
	
	void 		setMaxHP(int n);
	void		setInitiative(int n);
	void		setSpeed(int n);

	abilityScores		getScores();
	int			getAbilityMod(Ability a);
	int 			getRollMod(proficiency p);
	set<proficiency>	getProficiencies();
	set<Feature>		getFeatures();
	
	Character(const Race& r, const Job& firstLevel, string bg);

	void levelUp(const Job& j);
	
private:
	string 			_name;
	Race&			_race;
	map<Job, int> 		_jobs;
	string			_background;
	abilityScores		_scores;
	set<proficiency>	_proficiencies;		
	set<Feature>		_features;

	int			_maxHP;	
	int			_initiative;
	int			_speed;
	
};
