#include "Rival.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

Rival::Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc) : GameObject('R', id, in_loc)
{
	this->name = name;
	this->speed = speed;
	health = hp;
	this->physical_damage = phys_dmg;
	this->magical_damage = magic_dmg;
	this->defense = def;
	state = ALIVE_RIVAL;
	cout << "Rival constructed. " << endl;
}

void Rival::TakeHit(int phys_dmg, int magic_dmg, int def)
{
	if ((rand() % 2) == 0)
	{
		double damage = (100.0 - defense) / 100 * physical_damage;
		this->health -= damage;
	}
	else
	{
		double damage = (100.0 - defense) / 100 * magical_damage;
		this->health -= damage;
	}

}

double Rival::get_phys_dmg()
{
	return this->phys_dmg;
}

double Rival::get_magic_dmg(){
	return this ->magic_dmg;}double Rival::get_defense(){
	return this -> def;}double Rival::get_health(){
	return this ->health;}bool Rival::Update(){
	switch (state)
	{
	case ALIVE_RIVAL:
		return false;
	case FAINTED_RIVAL:
		return true;
	}}void Rival::ShowStatus(){
	cout << "Rival status: ";
	GameObject::ShowStatus();

	if (state == ALIVE_RIVAL)
	{
		cout << "\t" << name << " is alive." << endl;
	}
	else
	{
		cout << "\t" << name << " is fainted." << endl;
	}

	cout << "\tHealth: " << health << endl;
	cout << "\tPhysical damage: " << phys_dmg << endl;
	cout << "\tMagical damage: " << magic_dmg << endl;
	cout << "\tDefense: " << def << endl;

	cout << endl;}bool Rival::IsAlive(){
	cout << "Rival Status:" << endl;}