#pragma once
#include <iostream>
#include "GameObject.h"

enum RivalStates {
	ALIVE_RIVAL = 0,
	FAINTED_RIVAL = 1
};

class Rival : public GameObject
{
protected:
	string name;
	double speed;
	double health;
	double physical_damage;
	double magical_damage;
	double defense;
	bool is_in_arena;
	BattleArena* current_arena;

public:
	Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc);
	void TakeHit(double phys_dmg, double magic_dmg, double def);
	double get_phys_dmg();
	double get_magic_dmg();
	double get_defense();
	double get_health();
	string GetName();
	bool Update();
	void ShowStatus();
	bool IsAlive();
	bool ShouldBeVisible();
};