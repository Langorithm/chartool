#include "basics.h"

class Character{

public:

	//	Getters/Setters
	string 		getName();
	void 		setName(string s);

	map<Job, int>	getLevels();
	Race&		getRace();

	int		getCharacterLevel();
	int		getProfBonus();
	int		getPassivePerception();

	int 		getMaxHP();
	void 		setMaxHP(int n);
	
	int		getAC();
	void		setAC(int n);
	
	int		getInitiative();
	void		setInitiative(int n);
	
	int		getSpeed();
	void		setSpeed(int n);
	
	abilityScores		getScores();
	int			getAbilityMod(Ability a);
	int 			getRollMod(proficiency p);
	set<proficiency>	getProficiencies();
	set<Feature>		getFeatures();	
	vector<int>		getSpellSlots();


	//Constructor
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
	int			_AC;
};
